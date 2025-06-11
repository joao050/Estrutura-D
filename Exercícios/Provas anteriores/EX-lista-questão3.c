/*
Codifique as funções conforme os protótipos. A primeira aloca uma matriz dinamicamente na
memória de tamanho “linhas” x “colunas”, retornando o endereço da matriz criada. A segunda receba duas
matrizes (A e B), uma contendo “n” linhas x “m” colunas e outra contendo “o” linhas x “p” colunas e retorne a
matriz soma em uma terceira matriz. A última, libera uma matriz passada por parâmetro contendo um certo
número de linhas.
*/

// Acho que eu já tinha feito essa... esse código fede a preguiça

#include <stdio.h>
#include <stdlib.h>

int **mt_cria(int linhas, int colunas);
int **mts_soma(int **mat1, int **mat2, int linhas, int colunas);
void libera(int **mat, int linhas);

int main()
{
    int **mat1 = mt_cria(2, 3);
    int **mat2 = mt_cria(2, 3);
    int **soma = mts_soma(mat1, mat2, 2, 3);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", soma[i][j]);
        }
        printf("\n");
    }

    libera(mat1, 2);
    libera(mat2, 2);
    libera(soma, 2);

    return 0;
}

int **mt_cria(int linhas, int colunas)
{
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Alocacao falhou.");
        return NULL;
    }
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        // acho que essa parte ta errada, sla. Vai ficar assim *-_-
        if (matriz[i] == NULL)
        {
            printf("alocação falhou.");
            for (int j = 0; j < 1; j++)
            {
                free(matriz[i]);
            }
            return NULL;
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = i + j + 1;
        }
        
    }
    
    return matriz;
}

int **mts_soma(int **mat1, int **mat2, int linhas, int colunas)
{
    int **res_soma = mt_cria(linhas, colunas);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            res_soma[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return res_soma;
}
void libera(int **mat, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
