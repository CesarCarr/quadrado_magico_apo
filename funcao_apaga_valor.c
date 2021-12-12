#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

void apagavalor(int coluna){
    int vetor[coluna*coluna], n=0, i, j, aleat=0, matriz[coluna][coluna], cont=1;
    srand(time(NULL));

    //matriz random para testes
    for(i=0; i<coluna; i++){
        for(j=0; j<coluna; j++){
            matriz[i][j] = cont;
            cont++;
        }
    }
    printf("\n\n\n");

    //printa a matriz

    for(i=0; i<coluna; i++){
        for(j=0; j<coluna; j++){
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");

    //transforma matriz 2d em vetor 1d
    n=0;
    for(i=0; i <coluna; i++){
        for(j=0; j <coluna; j++){
            vetor[n] = matriz[i][j];
            n++;
        }
    }

    //Apaga valores do vetor
    if(coluna == 3){
        aleat = rand()% 3;
        for(n=0; n < 7; n++){
            vetor[aleat+n] = 0;
        }
    }
    else{
        for(n=0; n < 6; n++){
            aleat = (rand()%(coluna*coluna)-1);
            vetor[aleat] = 0;
        }
    }
    //transforma vetor 1d em matriz 2d
    n=0;
    for(i=0; i <coluna; i++){
        for(j=0; j <coluna; j++){
            matriz[i][j] = vetor[n];
            n++;
        }
    }
    //matriz com valores apagados
    for(i=0; i<coluna; i++){
        for(j=0; j<coluna; j++){
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

int main(){
    int matriz[10][10], coluna;

    printf("Insira a quantidade de colunas: ");
    scanf("%d", &coluna);

    apagavalor(coluna);
}
