// Implemente uma função que calcule a derivada de um polinômio

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// protótipo da função
// *out é um vetor onde vai receber o resultado da derivada dos coeficientes
void deriva(double *poli, int grau, double *out);

int main()
{
    // preguiça....

    return 0;
}

void deriva(double *poli, int grau, double *out)
{
    out[0] = poli[0] * grau; // ax^2 >> 2ax^2-1
    out[1] = poli[1] * 1; // bx >> 1bx^0 >> b
    out[2] = poli[2] * 0; // c >> derivada da constante = 0;
}