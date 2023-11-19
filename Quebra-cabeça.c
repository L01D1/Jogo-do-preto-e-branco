#include <stdio.h>

#define MAX_L 100
#define MAX_C 100

int main() {
    int L, C, P;
    scanf("%d %d", &L, &C);  // Leitura do número de linhas e colunas
    scanf("%d", &P);         // Leitura do número de peças pretas

    // Inicializando o tabuleiro
    int tabuleiro[MAX_L][MAX_C] = {0};

    // Preenchendo o tabuleiro com as peças pretas
    for (int i = 0; i < P; i++) {
        int Xi, Yi;
        scanf("%d %d", &Xi, &Yi);
        tabuleiro[Xi - 1][Yi - 1] = 1;  // Marcando a posição da peça preta
    }

    // Contando o número máximo de peças brancas que podem ser colocadas
    int maxPecasBrancas = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (tabuleiro[i][j] == 0) {
                // Se a posição estiver vazia, incrementar o número de peças brancas
                maxPecasBrancas++;

                // Marcar as posições vizinhas como impossíveis para peças brancas
                if (i > 0) tabuleiro[i - 1][j] = 1;     // Acima
                if (i < L - 1) tabuleiro[i + 1][j] = 1; // Abaixo
                if (j > 0) tabuleiro[i][j - 1] = 1;     // À esquerda
                if (j < C - 1) tabuleiro[i][j + 1] = 1; // À direita
            }
        }
    }

    printf("%d\n", maxPecasBrancas);

    return 0;
}
