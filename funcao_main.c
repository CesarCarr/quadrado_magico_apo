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
