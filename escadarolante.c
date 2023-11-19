#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PEOPLE 10000

int qtd_d_inicio = 0;
int qtd_d_mudanca = 0;
int ponto_mudanca = 0;
int d_inicio = 0;
int d_mudanca = 0;
int n;
int tempo_atual = 0;
int direcao = 0;
int tempo_espera = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    int tempo;
    int direcao;
} Pessoa;

void* pessoa(void* args) {
    Pessoa pessoa_info;
    FILE* file = (FILE*)args;

    for (int i = 0; i < n; i++) {
        
        pthread_mutex_lock(&mutex);

        if (fscanf(file, "%d %d", &pessoa_info.tempo, &pessoa_info.direcao) == EOF) {
            // Lidar com o final do arquivo ou algum erro de leitura
            pthread_mutex_unlock(&mutex);
            break;
        }

        // define qual a direção de partida
        if(i == 0){
            d_inicio = pessoa_info.direcao;
            qtd_d_inicio++; // soma qtd inicio
        }

        // verifica se há mudança de direções
        if(i > 0){
          if(pessoa_info.direcao != d_inicio){
            d_mudanca = pessoa_info.direcao;
            qtd_d_mudanca++; // soma qtd mudança
            ponto_mudanca = i; // guarda o ponto de mudança
        }

        if (direcao == pessoa_info.direcao) {
            tempo_espera = 0;
        } else {
            tempo_espera = 10;
            direcao = pessoa_info.direcao;
        }

        int tempo_mover = pessoa_info.tempo - tempo_atual;
        if (tempo_mover < 0) {
            tempo_atual = pessoa_info.tempo;
        } else {
            tempo_atual += tempo_mover;
        }
        tempo_atual += tempo_espera;

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    FILE* file = fopen("entrada.txt", "r");
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
        pthread_create(&threads[i], NULL, pessoa, (void*)file);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", tempo_atual);

    fclose(file);
    return 0;
}


/*#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PEOPLE 10000

int n;
int tempo_atual = 0;
int direcao = 0;
int tempo_espera = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    int tempo;
    int direcao;
} Pessoa;

void* pessoa(void* args) {
    Pessoa pessoa_info;
    FILE* file = (FILE*)args;

    while (fscanf(file, "%d %d", &pessoa_info.tempo, &pessoa_info.direcao) != EOF) {
        pthread_mutex_lock(&mutex);

        if (direcao == pessoa_info.direcao) {
            tempo_espera = 0;
        } else {
            tempo_espera = 10;
            direcao = pessoa_info.direcao;
        }

        int tempo_mover = pessoa_info.tempo - tempo_atual;
        if (tempo_mover < 0) {
            tempo_atual = pessoa_info.tempo;
        } else {
            tempo_atual += tempo_mover;
        }
        tempo_atual += tempo_espera;

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    FILE* file = fopen("entrada.txt", "r");
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
        pthread_create(&threads[i], NULL, pessoa, (void*)file);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", tempo_atual);

    fclose(file);
    return 0;
}*/

