// utilizando o do while e switch

#include<stdio.h>
int main(){

    char op;

    do
    {
        printf("Deseja continuar(s/n):");
        scanf("%c%*c", &op);

        switch (op)
        {
        case 'S':
        case 's':
            printf("O usuario decidiu continuar...\n");
            break;
        case 'N':
        case 'n':
            printf("O usuario decidiu parar.\n");
            printf("Finalizando...");
            break;
        default:
            printf("Codigo invalido, digite novamente.\n");
            break;
        }
    } while (op != 'N' && op != 'n');
    

    return 0;
}
