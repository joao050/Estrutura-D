// **** ALOCAÇÃO DINÂMICA DE MEMÓRIA PARA MATRIZES ****

/*

Uma matriz dinâmica é como um *vetor de vetores*, ou seja:
Primeiro, alocar um vetor de ponteiros (linhas)
Depois, para cada linha, alocar um vetor de inteiros (colunas)

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lin, col;
    printf("Digite o numero de linhas e colunas respctivamente: ");
    scanf("%d %d", &lin, &col);

    int **matriz = (int **)malloc(lin * sizeof(int *)); // aloca memória das linhas(primeiro vetor)
    if (matriz == NULL)
    {
        printf("Alocacao falhou\n");
        return 1;
    }

    for (int i = 0; i < lin; i++)
    {
        matriz[i] = (int *)malloc(col * sizeof(int)); // aloca memória para as colunas das linhas

        // caso a alocação falhe é recomendado liberar toda a memória anterior( pq? eu não sei explicar, mas é recomendação do chatGPT)
        if (matriz[i] == NULL)
        {
            printf("Alocacoa falhou.");
            for (int j = 0; j <= i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
        }
    }
    // grandinho pq tem as condições de falha, sempre bom fazer uma função (modularizar) pra não repetir todo esse código sempre...

    // Preenchimento e exibir é o de sempre ( matriz[i][j] )...

    printf("Guarde valores na matriz:");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Exibri valores:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}