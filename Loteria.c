#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    
    srand(time(0));
    
    //Valores à serem acertados
    int valor1 = rand() % 20 + 1;
    int valor2 = rand() % 20 + 1;
    int valor3 = rand() % 20 + 1;
    
    while(valor1 == valor2 || valor1 == valor3){
        valor1 = rand() % 20 + 1;
    }
    while(valor2 == valor3 || valor2 == valor1){
        valor2 = rand() % 20 + 1;
    }

    
    //printf("v1: %d \nv2: %d \nv3: %d\n", valor1, valor2, valor3);
    //Acertos
    int acerto1 = 0;
    int acerto2 = 0;
    int acerto3 = 0;
    
    int dinheiroGasto = 0;
    
    int numTentativas = 0;
    
    while(1){
        numTentativas += 1;
        
        int chute1, chute2, chute3;
        int chuteCorreto = 0;
        
        printf("Digite seu chute para o número! (Tentativa núm. %d)\n", numTentativas);
        scanf("%d %d %d", &chute1, &chute2, &chute3);
        
        int c[3] = {chute1, chute2, chute3};
      
        for(int i = 0; i <= 2; i++){
            int chute = c[i];
            if(chute == valor1 && acerto1 == 0){
                chuteCorreto = 1;
                acerto1 = 1;
            }    
            if(chute == valor2 && acerto2 == 0){
                chuteCorreto = 1;
                acerto2 = 1;
            }
            if(chute == valor3 && acerto3 == 0){
                chuteCorreto = 1;
                acerto3 = 1;
            }
        }
        
        if(chuteCorreto == 1){
            printf("Parabéns! você acertou %d números\n", (acerto1+acerto2+acerto3));
        }
        
        if(acerto1 && acerto2 && acerto3){
            char resposta = 'n';
            dinheiroGasto += numTentativas;
            if(numTentativas <= 30){
                printf("Parabéns você é ÓTIMO! Você conseguiu acertar com %d tentativas!\n", numTentativas);
            }else if(numTentativas <= 60){
                printf("Parabéns você é BOM! Você conseguiu acertar com %d tentativas!\n", numTentativas);
            }else if(numTentativas <= 100){
                printf("Credo você é FRACO! Você conseguiu acertar com %d tentativas!\n", numTentativas);
                printf("Você quer tentar novamente? (s/n)\n");
                scanf(" %c", &resposta);
            }else if(numTentativas > 100){
                printf("Você é PÉSSIMO! Você acertou com %d tentativas!\n", numTentativas);
                printf("Você quer tentar novamente? (s/n)\n");
                scanf(" %c", &resposta);
            }
            if(resposta == 's'){
                numTentativas = 0;
                acerto1 = 0;
                acerto2 = 0;
                acerto3 = 0;
                
                valor1 = rand() % 20 + 1;
                valor2 = rand() % 20 + 1;
                valor3 = rand() % 20 + 1;
                while(valor1 == valor2 || valor1 == valor3){
                    valor1 = rand() % 20 + 1;
                }
                while(valor2 == valor3 || valor2 == valor1){
                    valor2 = rand() % 20 + 1;
                }
                //printf("v1: %d \nv2: %d \nv3: %d\n", valor1, valor2, valor3);
                continue;
            }else{
                printf("Você gastou um total de %d R$", dinheiroGasto);
                break;
            }
        }else{
            acerto1 = 0;
            acerto2 = 0;
            acerto3 = 0;
            continue;
        }
    }
    
    return 0;
}
