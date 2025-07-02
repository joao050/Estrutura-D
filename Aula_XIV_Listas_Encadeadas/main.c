// Arquivo principal

#include<stdio.h>
#include<stdlib.h>
#include"TAD_LISTA/TAD_LISTA.h"

int main()
{
    Lista *minha_lista = lista_cria();
    Lista *minha_segunda_lista = lista_cria();

    if (lista_vazia(minha_lista) == 1)
    {
        printf("Lista vazia.\n");
    }

    printf("Inserindo numeros...\n");

    for (int i = 0; i < 50; i++)
    {
        minha_lista = lista_insere_ordenado(minha_lista, i + 1);
    }

    for (int i = 0; i < 50; i++)
    {
        minha_segunda_lista = lista_insere_ordenado(minha_segunda_lista, i + 1);
    }

    printf("As listas sao ");
    if (lista_iguis(minha_lista, minha_segunda_lista))
    {
        printf("deiferentes\n");
    }
    else
    {
        printf("iguais\n");
    }
    
    
    if (lista_vazia(minha_lista) == 0)
    {
        printf("A lista nao esta vazia.\n");
    }
    
    printf("Numeros inseridos:\n");

    lista_imprime(minha_lista);

    int valor_busca;
    printf("Procurar por qual valor: ");
    scanf("%d", &valor_busca);

    Lista *find = lista_busca(minha_lista, valor_busca);
    printf("Valor ");
    if (find)
    {
        printf("%d encontrado.\n", find->valor);
    }
    else
    {
        printf("nao encontrado.\n");
    }

    int valor_retira;
    printf("Remover qual valor: ");
    scanf("%d", &valor_retira);

    minha_lista = lista_retira(minha_lista, valor_retira);

    lista_imprime(minha_lista);

    lista_libera(minha_lista);
    
}