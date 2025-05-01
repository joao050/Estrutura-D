// ***** PONTEIROS ****

/*

Definição técnica:
Um ponteiro é uma variável que armazena o endereço de memória de outra variável.
Em vez de guardar diretamente um valor (como um int que armazena 10), o ponteiro 
guarda a posição onde esse valor está na memória.


Analogia: ponteiro como um GPS
Imagine que você tem uma casa (variável) e o endereço da casa (ponteiro). Você pode
guardar e compartilhar esse endereço com alguém, e essa pessoa poderá visitar a casa
ou até mesmo modificar o que tem dentro da casa.

Variável comum = a casa em si (contém os dados)
int casa = 'conteúdo'

Ponteiro = um papel com o endereço da casa (não é o valor, é o local onde o valor está)
int* end_casa = &casa (end_casa recebe o endereço da  variável casa) 


*/

// EXEMPLOS >>

#include<stdio.h>

// função simples para alterar o conteúdo de uma variável
// Nesse caso é utilizado o chamado 'passagem por referência'
void dobrar(int* n);

int main(){

    int x = 10; // variável comum
    int* ponteiro = &x; // ponteiro recebe o endereço de x

    // & = operador de endereço. Retorna o endereço de memória de uma variável.
    // * = operador de indireção ou desreferência. Acessa o valor armazenado no endereço que o ponteiro aponta.

    printf("Acessando o x: %d\n", x);
    printf("O endereco da variavel x: %p\n", &x); // endereço na memória
    printf("Endereço que o ponteiro recebe: %p\n", ponteiro); // mesmo endereço de x
    printf("O valor que é apontado pelo ponteiro: %d\n", *ponteiro); //  acessando o valor que está nesse endereço (10)

    dobrar(&x); // passando o endereço de x (&x) pra função

    printf("Valor de x alterado: %d\n", x);

    return 0;
}

void dobrar(int* n) // unico parametro que recebe o endereço de uma variavel ( nesse caso o endereço de x )
{
    *n = *n * 2; // é possível alterar o conteúdo dessa variavel utilizando os ponteiros
}