// Crie um programa que tenha uma função que armazene a nota de 'n' alunos, cada aluno tem 'm' notas (matriz[n][m]),
// calcule a média de cada aluno. (a média de cada aluno deve ser armazenada em um vetor
// para ver depois: vetor[n])

#include <stdio.h>
#include <stdlib.h>

float **aloca_matriz(int n, int m);                          // função pra alocar memória pra uma matriz
void pree_matriz(float **matriz, int n, int m);              // preencher a matriz (passagem por referência)
void calc_media(float **matriz, float *vetor, int n, int m); // calcula media e armazena no vetor de medias (passagem por referência)

int main()
{

    int n_alunos, m_notas;
    printf("A classe tem quantos alunos:");
    scanf("%d", &n_alunos);
    printf("Cada aluno tem quantas notas:");
    scanf("%d", &m_notas);
    // att: avaliação de entrada seria uma boa prática

    // criação da matriz com memória alocada dinamicamente
    float **notas_alunos = aloca_matriz(n_alunos, m_notas);
    // a matriz de ponteiros criada aqui vai receber a matriz criada na função que (return matriz;)
    // caso a função *aloca_matriz()* retorne NULL
    if (notas_alunos == NULL)
    {
        printf("Alocação de memória falhou.");
        return 1;
    }

    printf("Registre as notas:\n");
    pree_matriz(notas_alunos, n_alunos, m_notas); // ...

    // alocando memória dinamicamente pra um vetor, simples...
    float *media_alunos = (float *)malloc(n_alunos * sizeof(float));
    // att:
    // pra não ocorrer vazamento de memória
    // se a alocação do vetor de médias falhou tem que liberar a matriz notas_alunos antes de retornar 1;
    if (media_alunos == NULL)
    {
        printf("Alocação de memória para vetor de médias falhou.\n");
        for (int i = 0; i < n_alunos; i++)
        {
            free(notas_alunos[i]);
        }
        free(notas_alunos);
        return 1;
    }

    // calculando a media e armazena no vetor *media_alunos*
    calc_media(notas_alunos, media_alunos, n_alunos, m_notas);

    // Exibição das médias
    printf("Boletin de medias:\n");
    for (int i = 0; i < n_alunos; i++)
    {
        printf("Media do aluno %d: %.2f\n", i + 1, media_alunos[i]);
    }

    // não pode esquecer de liberar a memória
    for (int i = 0; i < n_alunos; i++)
    {
        free(notas_alunos[i]); // liberando cada coluna antes das linhas da matriz
    }
    free(notas_alunos);
    free(media_alunos);

    return 0;
}
// aloca memória dinamicamente para uma matriz
float **aloca_matriz(int n, int m)
{
    // modelo já visto, a criação de uma matriz com alocação dinâmica segue sempre esse esquema
    float **matriz = (float **)malloc(n * sizeof(float *));
    // caso falhe, retorna NULL
    if (matriz == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        matriz[i] = (float *)malloc(m * sizeof(float));

        // caso falhe recomendado liberar toda a memória já alocada
        // retornando NULL
        if (matriz[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }
    // tudo certo, então retorna a matriz criada
    return matriz;
}
// preencher matriz, o de sempre. Att na passagem por referencia da matriz
void pree_matriz(float **matriz, int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        printf("Aluno %d:\n", i + 1);
        for (int j = 0; j < m; j++)
        {
            printf("Nota %d = ", j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }
    // att: avaliação de entrada seria uma boa prática...
}
// att a passagem por referencia (matriz e vetor)
void calc_media(float **matriz, float *vetor, int n, int m)
{

    // for pra passar por todos os alunos
    for (int j = 0; j < n; j++)
    {
        float media = 0;
        // for pra somar as notas do aluno
        for (int k = 0; k < m; k++)
        {
            media += matriz[j][k];
        }
        // calcula a media
        media /= (float)m;
        // armazena a media no vetor
        vetor[j] = media;
    }
}
