#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int contagem_de_acertos(int numeros[], int apostas[])
{

    int numero_de_acertos = 0;

    for(int n = 0; n <= 3; n++){
        //printf("%d",numeros[1]);
        //printf("%d , %d , %d , %d", apostas[1], apostas[2], apostas[3], apostas[4]);
        if(numeros[n] == apostas[0] || numeros[n] == apostas[1] || numeros[n] == apostas[2] || numeros[n] == apostas[3]){
            numero_de_acertos++;
            //printf("Você acertou! %d é um dos número(s) sorteados!\n", numeros[n]);
        }
    }
    return numero_de_acertos;
}

void sorteia_numeros(int numeros[])
{
    
    numeros[0] = rand()%15+1;
    numeros[1] = rand()%15+1;
    
    while (numeros[1] == numeros[0])
        numeros[1] = rand()%15+1;

    numeros[2] = rand()%15+1;
    
    while(numeros[2] == numeros[0] || numeros[2] == numeros[1])
        numeros[2] = rand()%15+1;
        
    numeros[3] = rand()%15+1;
    
    while(numeros[3] == numeros[0] || numeros[3] == numeros[1] || numeros[3] == numeros[2])
        numeros[3] = rand()%15+1;
    
}


int main()
{
    int numero_de_acertos;
    int tentativas;
    int dinheiro_gasto = 0;



    setlocale(LC_ALL, "Portuguese");
    srand(time(0));

    while(1)
    {
        tentativas = 0;
        int numeros[4];

        sorteia_numeros(numeros);
        
        //printf("%d /n",numeros[0]);
        //printf("Resultado do sorteio: %d %d %d %d\n", numeros[0], numeros[1], numeros[2], numeros[3]);

        do
        {
            tentativas++;
            dinheiro_gasto += 6;
            //printf("Dinheiro Gasto: %d \n", dinheiro_gasto);
            printf("Digite quatro números entre 1 e 15 (tentativa %d): ", tentativas);
            
            int apostas[4];
            
            for(int i = 0; i <= 3; i++){
                scanf("%d", &apostas[i]);
            }
           
            numero_de_acertos = contagem_de_acertos(numeros, apostas);
            
            printf("Você acertou %d números na sua aposta!\n", numero_de_acertos);
        }
        while (numero_de_acertos !=4);

        printf("Você conseguiu em %d tentativa(s) e gastou %d reais\n", tentativas, dinheiro_gasto);

        if (tentativas <= 10)
        {
            printf("Você é ÓTIMO!\n");
            break;
        }
        else if (tentativas <=15)
        {
            printf("Você é BOM!\n");
            break;
        }
        else if (tentativas <=25)
        {
            printf("Você é FRACO!\n");
        }
        else
        {
            printf("Você é PÉSSIMO!\n");
        }

        while ( getchar() != '\n' );
        char c;
        printf("Deseja continuar? (S/N):");
        scanf("%c", &c);
        if (c != 'S')
        {
            break;
        }


    }
    return 0;
}
