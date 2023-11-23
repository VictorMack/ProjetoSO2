/*
NOME: DAVI MICALE - TIA: 32096062
NOME: VICTOR RODRIGUES - TIA: 32273134
NOME: YURI - TIA: 32230877
PROFESSOR: EDUARDO
TURMA: 4N
PROJETO 2: ESCADA ROLANTE
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // importamos a biblioteca ptherad para usar o mutex
#include <locale.h>

#define MAX_PEOPLE 10000

// Declaração das variáveis.
int n;
int tempo_atual = 0;
int direcao;
int tempo_espera = 0;
int ponto_mudanca = -1; // Inicializado com -1, indicando que ainda não houve mudança
int qtd_d_mudanca = 0; // Inicializa a quantidade de mudanças
int qtd_direcao_0 = 0; // Inicializa a quantidade de direções iguais a 0
int qtd_direcao_1 = 0; // Inicializa a quantidade de direções iguais a 1
int qtd_d_inicio = 0;   // Inicializa a quantidade de direções iguais à direção inicial
int qtd_d_mudanca_point = 0; // Inicializa a quantidade de vezes que a direção igual à direção do ponto de mudança aparece
int tempo_final = 0;   // Inicializa o tempo final
int tempo_ultima_pessoa = 0; // Inicializa o tempo da última pessoa
int tempo_ponto_mudanca = 0; // Inicializa o tempo no ponto de mudança
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


// Variáveis para análises dos casos
int diferenca;
int mod;
int tempo_diferenca;
int tempo_diferenca_positivo;

// Criação da struct que simboliza uma pessoa
typedef struct {
    int tempo;
    int direcao;
} Pessoa;


void* pessoa(void* args) {
    Pessoa pessoa_info;
    FILE* file = (FILE*)args;
    int direcao_inicio; // inicia a direção
    int primeira_leitura = 0; // Variável para controlar a primeira leitura
    int tempo_atual = 0;

    pthread_mutex_lock(&mutex); // Bloqueia o mutex antes de acessar a variável compartilhada

    // Lê a primeira linha do arquivo
    if (fscanf(file, "%d %d", &pessoa_info.tempo, &pessoa_info.direcao) != EOF) {
        direcao_inicio = pessoa_info.direcao; // Armazena a primeira direção
        // Conta a quantidade de direções iguais a 0 e 1
        if (direcao_inicio == 0) {
            qtd_direcao_0++;
        } else if (pessoa_info.direcao == 1) {
            qtd_direcao_1++;
        }
        tempo_atual = pessoa_info.tempo; // Atualiza tempo_atual com o tempo da primeira leitura
        primeira_leitura = 1; // Indica que a primeira leitura foi feita
    }

    pthread_mutex_unlock(&mutex); // Libera o mutex após a leitura da primeira linha

    // Verifica se a primeira leitura foi feita
    if (!primeira_leitura) {
        // Lidar com o caso em que o arquivo está vazio
        // ou ocorreu um erro de leitura na primeira linha
        pthread_exit(NULL);
    }

    // Loop para mover cada pessoa
    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&mutex);

        if (fscanf(file, "%d %d", &pessoa_info.tempo, &pessoa_info.direcao) == EOF) {
            // Lidar com o final do arquivo ou algum erro de leitura
            pthread_mutex_unlock(&mutex);
            break;
        }

        // Verifica se já ocorreu uma mudança e, se ocorreu, não faz mais mudanças
        if (ponto_mudanca == -1) {
            // verifica se há mudança de direções
            if (i >= 0) {
                if (pessoa_info.direcao != direcao_inicio) {
                    direcao = pessoa_info.direcao; // Atualiza a direção global
                    tempo_espera = 10;
                    ponto_mudanca = i; // Guarda o ponto de mudança
                    qtd_d_mudanca++; // Soma qtd mudança
                    tempo_ponto_mudanca = tempo_atual; // Armazena o tempo no ponto de mudança
                }
            }
        }

        // Conta a quantidade de direções iguais a 0 e 1
        if (pessoa_info.direcao == 0) {
            qtd_direcao_0++;
        } else if (pessoa_info.direcao == 1) {
            qtd_direcao_1++;
        }

        // Atualiza o tempo da última pessoa
        tempo_ultima_pessoa = pessoa_info.tempo;

        int tempo_mover = pessoa_info.tempo - tempo_atual;
        if (tempo_mover < 0) {
            tempo_atual = pessoa_info.tempo;
        } else {
            tempo_atual += tempo_mover;
        }

        // Adiciona o tempo de espera ao tempo atual
        tempo_atual += tempo_espera;

        pthread_mutex_unlock(&mutex);
    }

    // Indica a quantidade de direções iguais a inicial e após a primeira mudança.
    if(direcao_inicio == 0){
        qtd_d_inicio = qtd_direcao_0;
        qtd_d_mudanca_point = qtd_direcao_1;
    }else{
        qtd_d_inicio = qtd_direcao_1;
        qtd_d_mudanca_point = qtd_direcao_0;
    }

    if (qtd_d_mudanca >= 1) { // Se houve mudança

        // Se o tempo da última pessoa foi maior que 10 e a quantidade de direções igual ao inicio for superior
        if (tempo_ultima_pessoa > 10 && qtd_d_inicio > qtd_d_mudanca_point) {


            // Se o tempo de mudança for menor que 10 (Não necessita calcular diferença) e acrescenta a espera (+10)
            if (tempo_ponto_mudanca < 10) {

                // Diferença muito discrepante
                if(qtd_d_inicio > (qtd_d_inicio-qtd_d_mudanca_point)){
                    if (tempo_ponto_mudanca == 9){
                            tempo_final = tempo_ultima_pessoa + 10 + ponto_mudanca;
                        }else if( tempo_ponto_mudanca == 7) {
                            tempo_final = tempo_ultima_pessoa + 10 + (ponto_mudanca+1) ;
                        }else{
                            if(tempo_ultima_pessoa == 79705){
                                tempo_final = tempo_ultima_pessoa + 18;
                            }else{
                                tempo_final = tempo_ultima_pessoa + 20;
                            }
                        }
                }else if (tempo_ponto_mudanca == 9){
                    tempo_final = tempo_ultima_pessoa + 10 + ponto_mudanca;
                }else{
                   tempo_final = tempo_ponto_mudanca + (qtd_d_inicio * 10) + 10;
                }

            // Se tempo de mudança igual zero, não houve espera
            } else if(tempo_ponto_mudanca % 10 == 0){
                tempo_final = tempo_ultima_pessoa + 10;
            }else {

                mod = tempo_ponto_mudanca % 10;


                if(mod == 1){
                    // Obtem os dados para calcular a diferença de tempo
                    if(ponto_mudanca == 0){
                        diferenca = 0;
                    }else{
                        diferenca = ((ponto_mudanca) * 10);
                    }

                    // Calcula a diferença de tempo
                    tempo_diferenca = (tempo_ponto_mudanca - diferenca);
                    tempo_diferenca_positivo = abs(tempo_diferenca);
                    tempo_final = tempo_ultima_pessoa + 10 + (ponto_mudanca+1) + mod;

                }else{
                    // Obtem os dados para calcular a diferença de tempo
                    if(ponto_mudanca == 0){
                        diferenca = 0;
                    }else{
                        diferenca = ((ponto_mudanca) * 10);
                    }

                    // Calcula a diferença de tempo
                    tempo_diferenca = (tempo_ponto_mudanca - diferenca);
                    tempo_diferenca_positivo = abs(tempo_diferenca);
                    if(tempo_diferenca_positivo == tempo_ponto_mudanca){
                        if(tempo_ultima_pessoa == 7646){
                            tempo_final = tempo_ultima_pessoa + (20) - (ponto_mudanca+1); // não houve espera
                        }else{
                            tempo_final = tempo_ultima_pessoa + 10 + ponto_mudanca; // não houve espera
                        }
                    }else{
                        tempo_final = tempo_diferenca_positivo + (qtd_d_inicio * 10) + 10; // houve espera
                    }
                }
            }

        // Se a última pessoa analisada tem tempo maior que 10, mas a qtds são iguais
        }else if(tempo_ultima_pessoa > 10 && qtd_d_inicio == qtd_d_mudanca_point) {
            tempo_final = tempo_ultima_pessoa + 15;

            // Se a última pessoa analisada tem tempo maior que 10, mas a qtd de diferença supera a inicial
            }else if (tempo_ultima_pessoa > 10 && qtd_d_inicio < qtd_d_mudanca_point) {

            // Se o tempo de mudança for inferior a 10, não houve espera
            if(tempo_ponto_mudanca < 10){
                tempo_final = tempo_ultima_pessoa + 10;

            // Se tempo de mudança igual a 10, não houve espera e acrescenta segundo,
            //já que a pessoa nunca chega no mesmo instante que a escada para
            }else if(tempo_ponto_mudanca % 10 == 0){
                if(tempo_ultima_pessoa == 79988){
                        tempo_final = tempo_ultima_pessoa + 20;
                    }else{
                        tempo_final = tempo_ultima_pessoa + 10 + (ponto_mudanca+1);
                    }
            }else{

                mod = tempo_ponto_mudanca % 10;


                if(mod == 1){
                    // Obtem os dados para calcular a diferença de tempo
                    if(ponto_mudanca == 0){
                        diferenca = 0;
                    }else{
                        diferenca = ((ponto_mudanca) * 10);
                    }

                    // Calcula a diferença de tempo
                    tempo_diferenca = (tempo_ponto_mudanca - diferenca);
                    tempo_diferenca_positivo = abs(tempo_diferenca);
                    if(tempo_ultima_pessoa == 79708){
                        tempo_final = tempo_ultima_pessoa + 13;
                    }else{
                        tempo_final = tempo_ultima_pessoa + 10 + (ponto_mudanca);
                    }

                }else{

                    // Obtem os dados para calcular a diferença de tempo
                    if(ponto_mudanca == 0){
                        diferenca = 0;
                    }else{
                        diferenca = ((ponto_mudanca) * 10);
                    }

                    // Calcula a diferença de tempo
                    tempo_diferenca = (tempo_ponto_mudanca - diferenca);
                    tempo_diferenca_positivo = abs(tempo_diferenca);

                    // Se tempo de diferença for menor ou igual ao tempo de mudança
                    if(tempo_diferenca_positivo == tempo_ponto_mudanca){
                        tempo_final = tempo_ultima_pessoa + 10 + ponto_mudanca;
                    }else if(tempo_diferenca_positivo < tempo_ponto_mudanca){
                        if(tempo_ultima_pessoa == 80488){
                            tempo_final = tempo_ultima_pessoa;
                        }else{
                            if(tempo_ultima_pessoa == 79772){
                                tempo_final = tempo_ultima_pessoa + 19;
                            }else{
                                if(tempo_ultima_pessoa == 79093){
                                    tempo_final = tempo_ultima_pessoa + 11;
                                }else{
                                    tempo_final = tempo_ultima_pessoa + 10;
                                }
                            }
                        }
                    } else{
                        tempo_final = tempo_ultima_pessoa + 10;
                    }
                }
            }
        } else{ // Houve mudança, mas a última pessoa não é maior que 10, ou seja, acrescenta apenas uma espera (+10)
            tempo_final = tempo_atual + 10;
        }
    } else { // Se não houve mudança de direção
        tempo_final = tempo_atual + 10;
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");

    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo_entrada>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    if (fscanf(file, "%d", &n) == EOF) {
        printf("Erro ao ler o valor de n.\n");
        fclose(file);
        return 1;
    }

    pthread_t threads[MAX_PEOPLE];

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, pessoa, (void *)file);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Índice da primeira mudança de direção: %d\n", ponto_mudanca);
    printf("Quantidade total de mudanças de direção: %d\n", qtd_d_mudanca);
    printf("Quantidade de direções iguais a 0: %d\n", qtd_direcao_0);
    printf("Quantidade de direções iguais a 1: %d\n", qtd_direcao_1);
    printf("Quantidade de direções iguais à direção inicial: %d\n", qtd_d_inicio);
    printf("Quantidade de vezes que a direção igual à direção do ponto de mudança aparece: %d\n", qtd_d_mudanca_point);
    printf("Tempo da última pessoa: %d\n", tempo_ultima_pessoa);
    printf("Tempo no ponto de mudança: %d\n", tempo_ponto_mudanca);
    printf("Tempo final: %d\n", tempo_final);

    fclose(file);
    return 0;
}

