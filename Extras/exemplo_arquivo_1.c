/*

Crie um program que deve permitir o usuário inserir números em um vetor dinâmico, exibir o vetor,
mostrar o maior número e a soma de todos os números do vetor.(Todas as posições do vetor devem ser
inicializadas com null)

*/

#include <stdio.h>
#include <stdlib.h>

void *aloca_vetor(int n);
void inserir_valor(int *vetor, int indice, int valor);
void exibir_vetor(int *vetor, int tam);
int maior_n(int *vetor, int tam);
int somar(int *vetor, int tam);
int main()
{
    int tamanho, soma, maior;
    printf("Qual o tamnaho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = aloca_vetor(tamanho);

    exibir_vetor(vetor, tamanho);

    return 0;
}

void *aloca_vetor(int n)
{
    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        vetor[i] = 0;
    }

    return vetor;
}
void inserir_valor(int *vetor, int indice, int valor)
{
    if (vetor[indice] != 0)
    {
        vetor[indice] = valor;
    }
    else
    {
        printf("Posicao ja ocupada.\n");
    }
}

void exibir_vetor(int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Posicao %d: %d\n", i + 1, vetor[i]);
    }
}
int maior_n(int *vetor, int tam)
{
    int maior = vetor[0];
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }
    return maior;
}
int somar(int *vetor, int tam)
{
    int soma = 0;
    for (int i = 0; i < tam; i++)
    {
        soma += vetor[i];
    }
    return soma;
}