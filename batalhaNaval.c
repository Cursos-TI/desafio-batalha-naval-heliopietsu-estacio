#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs() (valor absoluto)

#define TAM_TAB 10
#define TAM_HAB 5

int main() {
    // ---------------------------------------------------------
    // 1. INICIALIZAÇÃO DO TABULEIRO E NAVIOS
    // ---------------------------------------------------------
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};

    // Posicionando alguns navios rapidamente para ilustrar o cenário (Navio = 3)
    // Navio Horizontal
    tabuleiro[1][1] = 3; tabuleiro[1][2] = 3; tabuleiro[1][3] = 3;
    // Navio Vertical
    tabuleiro[6][8] = 3; tabuleiro[7][8] = 3; tabuleiro[8][8] = 3;
    // Navio Diagonal
    tabuleiro[7][1] = 3; tabuleiro[8][2] = 3; tabuleiro[9][3] = 3;

    // ---------------------------------------------------------
    // 2. CRIAÇÃO DINÂMICA DAS MATRIZES DE HABILIDADE (5x5)
    // ---------------------------------------------------------
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    // Preenchendo as habilidades utilizando loops aninhados e condicionais lógicas
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            
            // CONE: A distância da coluna em relação ao centro (2) deve ser menor ou igual à linha.
            // Isso cria um triângulo apontando para cima/baixo (limitado a 3 linhas de altura).
            if (i <= 2 && abs(j - 2) <= i) {
                cone[i][j] = 1;
            }

            // CRUZ: Marca apenas a linha central (2) ou a coluna central (2).
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            }

            // OCTAEDRO (Losango): A soma da distância da linha e da coluna até o centro (2,2) 
            // deve ser menor ou igual a 2. Isso cria o formato de diamante.
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // ---------------------------------------------------------
    // 3. INTEGRAÇÃO DAS HABILIDADES AO TABULEIRO
    // ---------------------------------------------------------
    // Vamos definir os pontos de origem (centro) de cada habilidade no tabuleiro
    int origemConeL = 2, origemConeC = 2;
    int origemCruzL = 5, origemCruzC = 5;
    int origemOctaL = 7, origemOctaC = 7;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            
            // Calculando a posição real no tabuleiro (subtraindo 2 para centralizar a matriz 5x5)
            
            // Aplicando o Cone (Valor 5)
            if (cone[i][j] == 1) {
                int linhaReal = origemConeL + i - 2;
                int colReal = origemConeC + j - 2;
                // Condicional para garantir que não saia dos limites do tabuleiro 10x10
                if (linhaReal >= 0 && linhaReal < TAM_TAB && colReal >= 0 && colReal < TAM_TAB) {
                    tabuleiro[linhaReal][colReal] = 5;
                }
            }

            // Aplicando a Cruz (Valor 5)
            if (cruz[i][j] == 1) {
                int linhaReal = origemCruzL + i - 2;
                int colReal = origemCruzC + j - 2;
                if (linhaReal >= 0 && linhaReal < TAM_TAB && colReal >= 0 && colReal < TAM_TAB) {
                    tabuleiro[linhaReal][colReal] = 5;
                }
            }

            // Aplicando o Octaedro (Valor 5)
            if (octaedro[i][j] == 1) {
                int linhaReal = origemOctaL + i - 2;
                int colReal = origemOctaC + j - 2;
                if (linhaReal >= 0 && linhaReal < TAM_TAB && colReal >= 0 && colReal < TAM_TAB) {
                    tabuleiro[linhaReal][colReal] = 5;
                }
            }
        }
    }

    // ---------------------------------------------------------
    // 4. EXIBIÇÃO DO TABULEIRO FINAL
    // ---------------------------------------------------------
    printf("--- Batalha Naval - Nivel Mestre (Habilidades Especiais) ---\n");
    printf("Legenda: [0] Agua | [3] Navio | [5] Area de Efeito\n\n");

    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            // Imprime cada célula com um espaço para alinhar perfeitamente
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
