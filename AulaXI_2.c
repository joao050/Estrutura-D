// Funções da biblioteca string.g
// strlen(string) >> tamanho da string
// strcpy(copia, original) >> copia a string original para a copia
// strcat(destino, string) >> concatena strings
// strcmp(string1, string2) >> compara strings(retorna 0 == iguais, < 0 (menor que zero) a primeira é menor, 0 > (maior que zero) a seguda é menor)

#include <stdio.h>
#include <string.h>
int main()
{

    char *string1 = "Banana";

    // tamnho da string
    int tam = strlen(string1);
    // lembrando que ele ignora o caractere nulo '\0'
    printf("Tamanho da string1 \"%s\" eh: %d\n", string1, tam);

    // Copia a string
    char copia[20]; // lembrando que a variavel de destino deve ter tamanho suficiente pre receber a original
    strcpy(copia, string1);
    printf("Exibindo a copia: %s\n", copia);

    // Concatenar (juntar) duas strings
    char concat[20] = "Ola ";
    strcat(concat, "mundo!");
    printf("String concatenada: %s\n", concat);

    // Compara strings
    char *s1 = "Abacate";
    char *s2 = "Abacate";
    if (strcmp(s1, s2) == 0) 
    {
        // se strcmp retornar 0 eles são iguais
        printf("As strings sao iguais.\n");
    }
    else
    {
        // qualquer valor diferente de zero que ela retornar significa que são strings diferentes
        printf("As strings sao diferentes.\n");
    }

    return 0;
}