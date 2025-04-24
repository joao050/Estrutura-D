// crie uma função que diga se um número é primo(retorna 1) ou não (retorna 0)

#include<stdio.h>
#include<math.h>

int primo(int n);

int main(){

    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    int res = primo(n);

    if (res == 1)
    {
        printf("O numero %d e primo", n);
    } else
    {
        printf("O numero %d nao e primo.", n);
    }
    
    



    return 0;
}

int primo(int n){

    if (n <= 1)
    {
        return 0; // não é primo
    } 
    if (n == 2)
    {
        return 1; // primo
    }
    if (n % 2 == 0) // números pares maiores que 2 não são primos
    {
        return 0;
    } 
    for (int i = 3; i <= sqrt(n) ; i+=2) // laço para verificar os números primos atá sua raiz
    {
        if (n % 1 == 0)
        {
            return 0;
        }
        
    }
    return 1;
    
    
    
    
    
}