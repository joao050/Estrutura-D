// Arquivo de implementação

// Biblioteca contendo a estrutura Matriz
#include "TAD_MATRIX.h"

// Bibliotecas básicas
#include <stdlib.h>
#include <stdio.h>

// Funções

// Cria uma matriz com alocação dinámica e rotorna a matriz criada
Matriz *mat_cria(int linhas, int colunas)
{
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    if (!mat)
    {
        printf("Falha criação da estrutura matriz.");
        exit(1);
    }

    mat->linhas = linhas;
    mat->colunas = colunas;

    mat->valores = (float **)malloc(linhas * sizeof(float *));
    if (mat->valores == NULL)
    {
        printf("Falha na criação das linhas da matriz.");
        exit(1);
    }
    for (int i = 0; i < linhas; i++)
    {
        mat->valores[i] = (float *)malloc(colunas * sizeof(float));
        if (mat->valores[i] == NULL)
        {
            printf("falha na criação das colunas da matriz.");
            for (int j = 0; j < i; j++)
            {
                free(mat->valores[j]);
            }
            free(mat);
            exit(1);
        }

        for (int j = 0; j < colunas; j++)
        {
            mat->valores[i][j] = 0.0;
        }
    }
    return mat;
}

// Libera memoria da matriz criada
void mat_libera(Matriz *mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        free(mat->valores[i]);
    }
    free(mat->valores);

    free(mat);
}

// Função para verificar de determinada posição da matriz é válida
int mat_position_valid(Matriz *mat, int i, int j)
{
    if (i < 0 || i >= mat->linhas)
    {
        printf("A matriz nao tem %d linhas.", i);
        return 0;
    }

    if (j < 0 || j >= mat->colunas)
    {
        printf("A matirz nao tem %d colunas.", j);
        return 0;
    }

    return 1;
}

// Acessa um elemento na linha i da coluna j e retorna o valor
float mat_acessa(Matriz *mat, int i, int j)
{
    if (mat_position_valid(mat, i, j) == 0)
    {
        exit(1);
    }

    return mat->valores[i][j];
}

// atribuir um valor na linha i da coluna j
void mat_atribui(Matriz *mat, int i, int j, float v)
{
    if (mat_position_valid(mat, i, j) == 0)
    {
        exit(1);
    }

    mat->valores[i][j] = v;
    
}

// retorna o número de linhas da matriz
int mat_linhas(Matriz *mat)
{
    return mat->linhas;
}

// retorna o número de colunas da matriz
int mat_colunas(Matriz *mat)
{
    return mat->colunas;
}
