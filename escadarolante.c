#include <stdio.h>
#define MAX_n 10000
#define MAX_t 100000
#define MAX_d 1

int main() {
    int n = 3; // Número de pessoas

    int tempos[] = {5, 7, 9}; // Vetor de tempos (exemplo)
    int posicoes[] = {0, 1, 0}; // Vetor de posições (exemplo)

    int tempo_atual = 0; // Tempo atual
    int direcao = 0; // Direção inicial (0 para direita, 1 para esquerda)
    int tempo_espera = 0; // Tempo de espera

    for (int i = 0; i < n; i++) {
        int t = tempos[i];
        int d = posicoes[i];

        // Verifica as direções
        if (direcao == d) {
            tempo_espera = 0;
        } else {
            tempo_espera = 10;
            direcao = d;
        }

        // Calcula o tempo necessário para se mover na escada e
        // gerencia o tempo de espera quando a direção da pessoa muda
        int time_to_move = t - tempo_atual;
        if (time_to_move < 0) {
            tempo_atual = t;
        } else {
            tempo_atual += time_to_move;
        }

        tempo_atual += tempo_espera;
        tempo_atual += 10;
    }

    printf("%d\n", tempo_atual);

    return 0;
}

