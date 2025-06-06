// Implemente uma função que receba como parâmetro um vetor de números reais de tamanho n
// e retorno a quantidade de números negativos armazenados no vetor

#include <stdio.h>
#include <stdlib.h>

// Protótipo da função
int negativos(int n_numeros, float *vet_numeros);

int main()
{
    int tamanho;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    float *vetor = (float *)malloc(tamanho * sizeof(float));
    if (vetor == NULL)
    {
        printf("Erro na alocacao de memoria.");
        return 1;
    }

    printf("Preencha o vetor>>\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }
    printf("Exibir o vetor>>>\n ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Numero %d: %.2f\n", i + 1, vetor[i]);
    }

    printf("O vetor tem %d numero/s negativos.", negativos(tamanho, vetor));

    free(vetor);

    return 0;
}

int negativos(int n_numeros, float *vet_numeros)
{
    int n_negativos = 0;
    for (int i = 0; i < n_numeros; i++)
    {
        if (vet_numeros[i] < 0)
        {
            n_negativos += 1;
        }
    }

    return n_negativos;
}