/*
**Vetor de ponteiros
Desenvolva um programa que gerencie um conjunto de números inteiros, o programa deve permitir o usuário
inserir os números em um vetor, em seguida exibir o vetor, exibir o maior números e a soma de todos
os números do vetor.

*/

#include <stdio.h>
#include <stdlib.h>

// Aloca memória para um vetor de ponteiros do tipo int e retorna o vetor criado
int **alocar_vetor(int tamanho);
void preencher_vetor(int **vetor, int tamanho);
void exibir(int **vetor, int tamanho);
int maior(int **vetor, int tamanho);
int soma(int **vetor, int tamanho);
void vet_libera(int **vetor, int tamanho);

int main()
{
    int n;

    printf("Digite o tamanho pro vetor: ");
    scanf("%d", &n);

    // Vetor de ponteiros
    int **vet_numeros = alocar_vetor(n);

    preencher_vetor(vet_numeros, n);
    exibir(vet_numeros, n);

    printf("O maior numero do vetor: %d\n", maior(vet_numeros, n));
    printf("Resultado da soma dos numeros do vetor: %d\n", soma(vet_numeros, n));

    vet_libera(vet_numeros, n);

    return 0;
}

int **alocar_vetor(int tamanho)
{
    // alocando memória para um vetor, cada posição é um ponteiro
    int **vetor = (int **)malloc(tamanho * sizeof(int *));
    if (vetor == NULL)
    {
        printf("Falha na alocação.");
        exit(1);
    }

    // inicializando todas as posições com NULL
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = NULL;
    }

    return vetor;
}
void preencher_vetor(int **vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = (int *)malloc(sizeof(int)); // Aloca espaço para cada número
        if (vetor[i] == NULL)
        {
            printf("Falha na alocacao de memoria.\n");
            exit(1);
        }
        printf("Digite o numero para a posicao %d: ", i);
        scanf("%d", vetor[i]); // Preenche o vetor na posição que foi alocada memória
    }
}

/*
Observação importante: Acessamos o valor nas posições do vetor com '*vetor[i]'
 -- Se você usar só vetor[i], você está acessando o endereço de memória, já que é um ponteiro.
 -- Se você usa *vetor[i], você acessa o conteúdo armazenado nesse endereço (o valor real).
O segundo caso é o que queremos.
*/

void exibir(int **vetor, int tamanho)
{
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", *vetor[i]);
    }
    printf("\n");
}
int maior(int **vetor, int tamanho)
{
    int maior = *vetor[0];
    for (int i = 0; i < tamanho; i++)
    {
        if (*vetor[i] > maior)
        {
            maior = *vetor[i];
        }
    }

    return maior;
}
int soma(int **vetor, int tamanho)
{
    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += *vetor[i];
    }

    return soma;
}

void vet_libera(int **vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        free(vetor[i]); // libera cada posição do vetor
    }
    free(vetor); // libera o vetor por completo
}
