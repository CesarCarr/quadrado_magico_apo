/* QUADRADO MáGICO
N�VEL 1 - 3X3
Soma = 15
Fácil - 2 valores
Intermediário - 0 valor
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#define NUML 4
#define NUMC 4

//Adicionar limite para valor ser 15 em todas as funções de soma

void printfmatriz(int coluna, int matriz[][coluna]){//função que printa a matriz novamente
    int i, j;
    printf("\n\n");
    for(i=0; i< coluna; i++){
        for(j=0; j < coluna; j++){
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
}

void SomarCol(int coluna, int matriz[][coluna]){ //função que soma colunas
    int i, j, soma, somacol[coluna];

    for(j=0 ; j< coluna; j++){
        soma = 0;
        for(i=0; i < coluna; i++){
            soma += matriz[i][j];
        }
        somacol[j] = soma;
    }
    for(j=0; j<3; j++){
        printf("\nA soma da coluna %d é: %d\n", j, somacol[j]);
        if(somacol[j] > 15){
            printf("\n\nA coluna %d ultrapassou o valor máximo de 15. Tente novamente!", j);
        }
    }
}

void SomarRow(int coluna, int matriz[][coluna]){//função que soma as linhas
    int i, j, soma, somarow[coluna];

    for(i=0 ; i< coluna; i++){
        soma = 0;
        for(j=0; j < coluna; j++){
            soma += matriz[i][j];
        }
        somarow[i] = soma;
    }
    for(i=0; i<3; i++){
        printf("\nA soma da linha %d é: %d\n", i, somarow[i]);
        if(somarow[i] > 15){
            printf("\n\nA linha %d ultrapassou o valor máximo de 15. Tente novamente!", i);
        }
    }
}

int SomarDia1(){
    int i, j, somaDia1[3];

}
int SomarDia2(){
}
int matriz1(){
        int i, j;
        char nome[30];
        int escolha2;
        int cont_matriz = 0;
        int test1=3;

        printf("Voce prefere ir pelo caminho (1)facil ou (2)Intermediario\n ");
        scanf("%d", &escolha2);

        if(escolha2 == 1){
            int matriz[3][3]={{0,0,0},
                            {0,0,7},
                            {0,1,0}};
        // Print Matriz vazia
          for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                printf("%5d", matriz[i][j]);
            }
            printf("\n");
        }
        // Inserção de dados da matriz
        for ( i=0; i<3; i++ ){
            for ( j=0; j<3; j++ ){
                voltar:
                printf("\nEscolha a linha=");
                scanf("%d", &i);
                printf("\nEscolha a coluna= ");
                scanf("%d", &j);

			// validação da linha e coluna
                if((i == 1)&& (j==2)){
                    printf("Esse valor ja foi preenchido");
                    matriz[1][2]= 7;
                    goto voltar;
                }
                if((i == 2)&& (j==1)){
                    printf("Esse valor ja foi preenchido");
                    matriz[2][1]= 1;
                    goto voltar;
                }
            // validação da linha e coluna
                if(( i > 2) && (j > 2)){
                    printf("valor de linha/coluna invalido");
                    goto voltar;
                }else{
                    printf ("\nValor [%d][%d] = ",i,j);
                    scanf ("%d", &matriz[ i ][ j ]);
                }
                //chamando as funções que verificam a matriz
                SomarRow(3, matriz);
                SomarCol(3, matriz);
                printfmatriz(3, matriz);
                //SomarDia1(3, matriz);
                //SomarDia2(3, matriz);
            }
        }
        }
    return(0);
}

int main(){
        int escolha, nivel1(), nivel2();
        char nome[50];
        setlocale(LC_ALL,"");

    // Introducão
        printf("\tSeja bem vindo(a) ao Cubo dos 15 reis.\n");
        printf("\tPermito que diga seu nome, barbaro(a).\n");
        scanf("\t %s",&nome);
    // retorno do nome
        printf("\t%s...um nome realmente estranho.\n",nome);
        printf("\tVai se atrever a tentar resolver o cubo ou ir� correr com o rabo entre as pernas??\n");
    // Escolhas
        printf("\t\nEscolha sua opção de jogo: ");
        printf("\t\n1 - Quadrado 3x3 de 1 a 9");
        printf("\t\n2 - Quadrado 4x4 de 1 a 16");
        printf("\t\n3 - Fechar o Jogo\n");
        fflush(stdin); //Limpar os espa�os
        scanf("%d", &escolha);

    // Escolha da matriz
        switch (escolha) {
        case 1:
            matriz1(); //fun��o nivel1
        break;
        case 2:
            //matriz2(); //fun��o nivel2
        break;
        case 3:
            return 0;
        break;
        default:
            printf("\t\nEscolha um modo de jogo válido");
            main();
        break;
    }
}
