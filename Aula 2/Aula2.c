#include<stdio.h>
// variaveis globais, 
int var1 = 10; // 4 bytes
short int var2 = 10; // 2 bytes
long int var3 = 10; // 4 bytes 
double var4 = 10; // 8 bytes

// Funçao pra exibir o valor da variavel na pilha de execução
void exibir(void);

int main(){
    printf("Variavel global 1: %d\n", var1);
    printf("Quantidade de bytes: %d\n", sizeof(var1));
    printf("Quantidade de bytes(var2): %d\n", sizeof(var2));
    printf("Quantidade de bytes(var3): %d\n", sizeof(var3));
    printf("Quantidade de bytes(var4): %d\n", sizeof(var4));
    printf("Emdereços em hexadecimal: var1: %x; var2: %x; var3: %x e var4: %x\n", &var1, &var2, &var3, &var4);

    printf("\n\n");

    // tentando chamar a variavel que foi criada na função
    // printf("Variavel A: %d", var_A); 
    // consequentimente o código da erro pois a variavel esta apenas no scopo da função.

    // Chamar a função pra exibir o valor da variavel A
    exibir();
    return 0;
}

void exibir(){
    int var_A = 100;
    printf("Valor da variavel A: %d\n", var_A); 
    printf("Seu endereco: %x\n", &var_A);

}