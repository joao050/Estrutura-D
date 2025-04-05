// Arranjo simples(n!/(n-p)!), passando argumentos pela função main
// executando pelo terminal >> .\Aula5_2.exe <<

// Sem comentarios....

#include<stdio.h>
#include<stdlib.h>

int fatorial (int n);

int main(int argc, char *argv[])
{

    switch (argc)
    {
    case 1:
        printf("Não foi digitado argumentos.\n");
        break;
    case 2 :
        printf("Argumentos insuficicentes.\n");
        break;
    case 3:
        printf("Argumentos passados: %s, %s\n", argv[1], argv[2]);
        int n = atoi(argv[1]);
        int p = atoi(argv[2]);
        float arranjo = fatorial(n)/fatorial(n-p);
        printf("Resultado do arranjo: %.2f\n", arranjo);
        break;
    default:
        printf("Muitos argumentos!!");
        break;
    }

    return 0;
}

int fatorial (int n){

    int fat = 1;
    for (int i = 2; i <= n; i++)
    {
        fat *= i;
    }

    return fat;
}