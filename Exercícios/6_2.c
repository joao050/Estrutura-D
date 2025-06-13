// Considere uma estrutura para representar um vetor no espaço 3D.
// Implemente uma função para calcular o produto escalar entre dois vetores
// vetor1(x1,y1,z1); vetor2(x2,y2,z2)
// produto escalar = (x1 * x2) + (y1 * y2) + (z1 * z2)

#include <stdio.h>
#include <stdlib.h>

typedef struct vetor3d
{
    float x, y, z;
} Vetor;

Vetor *cria_vetor3d();
void libera_vetor(Vetor *vet);
float produto_escalar(Vetor *vet1, Vetor *vet2);

int main()
{
    printf("Vetor 1:\n");
    Vetor *vetor1 = cria_vetor3d();

    printf("Vetor 2:\n");
    Vetor *vetor2 = cria_vetor3d();

    printf("Resultado de produto escalar entre dois vetores: %.2f\n", produto_escalar(vetor1, vetor2));

    return 0;
}

Vetor *cria_vetor3d()
{
    Vetor *vet = (Vetor *)malloc(sizeof(Vetor));
    if (!vet)
    {
        exit(1);
    }

    printf("Digite x, y e z: ");
    scanf("%f%f%f", &vet->x, &vet->y, &vet->z);

    return vet;
}
void libera_vetor(Vetor *vet)
{
    free(vet);
}
float produto_escalar(Vetor *vet1, Vetor *vet2)
{
    return (vet1->x * vet2->x) + (vet1->y * vet2->y) + (vet1->z * vet2->z);
}