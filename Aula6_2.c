// Macros: meio que instruções que são definidas antes da compilação, basicamente ele "substitui" o texto 
// pelo seu valor, o exemplo mais comum é >> #define PI 3.14... << onde cada 'PI' encontrado
// no código é substituido por 3.14.

// !!  Sempre use parênteses extras nas macros com parâmetros para evitar erros de precedência !!
// !! Não são funções de verdade, apenas substitui o texto...


#include<stdio.h>

#define PI 3.14 // ...
#define f(x) x*x + x + 2 // nesse caso meio que criou uma função onde x é o argumento
#define quadrado(x) ((x) * (x)) // parecido, esse caucula o quadrado de um número
#define maior(a, b) ((a) > (b) ? (a) : (b)) // também com condições

int main(){

    int n, a, b;
    n = a = b = 0; // uma inicialização pras variáveis...

    printf("Valor aproximado de pi: %.2f\n", PI); // ...

    printf("Digite um valor para x: ");
    scanf("%d%*c", &n);

    printf("f(%d) = %d\n", n, f(n)); // quando o programa encontra f(n) = n*n + n + 2

    printf("Quadrado de %d: %d\n", n, quadrado(n)); // ...

    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);

    printf("Maior: %d\n", maior(a, b)); // condição



    return 0;
}