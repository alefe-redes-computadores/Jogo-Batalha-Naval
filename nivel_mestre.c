#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5

int main() {
    int tabuleiro[TAM][TAM];

    // Preenche o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanhoNavio = 3;

    // Navios base (igual ao nível anterior)
    int linhaH = 2, colunaH = 1;
    int linhaV = 5, colunaV = 7;

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // === Matrizes das habilidades ===
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int centro = TAM_HAB / 2; // centro da matriz (2 em uma 5x5)

    // Cone - formato triangular apontando para baixo
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Cruz - linhas e colunas centrais
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Octaedro (losango)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // === Pontos de origem das habilidades no tabuleiro ===
    int origemConeLinha = 1, origemConeColuna = 4;
    int origemCruzLinha = 6, origemCruzColuna = 2;
    int origemOctaLinha = 4, origemOctaColuna = 6;

    // Função genérica de sobreposição (manual)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origemConeLinha + i - centro;
            int colunaTab = origemConeColuna + j - centro;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (cone[i][j] == 1) tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origemCruzLinha + i - centro;
            int colunaTab = origemCruzColuna + j - centro;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (cruz[i][j] == 1) tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origemOctaLinha + i - centro;
            int colunaTab = origemOctaColuna + j - centro;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (octaedro[i][j] == 1) tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }

    // === Exibe o tabuleiro final ===
    printf("\n=== TABULEIRO COM HABILIDADES ===\n\n");
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

    printf("\nLegenda: 0 = água | 3 = navio | 5 = área de habilidade\n");

    return 0;
}
