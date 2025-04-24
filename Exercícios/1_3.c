// crie uma função que retorne o n-ésimo termo da sequencia de fibonacci.

#include<stdio.h>

int fib(int n);

int main(){

    int n_termo;
    printf("Digite a posição do termo: ");
    scanf("%d", &n_termo);

    printf("Termo da posicao %d >> %d", n_termo, fib(n_termo));


    return 0;
}

int fib(int n){

    int p1 = 0;
    int p2 = 1;
    int fib;

    if (n == 1 )
    {
        return p1;
    } else if ( n == 2)
    {
        return p2;
    } else
    {
        printf("%d %d ", p1, p2);
        for (int i = 3; i <= n; i++)
        {
            fib = p1 + p2;
            p1 = p2;
            p2 = fib;
            printf("%d ", fib);
        }

        return fib;
        
    }
    
}