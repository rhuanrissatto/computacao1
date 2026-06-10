#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int coord_X[12][2] ={
    {}}
}
int coord_O[12][2];
int coord_Z[12][2];



int preencher_tab(int dimensao){
    for(int i = 0; i<dimensao; i++){
        printf("\n");
        for(int j=0; j<dimensao; j++){
            
            printf("%d", &coord_X[i][0]);
            printf("° ");
        }
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    preencher_tab(6);
    
    return 0;
}

