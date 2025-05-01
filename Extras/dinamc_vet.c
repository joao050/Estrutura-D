// **** ALOCAÇÃO DINÂMICA DE MEMÓRIA PARA VETORES ****

/*

Quando declaramos o tamnho de um vetor/matriz com tamnho fixo (int vet[10])
a memória é reservada *estaticamente* durante a compilação. Isso é limitado, pois:

Você precisa saber o tamanho antes de rodar o programa.

Pode desperdiçar memória (se alocar mais do que precisa).

Já a *alocação dinâmica* permite criar vetores/matrizes em tempo de execução, com tamanhos
definidos pelo usuário ou por alguma lógica do programa.

*/

#include <stdio.h>
#include <stdlib.h> // lib nescessária pra usar malloc

int main()
{

    int n;
    printf("Digite o tamnho do vetor: ");
    scanf("%d", &n);

    // aloca dinamicamente memória para n inteiros
    int *vetor = (int *)malloc(n * sizeof(int));
    // n * sizeof(int) >> quantidade de bytes necessária.
    // malloc(...) >> aloca e retorna um ponteiro void *.
    // (int *) >> fazemos um cast para dizer que o ponteiro aponta para inteiros.
    // vetor[i] >> funciona normalmente como array.

    // caso a alocação falhe malloc retorna 'NULL'
    if (vetor == NULL)
    {
        printf("Alocação falhou, falta de memorira.");
        return 1; 
    }
    

    printf("Preencha o vetor: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    printf("Imprime:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    // Lembrando sempre de liberar a memória depois de usada
    free(vetor);

    return 0;
}
