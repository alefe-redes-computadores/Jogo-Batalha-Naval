#include <stdio.h>

// Tamanho do tabuleiro
#define TAM 10

int main() {
    // Matriz 10x10 representando o tabuleiro
    int tabuleiro[TAM][TAM];

    // Preenche o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho dos navios
    int tamanhoNavio = 3;

    // Navio horizontal (valor 3)
    int linhaH = 2; // linha onde o navio horizontal começa
    int colunaH = 1; // coluna onde começa

    // Coloca o navio horizontal no tabuleiro
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio vertical (valor 3)
    int linhaV = 5; // linha onde o navio vertical começa
    int colunaV = 7; // coluna onde começa

    // Coloca o navio vertical no tabuleiro
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
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

    printf("\nLegenda: 0 = água | 3 = navio\n");

    return 0;
}
