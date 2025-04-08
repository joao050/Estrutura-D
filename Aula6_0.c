// Varáveis gloais: são variáveis criadas fora de qualquer função e podem ser
// acessadas por todo o programa.

// Variáveis státicas 'static': Criada em uma função sua visibilidade é apenas na função.
// ela mantém seu valor entre chamada de funções, diferente de uma variavel comum
// e seu tempo de vida é até o fim do programa.
// Também pode ser criada fora de qualquer função, porém sua visibilidade é apenas no arquivo atual.


#include<stdio.h> //...
#include<stdlib.h> // função para usar a função 'rand()' [gera números inteiros aleatorios]
#include<time.h> // em particular eu usei para criar uma "semente" pra função rand() gerar números aleatórios de acordo com o tempo

void print(int n);

int main(){
    srand(time(NULL)); // criação da semente. (acho que isso ele não vá cobrar)

    for (int i = 0; i < 10; i++) // laço para exibir 10 numeros aleatorios
    {
        print(rand()); // função rand()...
    }
    
    // tentando chamar a variável 'staic int cont' 
    // printf("Cont: %d", cont);
    // não é possivel pois sua visibilidade é apenas dentro da função 'print'

    return 0;
}

void print(int n){
    static int cont = 0; // variável static criada dentro da função
    printf("%d - %d // ",cont, n );
    cont++;
    if (cont % 5 == 0) // a cada 5 números ele dá uma quebra de linha
    {
        printf("\n");
    }
}