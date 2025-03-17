#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    for (int i =0; i < TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            tabuleiro[i][j] = AGUA;
        }
    };
}

// Função para posicionar um navio horizontal ou vertical
int posicionaNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            if (coluna + TAMANHO_NAVIO > TAMANHO || tabuleiro[linha][coluna + i] == NAVIO) return 0;
            tabuleiro[linha][coluna + i] = NAVIO;
        } else if (orientacao == 'V') {
            if (linha + TAMANHO_NAVIO > TAMANHO || tabuleiro[linha + i][coluna] == NAVIO) return 0;
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    return 1; // Return 1 to indicate success
}

// Função para posicionar um navio diagonal
int posicaoNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'D') {
            if (linha + TAMANHO_NAVIO > TAMANHO || coluna + TAMANHO_NAVIO > TAMANHO || tabuleiro[linha + i][coluna + i] == NAVIO) return 0;
            tabuleiro[linha + i][coluna + i] = NAVIO;
        } else if (direcao == 'E') {
            if (linha + TAMANHO_NAVIO > TAMANHO || coluna - TAMANHO_NAVIO < 0 || tabuleiro[linha + i][coluna - i] == NAVIO) return 0;
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
    return 1; // Return 1 to indicate success
}

// Função para exibir as habiliades do navio
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char tipo){
    if (tipo == 'C'){ // Cruz
        for (int i= -2; i <=2; i++){
            if (linha + i >=0 && linha + i < TAMANHO) tabuleiro[linha + i][coluna] = HABILIDADE;
            if (coluna + i >=0 && coluna + i < TAMANHO) tabuleiro[linha][coluna + i] = HABILIDADE;
        }
    }else if (tipo =='O'){ // Octaedro (losango)
        for (int i = -2; i<=2; i++){
            for (int j = -2; j <=2; j++){
                if (abs(i) + abs(j)<=2 && linha + i >=0 && linha + i < TAMANHO && coluna + j >=0 && coluna +j < TAMANHO){
                    tabuleiro[linha+1][coluna+j] = HABILIDADE;
                }
            }
        }
    }else if (tipo == 'N'){ // Cone 
        for (int i =-2; i <=2; i++){
            for (int j = -2; j<=2; j++){
                if (linha + i <TAMANHO && coluna + j >=0 && coluna + j < TAMANHO){
                    tabuleiro[linha+i][coluna+j] = HABILIDADE;
                }
            }
        }
    }
}


// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]){
    for (int i = 0; i< TAMANHO; i++){
        for (int j = 0; j < TAMANHO; j++){
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    };
}

int main(){
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios horizontais e verticais
    posicionaNavio(tabuleiro,2,3,'H');
    posicionaNavio(tabuleiro,5,6,'V');

    posicaoNavioDiagonal(tabuleiro, 0, 0,'D');
    posicaoNavioDiagonal(tabuleiro, 0, 9,'E');

    // Aplicar habilidades
    aplicarHabilidade(tabuleiro, 4, 4, 'C'); // Cruz
    aplicarHabilidade(tabuleiro, 6, 6, 'O'); // Octaedro
    aplicarHabilidade(tabuleiro, 2, 5, 'N'); // Cone

    // exibir tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
