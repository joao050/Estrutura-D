// Crie uma função que diga se um ponto (x,y) está dentro de um retângulo definido
// pela vertice esquerda(x0,y0) e direita (x1,y1). Afunção deve retornar 1 se
// estiver dentro e 0 caso não estiver.

#include <stdio.h>

int find_point(int x0, int y0, int x1, int y1, int x, int y);
int main()
{

    int x0, y0, x1, y1, x, y = 0;

    printf("Defina o retangulo, preencha da seguinte forma(x0, y0, x1, y1)");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

    printf("Agora o ponto de busca(x, y)");
    scanf("%d %d", &x, &y);

    int retorno = find_point(x0, y0, x1, y1, x, y);

    if (retorno == 1)
    {
        printf("O ponto (%d,%d) esta no retangulo defino.", x, y);
    } else
    {
        printf("O ponto (%d,%d) nao esta no retangulo definido", x, y);
    }
    
    

    return 0;
}

int find_point(int x0, int y0, int x1, int y1, int x, int y)
{

    if ((x <= x1 && x >= x0) && (y <= y1 && y >= y0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}