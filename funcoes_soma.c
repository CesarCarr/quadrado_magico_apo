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
