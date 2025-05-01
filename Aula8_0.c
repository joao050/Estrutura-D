//ESSA VEIO POTENTE...

#include <stdio.h>
#include <stdlib.h>

#define N_LINHAS 2
#define N_COLUNAS 2

float **cria_matriz(int n_linhas, int n_colunas);
void libera_matriz(float **matriz, int n_linhas);
void preenche_matriz(float **matriz, int n_linhas, int n_colunas);
void imprime_matriz(float **matriz, int n_linhas, int n_colunas);
float **transpor_matriz(float **matriz, int n_linhas, int n_colunas);
float **soma_matriz(float **matriz_a, int linhas_a, int colunas_a, float **matriz_b, int linhas_b, int colunas_b);
float **sub_matriz(float **matriz_a, int linhas_a, int colunas_a, float **matriz_b, int linhas_b, int colunas_b);
float **mult_matriz(float **matriz_a, int linhas_a, int colunas_a, float **matriz_b, int linhas_b, int colunas_b);

int main()
{
    // Criando matriz utilizando a função 'cria matriz()'
    float **matriz = cria_matriz(N_LINHAS, N_COLUNAS);
    if (matriz == NULL)
    {
        printf("Erro na alocacao de memoria;");
        return 1;
    }

    // preenche a matriz
    preenche_matriz(matriz, N_LINHAS, N_COLUNAS);

    // imprime matriz
    printf("Imprimindo a matriz\n");
    imprime_matriz(matriz, N_LINHAS, N_COLUNAS);

    // Transpor matriz
    float **transp_matriz = transpor_matriz(matriz, N_LINHAS, N_COLUNAS);
    if (transp_matriz == NULL)
    {
        printf("Matriz trasposta falhou.");
        return 1;
    }

    // imprime matriz transposta
    printf("Imprimindo matriz transposta:\n");
    imprime_matriz(transp_matriz, N_LINHAS, N_COLUNAS);

    // Matriz de soma
    float **soma = soma_matriz(matriz, N_LINHAS, N_COLUNAS, transp_matriz, N_LINHAS, N_COLUNAS);
    if (soma == NULL)
    {
        printf("Soma falhou.");
        return 1;
    }

    // imprime matriz soma
    printf("Matriz soma:\n");
    imprime_matriz(soma, N_LINHAS, N_COLUNAS);

    // Matriz de subtração
    float **sub = sub_matriz(matriz, N_LINHAS, N_COLUNAS, transp_matriz, N_LINHAS, N_COLUNAS);
    if (sub == NULL)
    {
        printf("Subtraçõa falhou.");
        return 1;
    }

    // imprime matriz sub
    printf("Matriz subtração:\n");
    imprime_matriz(sub, N_LINHAS, N_COLUNAS);

    // Matriz de multiplicação
    float **mult = mult_matriz(matriz, N_LINHAS, N_COLUNAS, transp_matriz, N_LINHAS, N_COLUNAS);
    if (sub == NULL)
    {
        printf("Multiplicação falhou.");
        return 1;
    }

    // imprime matriz mult
    printf("Matriz multiplicacao:\n");
    imprime_matriz(mult, N_LINHAS, N_COLUNAS);

    // Libera a memória
    libera_matriz(matriz, N_LINHAS);
    libera_matriz(transp_matriz, N_LINHAS);
    libera_matriz(soma, N_LINHAS);
    libera_matriz(sub, N_LINHAS);
    libera_matriz(mult, N_LINHAS);

    return 0;
}
// modularizar a criação e alocação de memória pra uma matriz
float **cria_matriz(int n_linhas, int n_colunas)
{

    // seguinte... pra criar esse tipo matriz da pra seguir sempre esse modelo
     
    float **mat = (float **)malloc(n_linhas * sizeof(float *)); //aloca um vetor de ponteiros para n_linhas
    if (mat == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n_linhas; i++)
    {
        mat[i] = (float *)malloc(n_colunas * sizeof(float)); // aloca as colunas para cada linha

        if (mat[i] == NULL)
        {
            // Caso falhe é recomendado liberar a memória anterior pra não ter vazamento de memória... recomendação ChatGPT
            for (int j = 0; j < n_linhas; j++)
            {
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
    }

    // pontos a destacar:
    // criação de uma variavel com ponteiro de ponterio (float **mat)
    // casting do tipo de dado antes do malloc (float **)
    // sizeof(float *) na alocação das linhas
    // alocar memória pra cada linha utilizando um for com (mat[i] = (float *)malloc(n_colunas * sizeof(float)))
    // liberação da memória caso falhe

    return mat;
}
// modularizar a liberação de memória
void libera_matriz(float **matriz, int n_linhas)
{
    for (int i = 0; i < n_linhas; i++)
    {
        free(matriz[i]); // primeiro libera as colunas das linhas
    }
    free(matriz); // depois as linhas
}
// modularizar o preenchimento da matriz
void preenche_matriz(float **matriz, int n_linhas, int n_colunas)
{

    // para preencher a matriz é simples, já sabemos...
    printf("Guardando valores na matriz:\n");

    for (int i = 0; i < n_linhas; i++)
    {
        for (int j = 0; j < n_colunas; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
    }
}
// imprime...
void imprime_matriz(float **matriz, int n_linhas, int n_colunas)
{

    // pra imprimir também é simples
    for (int i = 0; i < n_linhas; i++)
    {
        for (int j = 0; j < n_colunas; j++)
        {
            printf("%5.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}
// Transpor matriz OBS:eu não fazia ideia do que era isso...
float **transpor_matriz(float **matriz, int n_linhas, int n_colunas)
{
    float **mat = cria_matriz(n_colunas, n_linhas); // **recursividade manos, utilizando uma função dentro de outra função
    if (mat == NULL)
    {
        printf("Alocação pra matriz trasposta falhou.");
        return NULL;
    }

    // transpondo a matriz
    for (int i = 0; i < n_linhas; i++)
    {
        for (int j = 0; j < n_colunas; j++)
        {
            mat[j][i] = matriz[i][j];
        }
    }

    return mat;
}
// soma a matriz normal com a matriz transposta
float **soma_matriz(float **matriz_a, int linhas_a, int colunas_a, float **matriz_b, int linhas_b, int colunas_b)
{
    // Nesse caso como eu vou utilizar a matriz normal e matriz transposta tendo o mesmo número de linhas e colunas
    // posso passar as mesmas quantides pra função cria_matriz.
    // Acredito que se fosse matrizes de tamanho diferente precisaria de algumas condições...
    float **soma_matr = cria_matriz(linhas_a, colunas_a);
    if (soma_matr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < linhas_b; i++)
    {
        for (int j = 0; j < colunas_b; j++)
        {
            soma_matr[i][j] = matriz_a[i][j] + matriz_b[i][j];
        }
    }

    return soma_matr;
}
// subtração
float **sub_matriz(float **matriz_a, int linhas_a, int colunas_a, float **matriz_b, int linhas_b, int colunas_b)
{
    // Mesmo caso pra subtração
    float **sub_matr = cria_matriz(linhas_a, colunas_a);
    if (sub_matr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < linhas_b; i++)
    {
        for (int j = 0; j < colunas_b; j++)
        {
            sub_matr[i][j] = matriz_a[i][j] - matriz_b[i][j];
        }
    }

    return sub_matr;
}
//multiplicação
float **mult_matriz(float **matriz_a, int linhas_a, int colunas_a, float **matriz_b, int linhas_b, int colunas_b)
{
    // Mesmo caso pra multiplicação
    float **m_matr = cria_matriz(linhas_a, colunas_a);
    if (m_matr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < linhas_b; i++)
    {
        for (int j = 0; j < colunas_b; j++)
        {
            m_matr[i][j] = matriz_a[i][j] * matriz_b[i][j];
        }
    }

    return m_matr;
}
