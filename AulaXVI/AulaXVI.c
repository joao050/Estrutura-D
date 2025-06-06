// Arquivo main

// Arquivo de cabeçalho
#include "TAD_PONTO/TAD_PONTO.h"

//Biblioteca básica
#include <stdio.h>

int main()
{
    Ponto *ponto1 = pto_cria(1.0, 2.0);
    printf("Ponto 1: ");
    pto_exibir(ponto1);

    pto_atribuir(ponto1, 3.5, 2.3);
    printf("Atribuindo novo ponto 1: ");
    pto_exibir(ponto1);

    Ponto *ponto2 = pto_cria(4.0, 1.0);
    printf("Ponto 2: ");
    pto_exibir(ponto2);

    printf("A distancia entre os dois ponto: %.2f", pto_distancia(ponto1, ponto2));

    pto_deleta(ponto1);
    pto_deleta(ponto2);

    return 0;
}