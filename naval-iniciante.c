#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {

    int tabuleiro[TAM][TAM];
    int i, j;

    // =========================
    // 1. Inicializar tabuleiro
    // =========================
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==========
    // 2. Navios
    // ==========
    int navioH[NAVIO] = {3, 3, 3};
    int navioV[NAVIO] = {3, 3, 3};

    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;

    // ===============================
    // 3. Posicionar Navio Horizontal
    // ===============================
    if (colunaH + NAVIO <= TAM) {
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                printf("Erro: sobreposição!\n");
                return 1;
            }
        }
        for (i = 0; i < NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioH[i];
        }
    }

    // ==============================
    // 4. Posicionar Navio Vertical
    // ==============================
    if (linhaV + NAVIO <= TAM) {
        for (i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                printf("Erro: sobreposição!\n");
                return 1;
            }
        }
        for (i = 0; i < NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = navioV[i];
        }
    }

    // ==========================
    // 5. Exibir Tabuleiro 
    // ==========================

    printf("\n   ");
    // Letras do topo
    for (j = 0; j < TAM; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    printf("   ");
    for (j = 0; j < TAM; j++) {
        printf("---");
    }
    printf("\n");

    for (i = 0; i < TAM; i++) {
        printf("%2d|", i + 1); // Número da linha

        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" ~ ");
            } else {
                printf(" # ");
            }
        }
        printf("\n");
    }

    return 0;
}