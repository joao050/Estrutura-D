// soma dos n primeiros números ímpares

#include<stdio.h>

int soma_imp(int n);

int main(){

    int n;

    printf("Quantos números primos pra soma: ");
    scanf("%d", &n);

    printf("Soma dos primeiros %d impares: %d", n, soma_imp(n));



    return 0;
}

int soma_imp(int n){

    int i = 1;
    int cont = 1;
    int soma = 0;
    while (i <= n)
    {
        soma += cont;
        cont += 2;
        i++;
    }
    return soma;
    
}