#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 6

char tabuleiro[TAM][TAM];

void inicializar() {
    for(int i=0;i<TAM;i++) {
        for(int j=0;j<TAM;j++) {
            tabuleiro[i][j] = '.';
        }
    }
}

void imprimir() {
    printf("\n");

    for(int i=0;i<TAM;i++) {
        for(int j=0;j<TAM;j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int valido(int x,int y) {
    return x >= 1 && x <= TAM &&
           y >= 1 && y <= TAM;
}

void verificar_bloqueio(int x,int y,char simbolo) {

    int linha = y-1;
    int coluna = x-1;

    /* esquerda */

    if(coluna >= 2 &&
       tabuleiro[linha][coluna-2] == simbolo) {

        if(tabuleiro[linha][coluna-1] == '.')
            tabuleiro[linha][coluna-1] = '-';
        else
            tabuleiro[linha][coluna-1] = simbolo;
    }

    /* direita */

    if(coluna <= TAM-3 &&
       tabuleiro[linha][coluna+2] == simbolo) {

        if(tabuleiro[linha][coluna+1] == '.')
            tabuleiro[linha][coluna+1] = '-';
        else
            tabuleiro[linha][coluna+1] = simbolo;
    }

    /* cima */

    if(linha >= 2 &&
       tabuleiro[linha-2][coluna] == simbolo) {

        if(tabuleiro[linha-1][coluna] == '.')
            tabuleiro[linha-1][coluna] = '-';
        else
            tabuleiro[linha-1][coluna] = simbolo;
    }

    /* baixo */

    if(linha <= TAM-3 &&
       tabuleiro[linha+2][coluna] == simbolo) {

        if(tabuleiro[linha+1][coluna] == '.')
            tabuleiro[linha+1][coluna] = '-';
        else
            tabuleiro[linha+1][coluna] = simbolo;
    }
}

int jogar(int x,int y,char simbolo) {

    if(!valido(x,y))
        return 1;

    int linha = y-1;
    int coluna = x-1;

    if(tabuleiro[linha][coluna] != '.')
        return 1;

    tabuleiro[linha][coluna] = simbolo;

    verificar_bloqueio(x,y,simbolo);

    return 0;
}

void computador() {

    int x,y;

    do {
        x = rand()%6 + 1;
        y = rand()%6 + 1;
    }
    while(jogar(x,y,'W'));
}

void contar_pontos(int *X,int *O,int *W,int *B) {

    *X = *O = *W = *B = 0;

    for(int i=0;i<TAM;i++) {
        for(int j=0;j<TAM;j++) {

            switch(tabuleiro[i][j]) {

                case 'X':
                    (*X)++;
                    break;

                case 'O':
                    (*O)++;
                    break;

                case 'W':
                    (*W)++;
                    break;

                case '-':
                    (*B)++;
                    break;
            }
        }
    }
}

int cheio() {

    for(int i=0;i<TAM;i++) {
        for(int j=0;j<TAM;j++) {

            if(tabuleiro[i][j] == '.')
                return 0;
        }
    }

    return 1;
}

int main() {

    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    inicializar();

    while(!cheio()) {

        int x,y;

        imprimir();

        printf("\nJogador 1 (X): ");
        scanf("%d %d",&x,&y);

        while(jogar(x,y,'X')) {
            printf("Posição inválida!\n");
            scanf("%d %d",&x,&y);
        }

        if(cheio()) break;

        imprimir();

        printf("\nJogador 2 (O): ");
        scanf("%d %d",&x,&y);

        while(jogar(x,y,'O')) {
            printf("Posição inválida!\n");
            scanf("%d %d",&x,&y);
        }

        if(cheio()) break;

        computador();
    }

    imprimir();

    int X,O,W,B;

    contar_pontos(&X,&O,&W,&B);

    printf("\n\nResultado Final\n");

    printf("Jogador 1 (X): %d\n",X);
    printf("Jogador 2 (O): %d\n",O);
    printf("Computador (W): %d\n",W);
    printf("Bloqueios (-): %d\n",B);

    if(X > O && X > W)
        printf("\nJogador 1 venceu!\n");
    else if(O > X && O > W)
        printf("\nJogador 2 venceu!\n");
    else if(W > X && W > O)
        printf("\nComputador venceu!\n");
    else
        printf("\nEmpate!\n");

    return 0;
}
