#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para validar se posição está dentro do tabuleiro
int dentroDoLimite(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

// Função para verificar se pode posicionar navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;

        if (!dentroDoLimite(novaLinha, novaColuna)) {
            return 0; // Fora do tabuleiro
        }

        if (tabuleiro[novaLinha][novaColuna] == NAVIO) {
            return 0; // Já ocupado
        }
    }
    return 1;
}

// Função para posicionar navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int dLinha, int dColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * dLinha;
        int novaColuna = coluna + i * dColuna;
        tabuleiro[novaLinha][novaColuna] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // ===== NAVIOS =====

    // Navio 1 (horizontal)
    if (podePosicionar(tabuleiro, 1, 1, 0, 1)) {
        posicionarNavio(tabuleiro, 1, 1, 0, 1);
    }

    // Navio 2 (vertical)
    if (podePosicionar(tabuleiro, 4, 3, 1, 0)) {
        posicionarNavio(tabuleiro, 4, 3, 1, 0);
    }

    // Navio 3 (diagonal principal ↘)
    if (podePosicionar(tabuleiro, 0, 0, 1, 1)) {
        posicionarNavio(tabuleiro, 0, 0, 1, 1);
    }

    // Navio 4 (diagonal secundária ↙)
    if (podePosicionar(tabuleiro, 0, 9, 1, -1)) {
        posicionarNavio(tabuleiro, 0, 9, 1, -1);
    }

    // Exibe o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}