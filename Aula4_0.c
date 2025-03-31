// Fatorial usando repetição com for e while

#include<stdio.h>
int main(){

    int n;
    int fatorial = 1;
    printf("Digite um numero: ");
    scanf("%d", &n);

    // for
    for (int i = 1; i <= n; i++)
    {
        fatorial *= i;
    }
    printf("For>> O fatorial de %d e: %d\n", n, fatorial);

    fatorial = 1; 

    //while
    int ii = 1;
    while (ii <= n)
    {
        fatorial *= ii;
        ii++;
    }
    printf("While>> O fatorial de %d e: %d\n", n, fatorial);
    

    return 0;
}