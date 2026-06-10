#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define DIMENSAO 6

int coord_X[36][2];
int lista_X = 0;
int coord_O[36][2];
int lista_O = 0;
int coord_W[36][2];
int lista_W = 0;

int ponto(int X, int Y, char simbolo){
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
    }
    return 0;
}

int preencher_tab(int dimensao,int coord_X[][2],int coord_O[][2],int coord_W[][2]){
    
    for(int i = 1; i<dimensao+1; i++){
        printf("\n");
        for(int j=1; j<dimensao+1; j++){
            int cXe = 0;
            int cOe = 0;
            int cWe = 0;
        
            
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
            }
            
            if(cXe == 1){
                printf("X ");
            }else if(cOe == 1){
                printf("O ");
            }else if(cWe == 1){
                printf("W ");
            }else{
                printf("° ");
            }
            
            }
        }
        return 0;
    }
 

int main()
{
    setlocale(LC_ALL, "Portuguese");
    ponto(1,2,'X');
    ponto(5,6, 'O');
    ponto(3,1,'W');
    preencher_tab(6, coord_X, coord_O, coord_W);
    
    return 0;
}

