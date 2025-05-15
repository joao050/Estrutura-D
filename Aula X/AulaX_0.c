// Funções que manipulam cadeia de caracteres(strings)

#include <stdio.h>
#include <stdlib.h>

// Função que imprime
void imprime(char *string);
// Calcula o comprimento da string
int comprimento(char *string);
// Só copia
void copia(char *org, char *dest);
// Concatena strings
void concatena(char *orig, char *dest);

int main()
{
    // cadeia de caracteres constante, não pode ser alterada.
    char *p_nome = "Joaozim";
    char *s_nome = "Silva";

    // cadeia de caracteres simples e pode ser alterada, básico
    char n_completo[41] = {'\0'}; // definindo um tamnho que possa receber as duas strings

    printf("Primeiro nome: ");
    imprime(p_nome);
    printf("Segundo nome: ");
    imprime(s_nome);

    // concatena
    concatena(p_nome, n_completo); // nome completo que estava vazia recebe o primeiro nome
    concatena(" ", n_completo);    // concatena um espaço
    concatena(s_nome, n_completo); // concatena o segundo nome

    printf("Nome completo: ");
    imprime(n_completo);
    printf("Comprimento do nome \"%s\" eh: %d\n", n_completo, comprimento(n_completo));

    // Copiando strings

    // Alocar memória suficiente pra receber a copia da sring
    char *cop = (char *)malloc((comprimento(p_nome) + 1) * sizeof(char)); // (comprimento + 1) só por causa do '\0' no final
    if (cop == NULL)
    {
        printf("Alocacao falhou, pouca memoria.");
        return 1;
    }

    copia(p_nome, cop);
    printf("Copia do primerio nome: %s\n", cop);
    // o nome copiado pode ser alterado já que não é uma constante
    cop[0] = 'P';
    printf("Nome copiado e alterado: %s\n", cop);


    //Liberando a memória da string que recebeu a copia
    free(cop);

    return 0;
}
// imprime os caracteres da cadeia enquanto não encontrar o '\0'(caractere que finaliza strings)
void imprime(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("%c", string[i]);
    }
    printf("\n");
}
// conta quantos caracteres o cadeia possui, ignorando o '\0'
int comprimento(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++);
    // retorna o proprio valor de i que foi incrementado no for
    return i;
}
// Só copia...
void copia(char *org, char *dest)
{
    // antes de fazer a copia, ter certeza de que a vairavel de destino ter espaço suficicente pra receber a string
    int i;
    for (i = 0; org[i] != '\0'; i++)
    {
        dest[i] = org[i];
    }
    // depois de copiar a string tem que colocar o '\0' no final
    dest[i] = '\0';
}
// concatena, junta duas strings
void concatena(char *orig, char *dest)
{
    int i, j;
    // encontra o final da string de destino, incrementando na posição i
    for (i = 0; dest[i] != '\0'; i++);

    // copia os caracteres da origem para o final da cadeia de destino
    for (j = 0; orig[j] != '\0'; j++)
    {
        dest[i] = orig[j];
        i++;
    }
    // fecha a cadeia de destino
    dest[i] = '\0';
}