// Área de um polígno

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // para obter o valor absoluto 'fabs()'

// struct de um ponto utilizando typedef
typedef struct ponto
{
    float x;
    float y;
} Ponto;

// Captura os pontos
void cap_pontos(int n_pontos, Ponto *vet_pontos);

// Calcula a área do polígno
float area_geometrica(int n_pontos, Ponto *vet_pontos);

int main()
{
    // Obtem a quantidade de pontos da figura
    int n_pontos;
    printf("Quantos pontos tem seu figura geometrica (n_pontos >= 3):");
    scanf("%d", &n_pontos);

    // Alocando memória dinamicamente para um vetor de Pontos
    Ponto *fig_geometrica = (Ponto *)malloc(n_pontos * sizeof(Ponto));
    if (!fig_geometrica)
    {
        printf("Falha em alocar memoria!!");
        return 1;
    }
    
    // Obtem as coordenadas dos pontos
    cap_pontos(n_pontos, fig_geometrica);

    // área da figura
    float area = area_geometrica(n_pontos, fig_geometrica);
    printf("Area da sua figura geometrica: %.2f m^2\n", area);

    // Libera a memória que foi alocada
    free(fig_geometrica);

    return 0;
}

// Captura os pontos do polígno
void cap_pontos(int n_pontos, Ponto *vet_pontos)
{
    printf("Determine os pontos/vertices da figura (coordenadas x e y):\n");
    for (int i = 0; i < n_pontos; i++)
    {
        // passamos os endereços '&'
        // accessando os campos da estrutura com '.'(ponto)
        printf("Ponto %d ->>\n", i + 1);
        printf("X: ");
        scanf("%f", &vet_pontos[i].x);
        printf("y: ");
        scanf(" %f", &vet_pontos[i].y);
    }
}

float area_geometrica(int n_pontos, Ponto *vet_pontos)
{
    // A fórmula usada é uma variação da fórmula do polígono de Gauss

    // Baguio doido @-@

    int j;          // índice do próximo ponto da sequência
    float area = 0; // variavel acumulativa para a área da figura

    for (int i = 0; i < n_pontos; i++)
    {
        // 'i' índice atual
        // 'j' será o próximo índice. Quando chegar no útimo ponto j será = 0, ou seja, fecha o polígno (incremento circular)
        j = (i + 1) % n_pontos;

        // Aqui estamos somando varias áreas de trapézios formado pelos pontos 'i'(indice atual) e 'j'(próximo índice)
        // A_trapézio = (Base_Maior - besa_menor) * altura / 2
        // (x_j - x_i) é a "base", e (y_i + y_j)/2 é a "altura média".
        area += (vet_pontos[j].x - vet_pontos[i].x) * (vet_pontos[i].y + vet_pontos[j].y) / 2;
    }

    // no final, retornamos o valor absoluto da área utilizando a função 'fabs()' de <math.h>
    return fabs(area);

    // -- Explicação do ChatGPT
}