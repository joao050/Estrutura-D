// TAD_CIRCULO

#ifndef _TAD_CIRCULO_
#define _TAD_CIRCULO_

// Dependência de módulos
#include "TAD_PONTO.h"

// Define PI utilizado na fórmula da área
#define PI 3.14

// Estrutura exportada
struct circulo
{
    Ponto *centro;
    float raio;
};

// Tipo exportado
typedef struct circulo Circulo;

// Funções exportadas

// Função que cria um círculo e retorna o círculo criado
Circulo *circ_cria(float x, float y, float raio);

// Função para exibir o círculo criado
void circ_exibir(Circulo *circulo);

// Função que libera a memória de um círculo criado
void circ_deleta(Circulo *circulo);

// Função que calcula a área do circulo
float circ_area(Circulo *circulo);

// Função que verifica se um determinado ponto está dentro do circulo
// Retorna 1(dentro) e 0(fora)
int circ_in_out(Circulo *circulo, Ponto *ponto);

#include "TAD_CIRCULO.c"
#endif