#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

void geramatriz(int coluna){
    int aleat=0, vetor[coluna*coluna], n=0, aux=0, cont=1, i, j, matriz[coluna][coluna], limite=0, soma=0, somacol[coluna], somarow[coluna], somadia1=0, somadia2=0;
    srand(time(NULL));

    //formula que delimita "numero magico"
    limite = (coluna*((coluna*coluna) +1))/2;

    //recebe a matriz de acordo com numero de colunas
    for(i=0; i<coluna; i++){
        for(j=0; j<coluna; j++){
            matriz[i][j] = cont;
            cont++;
        }
    }

    //transforma matriz 2d em vetor 1d
    for(i=0; i <coluna; i++){
        for(j=0; j <coluna; j++){
            vetor[n] = matriz[i][j];
            n++;
        }
    }

    //ponto de retorno para randomizar
    refazerdia1:
    refazerdia2:
    refazerrow:
    refazercol:

    //zerando as variaveis de soma no loop
    somadia1=0;
    somadia2=0;
    for(i=0;i<coluna;i++){
        somarow[i] = 0;
        somacol[i] = 0;
    }
    fflush(stdin);
    //randomiza vetor
    for(n=0; n< coluna*coluna; n++){
        aleat = (rand()%(coluna*coluna)-1)+1;
        aux = vetor[n];
        vetor[n] = vetor[aleat];
        vetor[aleat] = aux;
    }

    //transforma vetor 1d em matriz 2d
    n=0;
    for(i=0; i <coluna; i++){
        for(j=0; j <coluna; j++){
            matriz[i][j] = vetor[n];
            n++;
        }
    }

    //Verificação de valores
    for(j=0 ; j< coluna; j++){//colunas
        soma = 0;
        for(i=0; i < coluna; i++){
            soma += matriz[i][j];
        }
        somacol[j] = soma;
    }

    for(i=0 ; i< coluna; i++){//linhas
        soma = 0;
        for(j=0; j < coluna; j++){
            soma += matriz[i][j];
        }
        somarow[i] = soma;
    }
    soma=0;
    for(i=0 ; i< coluna; i++){//diagonal 1
        for(j=0; j < coluna; j++){
            if(i==j){
                soma += matriz[i][i];
            }
        }
        somadia1 = soma;
    }

    soma=0;
    for(i=0 ; i < coluna; i++){//diagonal 2
        for(j=0; j < coluna; j++){
            if(i + j == coluna - 1){
                soma += matriz[i][j];
            }
        }
        somadia2 = soma;
    }

    if(somadia1 != limite){
        goto refazerdia1;
    }

    if(somadia2 != limite){
        goto refazerdia2;
    }

    for(i=0; i < coluna; i++){
        if(somarow[i] != limite){
            goto refazerrow;
        }
    }
    for(j=0; j < coluna; j++){
        if(somacol[j] != limite){
            goto refazercol;
        }
    }
    for(i=0; i < coluna; i++){
        for(j=0; j<coluna; j++){
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
    //printf("%d", limite);
    //printf("\nDia1 = %d\n Dia2 = %d", somadia1, somadia2);

    //for(i=0; i<coluna; i++){
        //printf("\nLinha[%d] = %d", i, somarow[i]);
        //printf("\nColuna[%d] = %d",i, somacol[i]);
    //}
}

int main(){
    int coluna;
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &coluna);
    geramatriz(coluna);
}
