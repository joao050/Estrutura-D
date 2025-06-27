//Arquivo principal

#include <stdio.h>
#include <stdlib.h>
#include "TAD_MATRIX/TAD_MATRIX.h"

int main()
{
    int l, c;
    int linha, coluna;
    float valor;
    int find_l, find_c;

    printf("Digite o numero de linhas e de colunas da matriz: ");
    scanf("%d", &l);
    scanf("%d", &c);

    printf("Criando matriz.\n");

    Matriz *matriz1 = mat_cria(l, c);
    printf("Matriz criada.\n");

    printf("A matriz possui %d linhas e %d colunas.\n", mat_linhas(matriz1), mat_colunas(matriz1));

    printf("Atribuir valor:\n");
    printf("Linha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);
    printf("Valor: ");
    scanf("%f", &valor);

    mat_atribui(matriz1, linha, coluna, valor);
    printf("Valor atribuido.\n");

    printf("Qual valor encontrar(linha/coluna): ");
    scanf("%d %d", &find_l, &find_c);

    printf("Valor encontrado: %.2f\n", mat_acessa(matriz1, find_l, find_c));

    mat_libera(matriz1);

    return 0;
}