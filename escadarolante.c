#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Lê o número de pessoas

    int tempo_atual = 0; // Tempo atual
    int direcao = 0; // Direção inicial (0 para direita, 1 para esquerda)
    int tempo_espera = 0; // Tempo de espera

    for (int i = 0; i < n; i++) {
        int t, d; // Momento de chegada e direção (0 ou 1)
        scanf("%d %d", &t, &d);

        if (direcao == d) {
            // Se a direção da pessoa é a mesma que a direção atual, não precisa esperar
            tempo_espera = 0;
        } else {
            // Se a direção da pessoa é oposta à direção atual
            // A pessoa deve esperar até que a escada pare e mude de direção
            tempo_espera = 10;
            direcao = d; // Atualiza a direção
        }

        int tempo_mover = t - tempo_atual;
        if (tempo_mover < 0) {
            // Se a pessoa chegou antes da escada parar, atualiza o tempo para o momento em que a escada para
            tempo_atual = t;
        } else {
            tempo_atual += tempo_mover; // Move-se até o momento de chegada da pessoa
        }

        tempo_atual += tempo_espera; // Adiciona o tempo de espera
        tempo_atual += 10; // Leva 10 segundos para a pessoa sair da escada
    }

    printf("%d\n", tempo_atual);

    return 0;
}

