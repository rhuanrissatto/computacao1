#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int used[36][2];
int lista_used = 0;
int coord_X[36][2];
int lista_X = 0;
int coord_O[36][2];
int lista_O = 0;
int coord_W[36][2];
int lista_W = 0;
int coord_B[36][2];
int lista_B = 0;

int jogo = 1;

int ponto(int X, int Y, char simbolo){
    for(int i = 0; i < 36; i++){
        for(int j = 0; j < 36; j++){
            if(used[i][0] == X && used[i][1] == Y){
                return 1;
            }
        }
    }
    if(simbolo == 'X'){
        coord_X[lista_X][0] = X;
        coord_X[lista_X][1] = Y;
        lista_X++;
    }else if(simbolo == 'O'){
        coord_O[lista_O][0] = X;
        coord_O[lista_O][1] = Y;
        lista_O++;
    }else if(simbolo == 'W'){
        coord_W[lista_W][0] = X;
        coord_W[lista_W][1] = Y;
        lista_W++;
    }else if(simbolo == '-'){
        coord_B[lista_B][0] = X;
        coord_B[lista_B][1] = Y;
        lista_B++;
    }
    used[lista_used][0] = X;
    used[lista_used][1] = Y;
    return 0;
}

int preencher_tab(int dimensao,int coord_X[][2],int coord_O[][2],int coord_W[][2]){
    
    for(int i = 1; i<dimensao+1; i++){
        printf("\n");
        for(int j=1; j<dimensao+1; j++){
            int cXe = 0;
            int cOe = 0;
            int cWe = 0;
            int cBe = 0;
            
            for(int k = 0; k<36; k++){
                if(i == coord_X[k][0] && j == coord_X[k][1]){
                    cXe = 1;
                }
                if(i == coord_O[k][0] && j == coord_O[k][1]){
                    cOe = 1;
                }
                if(i == coord_W[k][0] && j == coord_W[k][1]){
                    cWe = 1;
                }
                if(i == coord_B[k][0] && j == coord_B[k][1]){
                    cBe = 1;
                }
            }
            
            if(cXe == 1){
                printf("X ");
            }else if(cOe == 1){
                printf("O ");
            }else if(cWe == 1){
                printf("W ");
            }else if(cBe == 1){
                printf("- ");
            }else{
                printf("° ");
            }
            }
        }
        printf("\n");
        return 0;
    }
 

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //ponto(1,2,'X');
    //ponto(5,6, 'O');
    //ponto(3,1,'W');
    //ponto(4,4,'-');
    preencher_tab(6, coord_X, coord_O, coord_W);
    while(jogo){
        int x, y;
        printf("\nJogador 1: Digite as coordenadas da sua jogada (X, Y)");
        scanf("%d %d", &x, &y);
        while(ponto(x, y, 'X') == 1){
            printf("\nEssas coordenadas estão ocupadas! Redija as coordenadas da sua jogada (X, Y)");
            scanf("%d %d", &x, &y);
        }
        preencher_tab(6, coord_X, coord_O, coord_W);
        printf("\nJogador 2: Digite as coordenadas da sua jogada (X, Y)");
        scanf("%d %d", &x, &y);
        ponto(x, y, 'O');
        preencher_tab(6, coord_X, coord_O, coord_W);
        x = rand() % 6 + 1;
        y = rand() % 6 + 1;
        //printf("%d %d", x, y);
        ponto(x, y, 'W');
        preencher_tab(6, coord_X, coord_O, coord_W);
    }
    
    return 0;
}

