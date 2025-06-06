// Implemente uma função que receba como parâmetro um vetor de números inteiros
// e retorno a quantidade de números pares

#include <stdio.h>
#include <stdlib.h>

// Portótipo da função
int numeros_pares(int tamanho_vet, int *vet_numeros);
int main()
{
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro na alocacao de memoria.\n");
        return 0;
    }

    printf("Preencha o vetor>>>\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("Exibir o vetor>>>\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Numero %d: %d\n", i + 1, vetor[i]);
    }

    printf("O vetor possui %d numero/s par.", numeros_pares(tamanho, vetor));

    return 0;
}

int numeros_pares(int tamanho_vet, int *vet_numeros)
{
    int n_pares = 0;
    for (int i = 0; i < tamanho_vet; i++)
    {
        if (vet_numeros[i] % 2 == 0)
        {
            n_pares += 1;
        }
    }

    return n_pares;
}