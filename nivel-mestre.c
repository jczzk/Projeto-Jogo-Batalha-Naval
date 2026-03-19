#include <stdio.h>

#define TAM 10
#define H 5   // tamanho das matrizes de habilidade (5x5)

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            // Representação visual
            if (tab[i][j] == 0)
                printf("~ "); // água
            else if (tab[i][j] == 3)
                printf("N "); // navio
            else if (tab[i][j] == 5)
                printf("* "); // área de habilidade

        }
        printf("\n");
    }
}

// Função para sobrepor habilidade no tabuleiro
void aplicarHabilidade(int tab[TAM][TAM], int habilidade[H][H], int origemLinha, int origemColuna) {

    int centro = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            if (habilidade[i][j] == 1) {

                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);

                // Verifica limites do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM &&
                    colunaTab >= 0 && colunaTab < TAM) {

                    // Marca área da habilidade (sem apagar navio)
                    if (tab[linhaTab][colunaTab] == 0)
                        tab[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

int main() {

    int tabuleiro[TAM][TAM] = {0};

    // Exemplo de navios
    tabuleiro[2][2] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[7][3] = 3;

    // =========================
    // MATRIZ CONE
    // =========================
    int cone[H][H];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            int meio = H / 2;

            // Forma de cone (abre para baixo)
            if (j >= meio - i && j <= meio + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // =========================
    // MATRIZ CRUZ
    // =========================
    int cruz[H][H];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            int meio = H / 2;

            if (i == meio || j == meio)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // =========================
    // MATRIZ OCTAEDRO (LOSANGO)
    // =========================
    int octaedro[H][H];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            int meio = H / 2;

            // Distância de Manhattan
            if (abs(i - meio) + abs(j - meio) <= meio)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // =========================
    // APLICAR HABILIDADES
    // =========================

    aplicarHabilidade(tabuleiro, cone, 2, 7);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);

    // =========================
    // EXIBIR RESULTADO
    // =========================
    imprimirTabuleiro(tabuleiro);

    return 0;
}