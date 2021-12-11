/* QUADRADO MáGICO
NÍVEL 1 - 3X3
Soma = 15
Fácil - 2 valores
Intermediário - 0 valor
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>

int SomarCol(){ //função para verificar a soma de coluna. Ainda incompleta
    int matriz[3][3];
    int i=0, j=0;
    int somacol;

    for(i=0 ; i< 3; i++){
        somacol += matriz[i][j];
        if(somacol>15){
        printf("\nA soma da coluna %d passou de 15, tente novamente.\n",j);
    }
        for(j=0; j<3; j++){
            somacol += matriz[i][j];
            if(somacol>15){
                printf("\nA soma da coluna %d passou de 15, tente novamente.\n",j);
            }
        }
    }
}

int SomarRow(){
}
int SomarDia(){
}
int SomarDia2(){
}
int matriz1(){
    int i, j;
    char nome[30];
    int escolha2;
    int cont_matriz = 0;



    setlocale(LC_ALL,"Portuguese");
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
            // repetição para linhas e colunas
            while (cont_matriz < 7){
            printf("\nEscolha a linha=");
            scanf("%d", &i);
            printf("Escolha a coluna= ");
            scanf("%d", &j);
            cont_matriz ++;

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
                if(( i > 2) || (j > 2)){
                    printf("valor de linha/coluna invalido");
                    goto voltar;
                }else{
                printf ("\nValor [%d][%d] = ",i,j);
                scanf ("%d", &matriz[ i ][ j ]);
                    if((matriz[ i ][ j ]<1)||(matriz[ i ][ j ]>9)){
                        printf("Valor invalido");
                        goto voltar;
                    }
                }

                }
            }
        }
        // Print Matriz com novos valores
         for(i=0; i<3; i++){
            for(j=0; j<3; j++){
            printf("%5d", matriz[i][j]);
            }
                printf("\n");
        }

    return(0);
    }
    if(escolha2 == 2){

        int matriz[3][3]={{0,0,0},
                          {0,0,0},
                          {0,0,0}};
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
            voltar2:

            // repetição para linhas e colunas
            while (cont_matriz < 7){
            printf("\nEscolha a linha=");
            scanf("%d", &i);
            printf("Escolha a coluna= ");
            scanf("%d", &j);
            cont_matriz ++;


                // validação da linha e coluna
                if(( i > 2) || (j > 2)){
                    printf("valor de linha/coluna invalido");
                    goto voltar2;
                }else{
                printf ("\nValor [%d][%d] = ",i,j);
                scanf ("%d", &matriz[ i ][ j ]);
                    if((matriz[ i ][ j ]<1)||(matriz[ i ][ j ]>9)){
                        printf("Valor invalido");
                        goto voltar2;
                    }
                }

                }
            }
        }
        // Print Matriz com novos valores
         for(i=0; i<3; i++){
            for(j=0; j<3; j++){
            printf("%5d", matriz[i][j]);
            }
                printf("\n");
        }

    return(0);
    }
}

int main(){
    int escolha, nivel1(), nivel2();
    char nome[50];

    setlocale(LC_ALL,"");
    // Introdu��o
    printf("\tSeja bem vindo(a) ao Cubo dos 15 reis.\n");
    printf("\tPermito que diga seu nome, barbaro(a).\n");
    scanf("\t %s",&nome);
    // retorno do nome
    printf("\t%s...um nome realmente estranho.\n",nome);
    printf("\tVai se atrever a tentar resolver o cubo ou ir� correr com o rabo entre as pernas??\n");
    // Escolhas
    printf("\t\nEscolha sua op��o de jogo: ");
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
        printf("\t\nEscolha um modo de jogo valido");
        main();
        break;
    }
}
