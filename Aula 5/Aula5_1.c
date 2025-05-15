// Calculando o fatorial de um numero passando argumentos pela função main
// Nescessário utilizar a biblioteca stdlib.h
// executando pelo terminal >> .\Aula5_1.exe <<

#include <stdio.h>
#include <stdlib.h>

int fat(int *n); // função para caucular o fatorial

int main(int argc, char *argv[])
{

    switch (argc)
    {
    case 1:
        printf("Não foi inserido argumetos para a operacao.");
        break;
    case 2:
        printf("Argumento passado: %s\n", argv[1]);

        // supondo que sempre será passado numeros como strings, então...
        int num = atoi(argv[1]); // função 'atoi' da 'stdlib.h' converte string para int (também é possivel para float 'atof')
        // caso for uma letra, a conversão tera resultado 0

        printf("Convertido para inteiro: %d\n", num);
        int fatorial = fat(&num);
        printf("Fatorial de %d = %d\n", num, fatorial);

        break;
    default:
        printf("Foram digitados muitos argumentos!!\n");
        break;
    }

    return 0;
}

int fat(int *n)
{
    printf("Numero passado pra funcao: %d\n", *n);
    int fat = 1;
    int i;
    for (i = 2; i <= *n; i++)
    {
        fat *= i;
    }
    if (fat == 1)
    {
        printf("ALERT!!\n");
        printf("Argumento passado foi '0' ou do tipo inesperado.\n");
    }
    return fat;
}
