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
#include <time.h>

void vitoria(int coluna, int matriz[][coluna]){
    int i, j, limite=0, soma=0, somacol[coluna], somarow[coluna], somadia1=0, somadia2=0;

    //formula que delimita "numero magico"
    limite = (coluna*((coluna*coluna) +1))/2;

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
    //condicionais para ser quadrado magico
    if(somadia1 != limite){
        return 0;
    }

    if(somadia2 != limite){
        return 0;
    }

    for(i=0; i < coluna; i++){
        if(somarow[i] != limite){
            return 0;
        }
    }
    for(j=0; j < coluna; j++){
        if(somacol[j] != limite){
            return 0;
        }
    }//frase de vitoria, apenas testando, pode mudar
    printf("\n\n*************************************************************\n\n");
    printf("\n\nParabéns! Você alcançou a vitória no QUADRADO MÁGICO!\n\n");
    printf("\n\n*************************************************************\n\n");
    return 0;
    main();
}

void apagavalor(int coluna, int matriz[][coluna]){
    int vetor[coluna*coluna], n=0, i, j, aleat=0, cont=1;

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
        aleat = rand() % 10;
        for(n=0; n < 6; n++){
            vetor[aleat + n] = 0;
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
}

void geramatriz(int coluna, int matriz[][coluna]){
    int aleat=0, vetor[coluna*coluna], n=0, aux=0, cont=1, i, j, limite=0, soma=0, somacol[coluna], somarow[coluna], somadia1=0, somadia2=0;

    //formula que delimita "numero magico"
    limite = (coluna*((coluna*coluna) +1))/2;

    //recebe a matriz de acordo com numero de colunas

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
    //condicionais para ser quadrado magico
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
}

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

void SomarCol(int coluna, int matriz[][coluna]){ //função que soma os elementos da coluna
    int i, j, soma, somacol[coluna];

    for(j=0 ; j< coluna; j++){
        soma = 0;
        for(i=0; i < coluna; i++){
            soma += matriz[i][j];
        }
        somacol[j] = soma;
    }

    for(j=0; j< coluna; j++){
        printf("\nA soma da coluna %d é: %d\n", j, somacol[j]);
        if(coluna == 3){
            if(somacol[j] > 15){
            printf("\n\nA coluna %d ultrapassou o valor máximo de 15. Tente novamente!", j);
        }
        }
        if(coluna == 4){
            if(somacol[j] > 34){
            printf("\n\nA coluna %d ultrapassou o valor máximo de 34. Tente novamente!", j);
            }
        }
    }
}

void SomarRow(int coluna, int matriz[][coluna]){//função que soma os elementos da linha
    int i, j, soma, somarow[coluna];

    for(i=0 ; i< coluna; i++){
        soma = 0;
        for(j=0; j < coluna; j++){
            soma += matriz[i][j];
        }
        somarow[i] = soma;
    }
    for(i=0; i<coluna; i++){
        printf("\nA soma da linha %d é: %d\n", i, somarow[i]);
        if(coluna == 3){
            if(somarow[i] > 15){
            printf("\n\nA linha %d ultrapassou o valor máximo de 15. Tente novamente!", i);
        }
        }
        if(coluna == 4){
            if(somarow[i] > 34){
            printf("\n\nA linha %d ultrapassou o valor máximo de 34. Tente novamente!", i);
            }
        }
    }
}

void SomarDia1(int coluna, int matriz[][coluna]){//função que soma os elementos da diagonal principal
    int i, j, soma=0, somadia1=0;

    for(i=0 ; i< coluna; i++){
        for(j=0; j < coluna; j++){
            if(i==j){
                soma += matriz[i][i];
            }
        }
    }
    somadia1 = soma;
    printf("\nA soma da diagonal principal é: %d\n", somadia1);
    if(coluna == 3){
        if(somadia1 > 15){
        printf("\n\nA diagonal principal ultrapassou o valor máximo de 15. Tente novamente!");
        }
    }
    if(coluna == 4){
        if(somadia1 > 34){
            printf("\n\nA diagonal principal ultrapassou o valor máximo de 34. Tente novamente!");
        }
    }
}

void SomarDia2(int coluna, int matriz[][coluna]){//função que soma os elementos da diagonal secundaria
    int i, j, soma=0, somadia2=0;

    for(i=0 ; i < coluna; i++){
        for(j=0; j < coluna; j++){
            if(i + j == coluna - 1){
                soma += matriz[i][j];
            }
        }
    }
    somadia2 = soma;
    printf("\nA soma da diagonal secundária é: %d\n", somadia2);
    if(coluna == 3){
        if(somadia2 > 15){
        printf("\n\nA diagonal secundária ultrapassou o valor máximo de 15. Tente novamente!");
        }
    }
    if(coluna == 4){
        if(somadia2 > 34){
            printf("\n\nA diagonal secundária ultrapassou o valor máximo de 34. Tente novamente!");
        }
    }
}
int matriz1(){
    int i=0, j=0, matriz[3][3], cont=1;
    char nome[30];
    int escolha2;
    int cont_matriz = 0;

    printf("Voce prefere ir pelo caminho (1)facil ou (2)Intermediario\n ");
    scanf("%d", &escolha2);

    if(escolha2 == 1){
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                matriz[i][j] = cont;
                cont++;
            }
        }
        geramatriz(3, matriz);
        apagavalor(3, matriz);
        printfmatriz(3, matriz);
        // Inserção de dados da matriz
        for ( i=0; i<3; i++ ){
            for ( j=0; j<3; j++ ){
            voltar:
            // repetição para linhas e colunas
            while (cont_matriz < 18){
            printf("\nEscolha a linha=");
            scanf("%d", &i);
            printf("Escolha a coluna= ");
            scanf("%d", &j);
            cont_matriz ++;

                // validação da linha e coluna
                if(( i > 2) || (j > 2)){
                    printf("valor de linha/coluna invalido");
                    goto voltar;
                }else{
                printf("\nTentativas restantes = %d", 18 - cont_matriz);
                printf ("\nValor [%d][%d] = ",i,j);
                scanf ("%d", &matriz[ i ][ j ]);
                    if((matriz[ i ][ j ]<1)||(matriz[ i ][ j ]>9)){
                        printf("Valor invalido");
                        goto voltar;
                    }
                }
                SomarRow(3, matriz);
                SomarCol(3, matriz);
                SomarDia1(3, matriz);
                SomarDia2(3, matriz);
                printfmatriz(3, matriz);
                vitoria(3, matriz);

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

        int matriz2[3][3]={{0,0,0},
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
            while (cont_matriz < 9){
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
                SomarRow(3, matriz);
                SomarCol(3, matriz);
                SomarDia1(3, matriz);
                SomarDia2(3, matriz);
                printfmatriz(3, matriz);
                vitoria(3, matriz);
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

int matriz2(){
    int i, j;
    char nome[30];
    int escolha2;
    int cont_matriz = 0;

    printf("Voce prefere ir pelo caminho (1)facil ou (2)Intermediario\n ");
    scanf("%d", &escolha2);

    if(escolha2 == 1){

        int matriz[4][4]={{16,2,3,13},
                          {5,11,10,8},
                          {9,7,6,12},
                          {4,14,15,1}};

        apagavalor(4, matriz);
        // Print Matriz vazia
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
            printf("%5d", matriz[i][j]);
            }
                printf("\n");
        }
        printf("\n\n\n\n\n");

        // Inserção de dados da matriz
        for ( i=0; i<4; i++ ){
            for ( j=0; j<4; j++ ){
            voltar3:
            // repetição para linhas e colunas
                while (cont_matriz < 13){
                printf("\nEscolha a linha=");
                scanf("%d", &i);
                printf("Escolha a coluna= ");
                scanf("%d", &j);
                cont_matriz ++;

			// validação da linha e coluna

                if((i == 0)&& (j==1)){
                    printf("Esse valor ja foi preenchido");
                    matriz[0][1]= 8;
                    goto voltar3;
                }
                if((i == 2)&& (j==2)){
                   printf("Esse valor ja foi preenchido");
                   matriz[2][2]= 1;
                   goto voltar3;
                }
                if((i == 3)&& (j==0)){
                   printf("Esse valor ja foi preenchido");
                   matriz[3][0]= 4;
                   goto voltar3;
                }
                // validação da linha e coluna
                if(( i > 3) || (j > 3)){
                    printf("valor de linha/coluna invalido");
                    goto voltar3;
                }else{
                printf ("\nValor [%d][%d] = ",i,j);
                scanf ("%d", &matriz[ i ][ j ]);
                    if((matriz[ i ][ j ]<1)||(matriz[ i ][ j ]>16)){
                        printf("Valor invalido");
                        goto voltar3;
                    }
                }
                SomarRow(4, matriz);
                SomarCol(4, matriz);
                SomarDia1(4, matriz);
                SomarDia2(4, matriz);
                printfmatriz(4, matriz);
                vitoria(4, matriz);

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

        int matriz[4][4]={{0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0}};
        // Print Matriz vazia
          for(i=0; i<4; i++){
            for(j=0; j<4; j++){
            printf("%5d", matriz[i][j]);
            }
                printf("\n");
        }
        // Inserção de dados da matriz
        for ( i=0; i<4; i++ ){
            for ( j=0; j<4; j++ ){
            voltar4:

            // repetição para linhas e colunas
            while (cont_matriz < 13){
            printf("\nEscolha a linha=");
            scanf("%d", &i);
            printf("Escolha a coluna= ");
            scanf("%d", &j);
            cont_matriz ++;


                // validação da linha e coluna
                if(( i > 3) || (j > 3)){
                    printf("valor de linha/coluna invalido");
                    goto voltar4;
                }else{
                printf ("\nValor [%d][%d] = ",i,j);
                scanf ("%d", &matriz[ i ][ j ]);
                    if((matriz[ i ][ j ]<1)||(matriz[ i ][ j ]>9)){
                        printf("Valor invalido");
                        goto voltar4;
                    }
                }
                SomarRow(4, matriz);
                SomarCol(4, matriz);
                SomarDia1(4, matriz);
                SomarDia2(4, matriz);
                printfmatriz(4, matriz);
                vitoria(4, matriz);

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
    srand(time(NULL));
    setlocale(LC_ALL," ");

    // Introdu��o
    printf("\tSeja bem vindo(a) ao Cubo dos 15 reis.\n");
    printf("\tPermito que diga seu nome, barbaro(a).\n");
    scanf("\t %s",&nome);
    // retorno do nome
    printf("\t%s...um nome realmente estranho.\n",nome);
    printf("\tVai se atrever a tentar resolver o cubo ou irá correr com o rabo entre as pernas??\n");
    // Escolhas
    printf("\t\nEscolha sua opção de jogo: ");
    printf("\t\n1 - Quadrado 3x3 de 1 a 9");
    printf("\t\n2 - Quadrado 4x4 de 1 a 16");
    printf("\t\n3 - Fechar o Jogo\n");
    fflush(stdin); //Limpar os espaços
    scanf("%d", &escolha);

    // Escolha da matriz
    switch (escolha) {
    case 1:
        matriz1(); //função nivel1
        break;
    case 2:
        matriz2(); //função nivel2
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
