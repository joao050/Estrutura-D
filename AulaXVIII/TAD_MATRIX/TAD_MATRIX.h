// Arquivo de cabeçalho

#ifndef _TAD_MATRIX_
#define _TAD_MATRIX_

// estrutura exportada
struct matriz
{
    int linhas;
    int colunas;
    float **valores;
};

// tipo exportado
typedef struct matriz Matriz;

//Cria uma matriz e rotorna a matriz criada
Matriz *mat_cria(int linhas, int colunas);

//Libera memoria da matriz criada
void mat_libera(Matriz* mat);

//Função para verificar de determinada posição da matriz é válida 
int mat_position_valid(Matriz *mat, int i, int j);

//Acessa um elemento na linha i da coluna j e retorna o valor
float mat_acessa(Matriz *mat, int i, int j);

//atribuir um valor na linha i da coluna j
void mat_atribui(Matriz *mat, int i, int j, float v);

// retorna o número de linhas da matriz
int mat_linhas(Matriz *mat);

// retorna o número de colunas da matriz
int mat_colunas(Matriz *mat);

#include "TAD_MATRIX.c"

#endif