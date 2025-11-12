#include <stdio.h>

#define TAM 10

int main() {
    int tabuleiro[TAM][TAM];

    // Preenche todo o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanhoNavio = 3;

    // === Navios horizontais e verticais ===
    int linhaH = 2, colunaH = 1; // navio horizontal
    int linhaV = 5, colunaV = 7; // navio vertical

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = 3; // horizontal
        tabuleiro[linhaV + i][colunaV] = 3; // vertical
    }

    // === Navios diagonais ===
    int linhaD1 = 0, colunaD1 = 0; // diagonal principal (↘)
    int linhaD2 = 0, colunaD2 = 9; // diagonal inversa (↙)

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;   // diagonal principal
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;   // diagonal inversa
    }

    // Exibe o tabuleiro completo
    printf("\n=== TABULEIRO 10x10 ===\n\n");
    printf("   ");
    for (int c = 0; c < TAM; c++) {
        printf("%2d ", c);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = água | 3 = navio (inclusive diagonais)\n");

    return 0;
}
