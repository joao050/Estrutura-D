// Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio r
// Área: 4r^2
// Volume: 4r^3/3

#include<stdio.h>
#include<math.h>

// Protótipo da função
void calcula_esfera(float raio, float *area, float *volume);

int main()
{
    float raio;
    printf("Informa o raio da esfera: ");
    scanf("%f", &raio);

    float area;
    float volume;

    calcula_esfera(raio, &area, &volume);

    printf("Valor da area: %.2f\n", area);
    printf("Valor do volume: %.2f\n", volume);

    return 0;
}

void calcula_esfera(float raio, float *area, float *volume)
{
    *area = 4*pow(raio, 2);
    *volume = 4*pow(raio, 3)/3;
}