// Implemente uma função que indique se determinado ponto esta dentro de um retángulo

#include <stdio.h>
#include <stdlib.h>

typedef struct ponto
{
    float x, y;
} Ponto;

Ponto *ponto_def();
int ponto_in_out(Ponto *i_esq, Ponto *s_dirt, Ponto *pt);
void ponto_libera(Ponto *ponto);

int main()
{
    printf("Ponto inferior esquerdo:\n");
    Ponto *in_esquerdo = ponto_def();

    printf("Ponto superior direito:\n");
    Ponto *sup_direito = ponto_def();
    
    printf("Ponto qualquer:\n");
    Ponto *p1 = ponto_def();

    printf("O ponto x: %.2f, y: %.2f está ", p1->x, p1->y);
    if (ponto_in_out(in_esquerdo, sup_direito, p1) == 1)
    {
        printf("dentro do retangulo.\n");
    }
    else
    {
        printf("fora do retangulo.\n");
    }

    ponto_libera(in_esquerdo);
    ponto_libera(sup_direito);
    ponto_libera(p1);

    return 0;
}

Ponto *ponto_def()
{
    Ponto *pt = (Ponto *)malloc(sizeof(Ponto));
    if (!pt)
    {
        exit(1);
    }

    printf("Digite x e y: ");
    scanf("%f%f", &pt->x, &pt->y);

    return pt;
}

int ponto_in_out(Ponto *i_esq, Ponto *s_dirt, Ponto *pt)
{
    if (pt->x > i_esq->x && pt->x < s_dirt->x)
    {
        if (pt->y > i_esq->y && pt->y < s_dirt->y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void ponto_libera(Ponto *ponto)
{
    free(ponto);
}