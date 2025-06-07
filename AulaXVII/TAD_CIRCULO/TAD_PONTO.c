// Arquivo de implementação

// Arquivo de cabeçalho, contendo a estrutura **Ponto** e os protótipos das funções
#include "TAD_PONTO.h"

// Bibliotecas básicas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funções para manipular os dados

// Função cria
// aloca e retorna um ponto com coordenada (x,y)
Ponto *pto_cria(float x, float y)
{
    Ponto *pt = (Ponto *)malloc(sizeof(Ponto));
    if (pt == NULL)
    {
        printf("Alocação falhou!!\n");
        exit(1);
    }

    pt->x = x;
    pt->y = y;

    return pt;
}

// Função para exibir as coordenadas do ponto
void pto_exibir(Ponto *ponto)
{
    printf("\nCoordenadas do ponto:\n");
    printf("X: %.2f\n", ponto->x);
    printf("Y: %.2f\n", ponto->y);
}

// Função deletar ponto
// Deleta o ponto que foi criado com alocação dinâmica
void pto_deleta(Ponto *ponto)
{
    free(ponto);
}

// Função para acessar as coordenadas de um ponto
// retorna as coordenadas do ponto
void pto_acessa(Ponto *ponto, float *x, float *y)
{
    *x = ponto->x;
    *y = ponto->y;
}

// Função para atribuir os valores dos ponto
void pto_atribuir(Ponto *ponto, float x, float y)
{
    ponto->x = x;
    ponto->y = y;
}

// Função para calcular a distância entre dois pontos
// Retorna o valor da distãcia
float pto_distancia(Ponto *ponto1, Ponto *ponto2)
{
    float dx = pow(ponto1->x - ponto2->x, 2);
    float dy = pow(ponto1->y - ponto2->y, 2);
    return sqrt(dx + dy);
}
