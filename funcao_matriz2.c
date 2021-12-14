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
