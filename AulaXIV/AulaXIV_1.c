// descobrir o centro de uma figura geométrica

#include <stdio.h>
#include <stdlib.h>

// struct ponto utilizando typedef
typedef struct ponto
{
    float x;
    float y;
} Ponto;

// preencher o vetor de pontos
void pontos_geo(int qunt_pontos, Ponto *pontos);

// Obtem um ponto que no caso seria o centro da figura geométrica
Ponto centr_geo(int n_pontos, Ponto *ponts);

int main()
{
    int n_pontos;
    printf("Quantos pontos tera a figura: "); // Obtem do usuário a quantidade de pontos da figura
    scanf("%d", &n_pontos);
    // ** Aprimorei o código alocando memória dinamicamente para o vetor de Pontos
    Ponto *fig_geometrica = (Ponto *)malloc(n_pontos * sizeof(Ponto));
    if (!fig_geometrica)
    {
        printf("Erro de memória.\n");
        return 1;
    }
    
    // Obtem os pontos da figura
    pontos_geo(n_pontos, fig_geometrica);

    // Aqui centro vai receber as coordenadas do centro da figura
    Ponto centro = centr_geo(n_pontos, fig_geometrica);

    printf("O centro da figura geometrica a dada pelo ponto x: %.2f, y: %.2f\n", centro.x, centro.y);

    // Libreando a memória que foi alocada
    free(fig_geometrica);
    

    return 0;
}

// Obtem as coordenadas das figuras
void pontos_geo(int qunt_pontos, Ponto *pontos) // Lembrando que 'Ponto *pontos' é um vetor de pontos 
{
    printf("Digite as coordenadas dos pontos (X,y):");
    for (int i = 0; i < qunt_pontos; i++)
    {
        printf("X: ");
        scanf("%f", &pontos[i].x);
        printf("Y: ");
        scanf(" %f", &pontos[i].y);
    }
    
}

Ponto centr_geo(int n_pontos, Ponto *ponts)
{
    // struct que vai receber as coordenadas do centro da figura
    Ponto centro;
    centro.x = 0.0;
    centro.y = 0.0;

    // basicamente calculando a mádia
    for (int i = 0; i < n_pontos; i++)
    {
        // somando os pontos
        centro.x += ponts[i].x;
        centro.y += ponts[i].y;
    }

    // divide pela quantidade de pontos
    centro.x /= n_pontos;
    centro.y /= n_pontos;
    
    //retornamos o ponto do centro da figura geometrica
    return centro;
}