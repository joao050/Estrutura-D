#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TAD_CIRCULO/TAD_CIRCULO.h"
#include "TAD_CIRCULO/TAD_PONTO.h"

int main()
{

    Circulo *circulo1 = circ_cria(2.0, 3.0, 5.5);

    circ_exibir(circulo1);

    printf("A area desse circulo: %.2fm^2\n", circ_area(circulo1));

    Ponto *ponto1 = pto_cria(6.0, 7.0);

    printf("Distancia entre o ponto e o centro do circulo: %.2f\n", pto_distancia(circulo1->centro, ponto1));

    if (circ_in_out(circulo1, ponto1) == 1)
    {
        printf("O ponto(%.2f,%.2f) esta dentro do circulo.", ponto1->x, ponto1->y);
    }
    else
    {
        printf("O ponto(%.2f,%.2f) esta fora do circulo.", ponto1->x, ponto1->y);
    }

    circ_deleta(circulo1);
    pto_deleta(ponto1);

    return 0;
}
