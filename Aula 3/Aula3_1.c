// Operador condicional
#include<stdio.h>
int main(){
    int a, b, maior;

    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);

    maior = a > b ? a : b; // Operador condicional, tipo um if/else contraido

    printf("Maior valor: %d", maior);
    return 0;
}