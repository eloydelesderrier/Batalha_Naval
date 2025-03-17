#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar um navio horizontal ou vertical
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            if (coluna + TAMANHO_NAVIO > TAMANHO || tabuleiro[linha][coluna + i] == NAVIO) return 0;
            tabuleiro[linha][coluna + i] = NAVIO;
        } else if (orientacao == 'V') {
            if (linha + TAMANHO_NAVIO > TAMANHO || tabuleiro[linha + i][coluna] == NAVIO) return 0;
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    return 1;
}

// Função para posicionar um navio diagonal
int posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'D') {
            if (linha + TAMANHO_NAVIO > TAMANHO || coluna + TAMANHO_NAVIO > TAMANHO || tabuleiro[linha + i][coluna + i] == NAVIO) return 0;
            tabuleiro[linha + i][coluna + i] = NAVIO;
        } else if (direcao == 'E') {
            if (linha + TAMANHO_NAVIO > TAMANHO || coluna - TAMANHO_NAVIO < -1 || tabuleiro[linha + i][coluna - i] == NAVIO) return 0;
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
    return 1;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionar navios horizontais e verticais
    posicionarNavio(tabuleiro, 2, 3, 'H');
    posicionarNavio(tabuleiro, 5, 6, 'V');
    
    // Posicionar navios diagonais
    posicionarNavioDiagonal(tabuleiro, 0, 0, 'D'); // Diagonal para a direita
    posicionarNavioDiagonal(tabuleiro, 0, 9, 'E'); // Diagonal para a esquerda
    
    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
