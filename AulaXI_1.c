// Duplicar a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca nescessária pra usar as funções strlen() e strcpy()

char *duplica(char *original);
int main()
{

    char *nome_orig = "Joao";
    char *nome_dupl = duplica(nome_orig);

    printf("Nome Original: %s\n", nome_orig);
    printf("Nome Duplicado: %s\n", nome_dupl);

    return 0;
}

char *duplica(char *original)
{
    // alocar memória para a cadeia que ira receber a copia da original
    char *replica = (char *)malloc(strlen(original) + 1 * sizeof(char)); // (strlen): função da lib 'string.h', retorna o tamnaho da string ignorando o '\0'

    // copia caractere por caractere da string original para a replica
    strcpy(replica, original);

    return replica;
}