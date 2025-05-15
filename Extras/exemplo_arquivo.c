/*

Faça funções:
- uma para alocar uma matriz dinamicamente na memória, retornando o endereço da matriz criada
- Uma função que receba duas matrizes e retorne uma terceira que será a soma das duas matrizes passadas pra função
- uma função que libere a matriz

*/

#include <stdio.h>
#include <stdlib.h>

void **cria_matriz(int linhas, int colunas)
{
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz == NULL)
        {
            for (int j = 0; j < i; i++)
            {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

void **soma(int **matr1, int l1, int c1, int **matr2, int l2, int c2)
{
    int **soma = cria_matriz(l1, c1);
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            soma[i][j] = matr1[i][j] + matr2[i][j];
        }
    }
    return soma;
}

void libera(int **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz);
    }
    free(matriz);
}