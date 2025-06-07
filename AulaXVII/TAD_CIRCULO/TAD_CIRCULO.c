// Arquivo de implementação

#include "TAD_CIRCULO.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cria um círculo com as coordenadas do centro(x,y) e de raio, retornando o círculo criado
Circulo *circ_cria(float x, float y, float raio)
{
    Circulo *circulo = (Circulo*)malloc(sizeof(Circulo));
    if (!circulo)
    {
        printf("Alocacao falhou.");
        exit(1);
    }
    
    circulo->centro = pto_cria(x, y);
    circulo->raio = raio;

    return circulo;
}

// Exibir o círculo
void circ_exibir(Circulo *circulo)
{
    printf("Centro (x: %.2f, y: %.2f)\n", circulo->centro->x, circulo->centro->y);
    printf("Raio do circulo: %.2f\n", circulo->raio);
}

// Deletar o círculo criado
void circ_deleta(Circulo *circulo)
{
    // Primeiro o Ponto *centro que também foi criado com alocação dinâmica
    free(circulo->centro);
    // Depois o círculo completo
    free(circulo);
}

// Função para calcular a área de um círculo
float circ_area(Circulo *circulo)
{
    float area = PI*pow(circulo->raio, 2);
    return area;
}

// Função para determinar se um ponto está dentro ou fora de um círculo
// Retorna 1(dentro) e 0(fora)
int circ_in_out(Circulo *circulo, Ponto *ponto)
{
    float distancia = pto_distancia(circulo->centro, ponto);
    if (distancia < circulo->raio)
    {
        return 1; // dentro
    }
    else
    {
        return 0; // fora
    }
        
}