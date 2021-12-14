/* QUADRADO M�GICO
N�VEL 1 - 3X3
Soma = 15
F�cil - 2 valores
Intermedi�rio - 0 valor
*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

void derrota(){

    system("cls");
    printf("\t|************************************************************|\n");
    printf("\t|         Voce foi derrotado, mas nao desista do            |\n");
    printf("\t|                                                            |\n");
    printf("\t|                     QUADRADO MAGICO!                       |\n");
    printf("\t|____________________________________________________________|\n");
    system("pause");
    main();
}

void vitoria(int coluna, int matriz[][coluna]){
    int i, j, limite=0, soma=0, somacol[coluna], somarow[coluna], somadia1=0, somadia2=0;

    //formula que delimita "numero magico"
    limite = (coluna*((coluna*coluna) +1))/2;

    //Verifica��o de valores
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
    }//frase de vitoria
    system("cls");
    printf("\t|************************************************************|\n");
    printf("\t|   Parabens! Voce alcan�ou a VITORIAAA!!                   |\n");
    printf("\t|    no                                                      |\n");
    printf("\t|      QUADRADO MAGICO!                                      |\n");
    printf("\t|____________________________________________________________|\n");
    system("pause");
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

int geramatriz(int coluna, int matriz[][coluna]){
    int aleat=0, vetor[coluna*coluna], n=0, aux=0, cont=1, i=0, j=0, limite=0, soma=0, somacol[coluna], somarow[coluna], somadia1=0, somadia2=0;

    //formula que delimita "numero magico"
    limite = (coluna*((coluna*coluna) +1))/2;

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

    //Verifica��o de valores
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
    return matriz;
}

void printfmatriz(int coluna, int matriz[][coluna]){//fun��o que printa a matriz novamente
    int i, j;

    printf("\n\n");
    for(i=0; i< coluna; i++){
        for(j=0; j < coluna; j++){
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
}

void SomarCol(int coluna, int matriz[][coluna]){ //fun��o que soma os elementos da coluna
    int i, j, soma, somacol[coluna];

    for(j=0 ; j< coluna; j++){
        soma = 0;
        for(i=0; i < coluna; i++){
            soma += matriz[i][j];
        }
        somacol[j] = soma;
    }

    for(j=0; j< coluna; j++){
        printf("\n Coluna [%d] -> %d\n", j, somacol[j]);
        if(coluna == 3){
            if(somacol[j] > 15){
            printf("\n\n<<<< A coluna [%d] ultrapassou o valor maximo de 15. >>>>",j);
            printf("\n<<<< Tente novamente! >>>>");
            }
        }
        if(coluna == 4){
            if(somacol[j] > 34){
            printf("\n\n<<<< A coluna [%d] ultrapassou o valor maximo de 34. >>>>",j);
            printf("\n<<<< Tente novamente! >>>>");
            }
        }
    }
}

void SomarRow(int coluna, int matriz[][coluna]){//fun��o que soma os elementos da linha
    int i, j, soma, somarow[coluna];

    for(i=0 ; i< coluna; i++){
        soma = 0;
        for(j=0; j < coluna; j++){
            soma += matriz[i][j];
        }
        somarow[i] = soma;
    }
    for(i=0; i<coluna; i++){
        printf("\n Linha [%d] -> %d\n", i, somarow[i]);
        if(coluna == 3){
            if(somarow[i] > 15){
            printf("\n\n<<<< A linha %d ultrapassou o valor maximo de 15. >>>>",i);
            printf("\n<<<< Tente novamente! >>>>");
            }
        }
        if(coluna == 4){
            if(somarow[i] > 34){
            printf("\n\n<<<< A linha %d ultrapassou o valor m�ximo de 34. >>>>",i);
            printf("\n<<<< Tente novamente! >>>>");
            }
        }
    }
}

void SomarDia1(int coluna, int matriz[][coluna]){//fun��o que soma os elementos da diagonal principal
    int i, j, soma=0, somadia1=0;

    for(i=0 ; i< coluna; i++){
        for(j=0; j < coluna; j++){
            if(i==j){
                soma += matriz[i][i];
            }
        }
    }
    somadia1 = soma;
    printf("\n Diagonal principal -> %d\n", somadia1);
    if(coluna == 3){
        if(somadia1 > 15){
        printf("\n\n<<<< A diagonal principal ultrapassou o valor maximo de 15. >>>>");
        printf("\n<<<< Tente novamente! >>>>");
        }
    }
    if(coluna == 4){
        if(somadia1 > 34){
            printf("\n\n<<<< A diagonal principal ultrapassou o valor maximo de 34. >>>>");
            printf("\n<<<< Tente novamente! >>>>");
        }
    }
}

void SomarDia2(int coluna, int matriz[][coluna]){//fun��o que soma os elementos da diagonal secundaria
    int i, j, soma=0, somadia2=0;

    for(i=0 ; i < coluna; i++){
        for(j=0; j < coluna; j++){
            if(i + j == coluna - 1){
                soma += matriz[i][j];
            }
        }
    }
    somadia2 = soma;
    printf("\n Diagonal secundaria -> %d\n", somadia2);
    if(coluna == 3){
        if(somadia2 > 15){
        printf("\n\nA diagonal secundaria ultrapassou o valor maximo de 15.");
        printf("\nTente novamente!");
        }
    }
    if(coluna == 4){
        if(somadia2 > 34){
            printf("\n\nA diagonal secundaria ultrapassou o valor maximo de 34.");
            printf("\n Tente novamente!");
        }
    }
}
int matriz1(){
    int i=0, j=0, matriz[3][3], cont=1;
    char nome[30];
    int escolha2;
    int cont_matriz = 0;

    printf("\n\n");
    printf("\t|**************************************************************|\n");
    printf("\t|       Voce prefere ir pelo caminho                           |\n");
    printf("\t|       1-Facil                                                |\n");
    printf("\t|       2-Intermediario                                        |\n ");
    printf("\t|______________________________________________________________->");
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
        system("cls");
        printf("\n");
        printf("\t<<<<<<<<<<<<<<<<<<<<<<<<<< INICIO DE JOGO >>>>>>>>>>>>>>>>>>>>>");
        printfmatriz(3, matriz);
        // Inser��o de dados da matriz
        for ( i=0; i<3; i++ ){
            for ( j=0; j<3; j++ ){
            voltar:
            // repeti��o para linhas e colunas
            while (cont_matriz < 19){
            printf("\nEscolha a linha ->");
            scanf("%d", &i);
            printf("Escolha a coluna ->");
            scanf("%d", &j);
            cont_matriz ++;

                // valida��o da linha e coluna
                if(( i > 2) || (j > 2)){
                    printf("\n");
                    printf("<<<< valor de linha/coluna invalido >>>>");
                    goto voltar;
                }else{
                    printf("\nTentativas restantes -> %d", 19 - cont_matriz);
                    printf ("\nValor [%d][%d] -> ",i,j);
                    scanf ("%d", &matriz[ i ][ j ]);
                    if((matriz[ i ][ j ]<1)||(matriz[ i ][ j ]>9)){
                        printf("\n<<<< Valor invalido >>>>\n");
                        goto voltar;
                    }
                }
                printf("\n SOMAS:\n");
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
                printf("\t\t\t\t");
            for(j=0; j<3; j++){
            printf("%5d", matriz[i][j]);
            }
                printf("\n");
        }

    derrota();
    //return(0); altera��o com fun��o de derrota
    }
    if(escolha2 == 2){

        int matriz[3][3]={{0,0,0},
                          {0,0,0},
                          {0,0,0}};

        printfmatriz(3, matriz);
        // Inser��o de dados da matriz
        for ( i=0; i<3; i++ ){
            for ( j=0; j<3; j++ ){
            voltar2:

            // repeti��o para linhas e colunas
            while (cont_matriz < 19){
            printf("\nEscolha a linha ->");
            scanf("%d", &i);
            printf("Escolha a coluna ->");
            scanf("%d", &j);
            cont_matriz ++;


                // valida��o da linha e coluna
                if(( i > 2) || (j > 2)){
                    printf("<<<< valor de linha/coluna invalido >>>>");
                    goto voltar2;
                }else{
                    printf("\nTentativas restantes -> %d", 19 - cont_matriz);
                    printf ("\nValor [%d][%d] = ",i,j);
                    scanf ("%d", &matriz[ i ][ j ]);
                    if((matriz[ i ][ j ]<1)||(matriz[ i ][ j ]>9)){
                        printf("\n<<<< Valor invalido >>>>\n");
                        goto voltar2;
                    }
                }
                printf("\n SOMAS:\n");
                SomarRow(3, matriz);
                SomarCol(3, matriz);
                SomarDia1(3, matriz);
                SomarDia2(3, matriz);
                printfmatriz(3, matriz);
                vitoria(3, matriz);
                }
            }
        }
    derrota();
    //return(0); altera��o com fun��o de derrota
    }
}

int matriz2(){
    int i, j;
    char nome[30];
    int escolha2;
    int cont_matriz = 0;

     printf("\n\n");
    printf("\t|**************************************************************|\n");
    printf("\t|       Voce prefere ir pelo caminho                           |\n");
    printf("\t|       1-Facil                                                |\n");
    printf("\t|       2-Intermediario                                        |\n ");
    printf("\t|______________________________________________________________->");
    scanf("%d", &escolha2);

    if(escolha2 == 1){
        //Inserir aqui outras op��es de 4x4
        //Tamb�m criar fun��o que randomiza as escolhas
        int matriz[4][4]={{16,2,3,13},
                          {5,11,10,8},
                          {9,7,6,12},
                          {4,14,15,1}};

        apagavalor(4, matriz);
        printfmatriz(4, matriz);
        printf("\n\n");
        // Inser��o de dados da matriz
        for ( i=0; i<4; i++ ){
            for ( j=0; j<4; j++ ){
            voltar3:
            // repeti��o para linhas e colunas
                while (cont_matriz < 11){
                printf("\nEscolha a linha ->");
                scanf("%d", &i);
                printf("Escolha a coluna ->");
                scanf("%d", &j);
                cont_matriz ++;

                // valida��o da linha e coluna
                if(( i > 3) || (j > 3)){
                    printf("<<<< valor de linha/coluna invalido >>>>");
                    goto voltar3;
                }else{
                    printf("\nTentativas restantes -> %d", 11 - cont_matriz);
                    printf ("\nValor [%d][%d] = ",i,j);
                    scanf ("%d", &matriz[ i ][ j ]);
                    if((matriz[ i ][ j ]<1)||(matriz[ i ][ j ]>16)){
                        printf("\n<<<< Valor invalido >>>>\n");
                        goto voltar3;
                    }
                }
                printf("\n SOMAS:\n");
                SomarRow(4, matriz);
                SomarCol(4, matriz);
                SomarDia1(4, matriz);
                SomarDia2(4, matriz);
                printfmatriz(4, matriz);
                vitoria(4, matriz);

            }
            }
        }

    derrota();
    //return(0);
    }
    if(escolha2 == 2){

        int matriz[4][4]={{0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0}};

        printfmatriz(4, matriz);
        // Inser��o de dados da matriz
        for ( i=0; i<4; i++ ){
            for ( j=0; j<4; j++ ){
            voltar4:

            // repeti��o para linhas e colunas
            while (cont_matriz < 35){
            printf("\nEscolha a linha ->");
            scanf("%d", &i);
            printf("Escolha a coluna ->");
            scanf("%d", &j);
            cont_matriz ++;


                // valida��o da linha e coluna
                if(( i > 3) || (j > 3)){
                    printf("<<<< valor de linha/coluna invalido >>>>");
                    goto voltar4;
                }else{
                    printf("\nTentativas restantes -> %d", 35 - cont_matriz);
                    printf ("\nValor [%d][%d] -> ",i,j);
                    scanf ("%d", &matriz[ i ][ j ]);
                    if((matriz[ i ][ j ]<1)||(matriz[ i ][ j ]>16)){
                        printf("\n<<<< Valor invalido >>>>\n");
                        goto voltar4;
                    }
                }
                printf("\n SOMAS:\n");
                SomarRow(4, matriz);
                SomarCol(4, matriz);
                SomarDia1(4, matriz);
                SomarDia2(4, matriz);
                printfmatriz(4, matriz);
                vitoria(4, matriz);

                }
            }
        }
    derrota();
    //return(0); altera��o com fun��o de derrota
    }
}

int main(){
    int escolha, nivel1(), nivel2();
    char nome[50];
    srand(time(NULL));
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL," ");

    printf("\n\n\n");
   SetConsoleTextAttribute(h,10);
    printf("\t|*************************************************************|");
    printf("\n        |       Seja bem vindo(a) ao QUADRADO MAGICO|*                |\n");
    printf("\t|       Antes de jogar diga, qual o seu nome?*                |\n");
    printf("\t|_____________________________________________________________->");
    scanf("%[^\n]",&nome);//le o string at� o Enter
    // retorno do nome
    printf("\n\n\n");
    printf("\t|***********************************************************************|\n");
    printf("\t|       [...]um nome realmente estranho. %s                   =D",nome);
    printf("\t\n        |       Voce tem coragem para enfrentar o desafio ou vai fugir?         |\n");
    printf("\t|_______________________________________________________________________|");
    SetConsoleTextAttribute(h,10);
    reinicio:
    // Escolhas
    printf("\n\n");
    printf("\t|**************************************************************|\n");
    printf("\t|       Escolha o seu caminho:                                 |\n");
    printf("\t|       1 - Quadrado 3x3 de 1 a 9                              |\n");
    printf("\t|       2 - Quadrado 4x4 de 1 a 16                             |\n");
    printf("\t|       3 - Fechar o Jogo                                      |\n");
    printf("\t|_____________________________________________________________->");
    fflush(stdin); //Limpar os espa�os
    scanf("%d", &escolha);

    // Escolha da matriz
    switch (escolha) {
    case 1:
        matriz1(); //fun��o nivel1
        break;
    case 2:
        matriz2(); //fun��o nivel2
        break;
    case 3:
        printf("\n");
        printf("\t        Voce perdeu um grande tesouro haha!   :p\n");
        printf("\t        -----------------------------------     ");
        return 0;
        break;
    default:
        system("cls");
        printf("\n\n");
        printf("\t        Escolha um modo de jogo valido :(       \n");
        printf("\t        -----------------------------------     ");
        main();
        break;
    }
}
