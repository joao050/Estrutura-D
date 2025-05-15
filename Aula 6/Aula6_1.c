// Fatorial usando a recursividade
// Recursividade é quando uma função chama ela mesma para resolver um problema, no caso, o fatoria.
// fato interessante é que é possivel causar (stack overflow) um estouro de pilha
// caso não for feito a recursividade da maneira correta


#include<stdio.h>

int fat (int n);

int main(){

    int n = 0;
    printf("Digite um numero: ");
    scanf("%d%*c", &n);

    printf("%d! = %d", n, fat(n));

    return 0;
}

// usando a recursividade para calcular o fatorial
// aqui devemos utilizar (n * (n-1)):
// Ex: 4! >> 4 * 3 * 2 * 1 = 24 (true)
// também 4! >> 4 * (4 - 1) * (3 - 1) * (2 - 1) = 24 (true)
// >>                 {3}       {2}       {1}


int fat (int n){
    if (n == 0)
    {
        return 1;
    } else{
        return n * fat(n-1); // chamada recursiva
    }
    
}

// complicado de entender de prima mas da pra pegar a manha
// nesse caso do fatorial ficou mais complexo por causa da fórmula com recursividad, o que poderia ser
// feito com um loop simples :/