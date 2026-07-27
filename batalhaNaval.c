#include <stdio.h>

// Definição de constantes para o tamanho do tabuleiro e dos navios
#define TAM_TAB 10
#define TAM_NAVIO 3

int main() {
    // 1. Inicializa o tabuleiro 10x10 com 0 (representando a água)
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};

    // Variável auxiliar para checar sobreposição antes de posicionar
    int podePosicionar;

    // ---------------------------------------------------------
    // NAVIO 1: HORIZONTAL (Linha constante, Coluna aumenta)
    // ---------------------------------------------------------
    int linhaH = 2, colH = 1;
    podePosicionar = 1; // Assumimos que é possível até provar o contrário

    // Verifica limites do tabuleiro
    if (colH + TAM_NAVIO <= TAM_TAB) {
        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colH + i] != 0) podePosicionar = 0;
        }
        // Posiciona se for válido
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colH + i] = 3;
            }
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites.\n");
    }

    // ---------------------------------------------------------
    // NAVIO 2: VERTICAL (Linha aumenta, Coluna constante)
    // ---------------------------------------------------------
    int linhaV = 5, colV = 8;
    podePosicionar = 1;

    if (linhaV + TAM_NAVIO <= TAM_TAB) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colV] != 0) podePosicionar = 0;
        }
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colV] = 3;
            }
        }
    } else {
        printf("Erro: Navio vertical fora dos limites.\n");
    }

    // ---------------------------------------------------------
    // NAVIO 3: DIAGONAL 1 (Baixo e Direita -> Linha++, Coluna++)
    // ---------------------------------------------------------
    int linhaD1 = 6, colD1 = 2;
    podePosicionar = 1;

    // Valida se não vai estourar o limite inferior nem o limite direito
    if (linhaD1 + TAM_NAVIO <= TAM_TAB && colD1 + TAM_NAVIO <= TAM_TAB) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colD1 + i] != 0) podePosicionar = 0;
        }
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colD1 + i] = 3;
            }
        }
    } else {
        printf("Erro: Navio diagonal 1 fora dos limites.\n");
    }

    // ---------------------------------------------------------
    // NAVIO 4: DIAGONAL 2 (Baixo e Esquerda -> Linha++, Coluna--)
    // ---------------------------------------------------------
    int linhaD2 = 0, colD2 = 7;
    podePosicionar = 1;

    // Valida se não vai estourar o limite inferior nem o limite esquerdo (coluna < 0)
    if (linhaD2 + TAM_NAVIO <= TAM_TAB && colD2 - TAM_NAVIO >= -1) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colD2 - i] != 0) podePosicionar = 0;
        }
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colD2 - i] = 3;
            }
        }
    } else {
        printf("Erro: Navio diagonal 2 fora dos limites.\n");
    }

    // ---------------------------------------------------------
    // EXIBIÇÃO DO TABULEIRO COMPLETO
    // ---------------------------------------------------------
    printf("--- Batalha Naval - Aventureiro ---\n\n");
    
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }

    return 0;
}
