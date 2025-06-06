// Implemente uma função que receba como parâmetro um vetor de números inteiros
// e inverta a ordem dos elementos armazenados no vetor

#include <stdio.h>
#include <stdlib.h>

// Protótipo da função
void inverte(int tamanho_vet, int *vet_numeros);

void exibir_vetor(int tamnho_vet, int *vet_numeros);

int main()
{
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro na alocacao de memoria.");
        return 1;
    }

    printf("Preencha o vetor>>>\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Exibindo o vetor antes>>>");
    exibir_vetor(tamanho, vetor);

    inverte(tamanho, vetor);

    printf("\nExibindo o vetor depois>>>>\n");
    exibir_vetor(tamanho, vetor);

    return 0;
}

void inverte(int tamanho_vet, int *vet_numeros)
{
    for (int i = 0; i < tamanho_vet / 2; i++)
    {
        int temp = vet_numeros[tamanho_vet - 1 - i];
        vet_numeros[tamanho_vet - 1 - i] = vet_numeros[i];
        vet_numeros[i] = temp;
    }
}
void exibir_vetor(int tamnho_vet, int *vet_numeros)
{
    for (int i = 0; i < tamnho_vet; i++)
    {
        printf("Numero %d: %d\n", i + 1, vet_numeros[i]);
    }
}