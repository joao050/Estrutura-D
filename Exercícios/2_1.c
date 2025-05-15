// Faça uma função que calcule as raízes de uma equação de segundo grau
// int raizes(float a, float b, float c, double *x1, double *x2)
#include<stdio.h>
#include<math.h>
int raizes(float a, float b, float c, double *x1, double *x2);
int main(){

    double x1 = 0, x2 = 0;
    float a, b, c;
    printf("Digite o valor do coeficiente a: ");
    scanf("%f", &a);
    printf("Digite o valor do coeficiente b: ");
    scanf("%f", &b);
    printf("Digite o valor do coeficiente c: ");
    scanf("%f", &c);

    switch (raizes(a, b, c, &x1, &x2))
    {
    case -1:
        printf("Nao e uma equacao do segundo grau.\n");
        break;
    case 0:
        printf(" A equação (%.2fx^2 + %.2fx + %.2fc) tem duas raizes: \n", a, b, c);
        printf("X1: %.2f\n", x1);
        printf("X2: %.2f\n", x2);
        break;
    case 1:
        printf("A equação do segundo grau tem apenas uma raiz, X1 = %.2f\n", x1);
        break;
    
    default:
        break;
    }

    return 0;
}
int raizes(float a, float b, float c, double *x1, double *x2){
    if (a == 0)
    {
        // "Não é uma equação de segundo grau"
        return -1;
    }

    double delta = (b * b) - 4 * a * c;

    if (delta == 0)
    {
        *x1 = (-b + sqrt(delta))/(2*a);
        return 1;
    }
    else
    {
        *x1 = (-b + sqrt(delta))/(2*a);
        *x2 = (-b - sqrt(delta))/(2*a);
        return 0;
    }
       
}

