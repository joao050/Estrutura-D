// Arquivo de implementação

#include <stdio.h>
#include <stdlib.h>

// arquivo de cabeçalho
#include "TAD_LISTA.h"

// estrutura exportada
struct lista
{
    int valor;
    struct lista *prox;
};

// Funções

// Função para criar uma lista
Lista *lista_cria()
{
    return NULL;
}

// Função insere um novo elemento na lista e retorna o novo valor inicial da lista
Lista *lista_insere(Lista *list, int valor)
{
    Lista *nova_lista = (Lista *)malloc(sizeof(Lista));
    if (!nova_lista)
    {
        printf("Não foi possivel alocar memoria para a lista.\n");
        exit(1);
    }

    nova_lista->valor = valor;

    nova_lista->prox = list;

    return nova_lista;
}

// Função para imprimir os valores da lista
void lista_imprime(Lista *list)
{
    Lista *p; // lista auxiliar para percorrer toda a lista
    for (p = list; p != NULL; p = p->prox)
    {
        printf("%d\n", p->valor);
    }
}

// Função para verificar se a lista está vazia (1) ou não (0)
int lista_vazia(Lista *list)
{
    if (list == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função de busca que retorna o numero encontrado ou NULL quando não encontrado
Lista *lista_busca(Lista *list, int valor)
{
    if (lista_vazia(list) == 0)
    {
        Lista *p;
        // Busca eficiente
        for (p = list; p != NULL && p->valor <= valor; p = p->prox)
        {
            if (p->valor == valor)
            {
                return p;
            }
        }
    }
    return NULL;
}

// Função para retirar um elemento da lista. Retorna a nova lista
Lista *lista_retira(Lista *list, int valor)
{
    Lista *anterior = NULL; // um ponteiro pro elemento anterior

    Lista *p = list; // Ponteiro para percorrer a lista

    // Procura pelo valor
    while (p != NULL && p->valor != valor)
    {
        anterior = p;
        p = p->prox;
    }

    // verifica se achou o valor
    if (p == NULL)
    {
        printf("Valor não encontrado.\n");
        return list; // retorna a lista original
    }

    // caso o elemento esteja na primeira posição
    if (anterior == NULL)
    {
        list = p->prox;
    }

    // Caso o elemento esteja no meio da lista ou no final
    else
    {
        anterior->prox = p->prox;
    }

    free(p);

    return list;
}

// função para destruir uma lista
void lista_libera(Lista *list)
{
    Lista *p = list;
    while (p != NULL)
    {
        Lista *temp = p->prox; // ponteiro temporario para o proximo elemento
        free(p);               // libera a memória
        p = temp;              // agora o p aponta para o próximo elemento
    }
}

// Insere um novo elemento na lista em ordem
Lista *lista_insere_ordenado(Lista *list, int v)
{
    Lista *ant = NULL;
    Lista *p = list;
    Lista *novo;

    // encontra a posição de inserir
    while (p != NULL && p->valor <= v)
    {
        ant = p;
        p = p->prox;
    }

    // cria umm novo elemento
    novo = (Lista *)malloc(sizeof(Lista));
    if (!novo)
    {
        printf("Falha em criar novo elemento.\n");
        exit(1);
    }
    novo->valor = v;

    // O elemento está no inicio da lista
    if (ant == NULL)
    {
        novo->prox = list;
        list = novo;
    }
    else
    {
        // O elemento está no meio ou no final
        novo->prox = p;
        ant->prox = novo;
    }

    return list;
}

//Função para verificar se duas listas são iguis
int lista_iguis(Lista *list1, Lista *list2)
{
    Lista *p1;
    Lista *p2;

    for ( p1 = list1, p2 = list2; p1 != NULL && p2 == NULL; p1 = p1->prox, p2 = p2->prox)
    {
        if (p1 != p2)
        {
            return 0;
        }
        
    }
    return p1==p2;
}
