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
