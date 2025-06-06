// Arquivo de cabeçalho

#ifndef _TAD_PONTO_
#define _TAD_PONTO_

// Estrutura exportada
struct ponto
{
    float x, y;
};

// tipo exportado
typedef struct ponto Ponto;

// funções exportadas

// Função cria
// aloca e retorna um ponto com coordenada (x,y)
Ponto *pto_cria(float x, float y);

// Função para exibir as coordenadas do ponto
void pto_exibir(Ponto *ponto);

// Função deletar ponto
// Deleta o ponto que foi criado com alocação dinâmica
void pto_deleta(Ponto *ponto);

// Função para acessar as coordenadas de um ponto
// retorna as coordenadas do ponto
void pto_acessa(Ponto *ponto, float *x, float *y);

// Função para atribuir os valores dos ponto
void pto_atribuir(Ponto *ponto, float x, float y);

// Função para calcular a distância entre dois pontos
// Retorna o valor da distãcia
float pto_distancia(Ponto *ponto1, Ponto *ponto2);

#include "TAD_PONTO.c"
#endif