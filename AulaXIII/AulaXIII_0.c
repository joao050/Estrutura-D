// Estruturas

// Não utilizei o 'typedef'

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// estrutura básica de um ponto no plano cartesiano
struct Ponto
{
    int x;
    int y;
};

struct Ponto *cria_ponto();          // cria uma estrutura ponto alocando memória dinamicamente
void ler_ponto(struct Ponto *p);     // lê as coordenadas digitados pelo usuário
void imprime_ponto(struct Ponto *p); // imprime o ponto digitado
float distancia(struct Ponto *ponto1, struct Ponto *ponto2);

int main()
{

    // estrutura qulquer>>

    struct Ponto p_qualquer;
    printf("Digite digite uma coorddenada qualquer(x,y): ");
    scanf("%d %d", &p_qualquer.x, &p_qualquer.y);
    // acessando os valores da estrutura utilizando o ponto(.)

    printf("Ponto digitado(%d,%d)\n", p_qualquer.x, p_qualquer.y); // acessar esses valores da estrutura //nome da estrutura.tipo de dado//

    // Estrutras criada com ponteiros

    // criando dois ponteiros para a struct Ponto usando a função 'cria_ponto()'
    struct Ponto *p1 = cria_ponto();
    struct Ponto *p2 = cria_ponto();

    ler_ponto(p1);
    imprime_ponto(p1);

    ler_ponto(p2);
    imprime_ponto(p2);

    printf("A distancia entre os pontos (%d,%d) e (%d,%d) eh: %.2f\n", p1->x, p1->y, p2->x, p2->y, distancia(p1, p2));
    // como os pontos p1 e p2 foram criados com ponteiros a forma de acessar os valores muda um pouco, agora usamos (->)

    // liberando a memória já que os dois pontos foram criados com alocação dinâmica
    free(p1);
    free(p2);

    return 0;
}

struct Ponto *cria_ponto()
{
    struct Ponto *p = (struct Ponto *)malloc(sizeof(struct Ponto));
    // Aloca espaço na memória para um ponto (malloc)
    // sizeof(struct ponto) calcula quantos bytes são necessários para guardar um ponto.

    if (!p)
    {
        printf("Falha em alocar memoria.");
        exit(1);
    }

    return p; // retorna um ponteiro para o ponto criado
}

void ler_ponto(struct Ponto *p)
{
    printf("Digite as coordenadas(x,y):");
    scanf("%d %d", &p->x, &p->y); // lê os valors digitados pelo usuário
    // atenção na forma de acessar o campo da estrutura (->)
}

void imprime_ponto(struct Ponto *p)
{
    printf("Ponto digitado (%d,%d)\n", p->x, p->y); // **(->)**
}

float distancia(struct Ponto *ponto1, struct Ponto *ponto2)
{
    // retorna a diatância entre dois pontos no plano cartesiano
    return sqrt(pow(ponto2->x - ponto1->x, 2) + pow(ponto2->y - ponto1->y, 2));
}