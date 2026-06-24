#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 6

char tabuleiro[TAM][TAM];


/* Preenche o tabuleiro inicialmente com posições vazias */

void inicializar() {

    for(int i=0;i<TAM;i++) {
        for(int j=0;j<TAM;j++) {

            tabuleiro[i][j] = '.';
        }
    }
}


/* Salva o estado atual do tabuleiro no arquivo de registro */

void salvar_tabuleiro(FILE *arquivo) {

    for(int i=0;i<TAM;i++) {
        for(int j=0;j<TAM;j++) {

            fprintf(arquivo,"%c ",tabuleiro[i][j]);
        }

        fprintf(arquivo,"\n");
    }

    fprintf(arquivo,"\n");
}


/* Mostra o tabuleiro atual no terminal */

void imprimir() {

    printf("\n");

    for(int i=0;i<TAM;i++) {
        for(int j=0;j<TAM;j++) {

            printf("%c ", tabuleiro[i][j]);
        }

        printf("\n");
    }
}


/* Verifica se a posição informada está dentro dos limites do tabuleiro */

int valido(int x,int y) {

    return x >= 1 && x <= TAM &&
           y >= 1 && y <= TAM;
}


/* Verifica se a jogada gera algum bloqueio em alguma direção */

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


/* Realiza uma jogada caso a posição esteja disponível */

int jogar(int x,int y,char simbolo) {


    // verifica se a posição existe

    if(!valido(x,y))
        return 1;


    int linha = y-1;
    int coluna = x-1;


    // impede jogar em posições ocupadas

    if(tabuleiro[linha][coluna] != '.')
        return 1;


    tabuleiro[linha][coluna] = simbolo;


    // após a jogada verifica se criou bloqueios

    verificar_bloqueio(x,y,simbolo);


    return 0;
}


/* Escolhe uma posição aleatória para o computador jogar */

void computador() {

    int x,y;

    do {

        x = rand()%6 + 1;
        y = rand()%6 + 1;

    } while(jogar(x,y,'W'));
}


/* Conta quantas peças de cada tipo existem no tabuleiro */

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


/* Verifica se todas as posições possíveis foram preenchidas */

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


    FILE *registro;


    // cria o arquivo onde a partida será salva

    registro = fopen("registro_jogo.txt","w");


    if(registro == NULL) {

        printf("Erro ao criar arquivo!\n");
        return 1;
    }


    fprintf(registro,"=== REGISTRO DA PARTIDA ===\n\n");


    inicializar();


    // continua enquanto existirem posições livres

    while(!cheio()) {


        int x,y;


        imprimir();


        printf("\nJogador 1 (X): ");
        scanf("%d %d",&x,&y);


        // repete caso a posição escolhida seja inválida

        while(jogar(x,y,'X')) {

            printf("Posição inválida!\n");
            scanf("%d %d",&x,&y);
        }


        fprintf(registro,"Jogador 1 (X): %d %d\n",x,y);
        salvar_tabuleiro(registro);


        if(cheio()) break;


        imprimir();


        printf("\nJogador 2 (O): ");
        scanf("%d %d",&x,&y);


        while(jogar(x,y,'O')) {

            printf("Posição inválida!\n");
            scanf("%d %d",&x,&y);
        }


        fprintf(registro,"Jogador 2 (O): %d %d\n",x,y);
        salvar_tabuleiro(registro);


        if(cheio()) break;


        // jogada automática do computador

        computador();
    }


    imprimir();


    int X,O,W,B;


    contar_pontos(&X,&O,&W,&B);



    printf("\n\nResultado Final\n");

    fprintf(registro,"Resultado Final\n");


    printf("Jogador 1 (X): %d\n",X);
    fprintf(registro,"Jogador 1 (X): %d\n",X);


    printf("Jogador 2 (O): %d\n",O);
    fprintf(registro,"Jogador 2 (O): %d\n",O);


    printf("Computador (W): %d\n",W);
    fprintf(registro,"Computador (W): %d\n",W);


    printf("Bloqueios (-): %d\n",B);
    fprintf(registro,"Bloqueios (-): %d\n",B);



    if(X > O && X > W) {

        printf("\nJogador 1 venceu!\n");
        fprintf(registro,"Jogador 1 venceu!\n");

    } else if(O > X && O > W) {

        printf("\nJogador 2 venceu!\n");
        fprintf(registro,"Jogador 2 venceu!\n");

    } else if(W > X && W > O) {

        printf("\nComputador venceu!\n");
        fprintf(registro,"Computador venceu!\n");

    } else {

        printf("\nEmpate!\n");
        fprintf(registro,"Empate!");
    }


    // fecha o arquivo de registro

    fclose(registro);


    return 0;
}
