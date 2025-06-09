// Implemente uma função que avalia polinômios

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Protótipo da função
// *poli é um vetor de coeficientes
double avalia ( double *poli, int grau, double x);

int main()
{
    double *coeficientes = (double*)malloc(3 * sizeof(double));
    if (!coeficientes)
    {
        printf("Falha na alocação de memória.");
        return 0;
    }
    
    int grau;
    double x;

    printf("Em qual grau avaliar os polinomios: ");
    scanf("%d", &grau);

    printf("Digite os coeficientes a, b e c respectivamente\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%lf", &coeficientes[i]);
    }

    printf("Qual o valor de x: ");
    scanf("%lf", &x);

    printf("Resultado do polinomio de grau %d = %lf", grau, avalia(coeficientes, grau, x));
    
    return 0;
}

double avalia ( double *poli, int grau, double x)
{
    return (poli[0]*pow(x, grau)) + (poli[1] * x) + poli[2];
}