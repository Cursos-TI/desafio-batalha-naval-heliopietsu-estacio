#include <stdio.h>

// Definição de constantes para facilitar a manutenção do código
#define TAM_TAB 10
#define TAM_NAVIO 3

int main() {
    // 1. Representação do Tabuleiro
    // Cria uma matriz 10x10 e inicializa todas as posições com 0 (água)
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};

    // 2. Declaração dos vetores dos navios
    // Como solicitado, criamos vetores unidimensionais onde '3' representa parte do navio
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais escolhidas (hardcoded) para o navio Horizontal (Linha 2, Coluna 1)
    int linhaHor = 2;
    int colHor = 1;

    // Coordenadas iniciais escolhidas (hardcoded) para o navio Vertical (Linha 5, Coluna 7)
    int linhaVert = 5;
    int colVert = 7;

    // ---------------------------------------------------------
    // 3. Validação e Posicionamento do Navio Horizontal
    // ---------------------------------------------------------
    // Verifica se as coordenadas estão dentro dos limites e se o navio cabe na linha
    if (linhaHor >= 0 && linhaHor < TAM_TAB && colHor >= 0 && (colHor + TAM_NAVIO) <= TAM_TAB) {
        
        int sobreposicao = 0;
        
        // Verifica se há alguma outra peça no caminho (sobreposição)
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaHor][colHor + i] != 0) {
                sobreposicao = 1; 
            }
        }

        // Se não houver sobreposição, copia os dados do vetor do navio para a matriz
        if (sobreposicao == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaHor][colHor + i] = navioHorizontal[i];
            }
        } else {
            printf("Erro: Sobreposicao detectada ao posicionar navio horizontal.\n");
        }
    } else {
        printf("Erro: Coordenadas invalidas para o navio horizontal.\n");
    }

    // ---------------------------------------------------------
    // 4. Validação e Posicionamento do Navio Vertical
    // ---------------------------------------------------------
    // Verifica se as coordenadas estão dentro dos limites e se o navio cabe na coluna
    if (colVert >= 0 && colVert < TAM_TAB && linhaVert >= 0 && (linhaVert + TAM_NAVIO) <= TAM_TAB) {
        
        int sobreposicao = 0;

        // Verifica se há alguma outra peça no caminho (sobreposição)
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaVert + i][colVert] != 0) {
                sobreposicao = 1;
            }
        }

        // Se não houver sobreposição, copia os dados do vetor do navio para a matriz
        if (sobreposicao == 0) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaVert + i][colVert] = navioVertical[i];
            }
        } else {
            printf("Erro: Sobreposicao detectada ao posicionar navio vertical.\n");
        }
    } else {
        printf("Erro: Coordenadas invalidas para o navio vertical.\n");
    }

    // ---------------------------------------------------------
    // 5. Exibição do Tabuleiro
    // ---------------------------------------------------------
    printf("--- Batalha Naval - Posicionamento dos Navios ---\n\n");
    
    // Loops aninhados para percorrer as linhas e colunas do tabuleiro
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            // Imprime o valor da coordenada atual seguido de um espaço para legibilidade
            printf("%d ", tabuleiro[i][j]);
        }
        // Pula para a próxima linha após imprimir todas as colunas da linha atual
        printf("\n");
    }

    return 0;
}
