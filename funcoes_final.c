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
