/*
NOME: DAVI MICALE - TIA: 32096062
NOME: VICTOR RODRIGUES - TIA: 32273134
NOME: YURI - TIA: 32230877
PROFESSOR: EDUARDO COSTA
TURMA: 4N
PROJETO 2: ESCADA ROLANTE
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

struct Passageiro {
    int tempo;
    int direcao;
};

void pessoa(int n, struct Passageiro passageiro[], const char *filename) {

    int tempo_atual = 0;
    int tempo_espera = 0;
    int time_to_move = 0;
    int direcao = passageiro[0].direcao; // Direção inicial
    bool analisa_espera = false; // Verifica se houve espera

    tempo_atual += 10;

    for (int i = 0; i < n; i++) {

        // Calcula o tempo necessário para se mover na escada e
        // se a pessoa já entrou ou teve que se mover
        time_to_move = passageiro[i].tempo - tempo_atual;


        // o tempo de chegada da pessoa for menor ou igual ao tempo atual
        if (time_to_move <= 0) {
            // Se direção for igual a inicial
            if(direcao == passageiro[i].direcao){
                tempo_espera = 0;
                tempo_atual = passageiro[i].tempo + 10;
            } else {
                tempo_espera = 10;
                analisa_espera = true;
            }
        }

        // Calcula o tempo necessário para se mover na escada e
        // se a pessoa já entrou ou teve que se mover
        time_to_move = passageiro[i].tempo - tempo_atual;

        // Se alguém se moveu para entrar
        if (time_to_move > 0) {
            // Houve espera
            if (analisa_espera) {
                tempo_atual += tempo_espera; // Adiciona a espera no tempo atual

                // Realiza a mudança de direção
                if (direcao == 1) {
                    direcao = 0;
                } else {
                    direcao = 1;
                }

                // Decrementa para realizar a análise novamente
                i--;
            } else {
                tempo_atual = passageiro[i].tempo + 10;
                direcao = passageiro[i].direcao;
            }
            analisa_espera = false;
        }
    }

    // Verifica se ainda há espera
    if (analisa_espera) {
        tempo_atual += 10;
    }

    printf("Arquivo lido: %s\n", filename);
    printf("Saída: %d\n", tempo_atual);
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese"); // Configura localização para português

    // Pra realizar a leitura realizada pelo terminal
    if (argc != 2) {
        printf("Uso: %s nome_do_arquivo\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    // Criação da struct
    struct Passageiro *passageiro = malloc(n * sizeof(struct Passageiro));
    if (passageiro == NULL) {
        perror("Erro ao alocar memória");
        fclose(file);
        return 1;
    }

    // Passando os valores para a astruct
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d", &passageiro[i].tempo, &passageiro[i].direcao);
    }

    fclose(file);

    pessoa(n, passageiro, argv[1]);

    free(passageiro);

    return 0;
}

