//Arquivo de cabeçalho

#ifndef _TAD_LISTA_
#define _TAD_LISTA_

// Tipo exportado
typedef struct lista Lista;

// Função para criar uma lista
Lista *lista_cria();

//Função insere um novo elemento na lista e retorna o novo valor inicial da lista
Lista *lista_insere(Lista *list, int valor);

//Função para imprimir os valores da lista
void lista_imprime(Lista *list);

//Função para verificar se alista está vazia
int lista_vazia(Lista *list);

//Função de busca que retorna o numero encontrado ou null quando não encontrado
Lista *lista_busca(Lista *list, int valor);

//Função para retirar um elemento da lista. Retorna a nova lista
Lista *lista_retira(Lista *list, int valor);

//função para destruir uma lista
void lista_libera(Lista *list);

// Insere um novo elemento na lista em ordem
Lista *lista_insere_ordenado(Lista *list, int v);


//Função para verificar se duas listas são iguis
int lista_iguis(Lista *list1, Lista *list2);
#include"TAD_LISTA.c"

#endif