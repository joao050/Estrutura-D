// Trabalhando com strings usando recursividade

#include <stdio.h>

// vamos imprimir a cadeia de caracteres usando recursividade
void imprime_rec(char *string);

// imprimir ao contrario
void imp_invert_rec(char *string);

// fazer uma copia com recursividade
void duplica(char *orig, char *copia);

// Utilizando recursividade para descobrir o comprimento da cadeia
int comprimento(char *string);

int main()
{

    char str[21] = "Marmelada";
    char str2[21] = "";

    printf("String normal: ");
    imprime_rec(str);

    printf("\nString invertida: ");
    imp_invert_rec(str);

    printf("\nString copia: ");
    duplica(str, str2);
    imprime_rec(str2);

    printf("\nComprimento da string \"%s\" eh: %d", str, comprimento(str));

    return 0;
}

void imprime_rec(char *string)
{
    // pra uma função recursiva sempre deve ter uma condição pra parada...
    if (string[0] != '\0')
    {
        putchar(string[0]);      // imprime um unico caractere na tela
        imprime_rec(&string[1]); // chamada recursiva da propria função, passando agora próximo caractere da string
        // ** passando o endereço '&' **
    }
    // só para quando encontrar o '\0' no final da string.
}
void imp_invert_rec(char *string)
{
    // no caso para imprimir a string ao contrario basta inverter a ordem dos comandos
    if (string[0] != '\0')
    {
        imp_invert_rec(&string[1]);
        putchar(string[0]);
    }
}
void duplica(char *orig, char *copia)
{
    // condição fundamental de uma função recursiva
    if (orig[0] != '\0')
    {
        copia[0] = orig[0];           // copia recebendo valor da origem
        duplica(&orig[1], &copia[1]); // chamada recursiva, passando agora o proximo caractere da cadeia
        // sempre passando o endereço '&' **
    }
}
int comprimento(char *string)
{
    // condição de função, enqunto não encontar o '\0' do final ele vai incrementando no else
    // que retorna o tamanho da cadeia
    if (string[0] == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + comprimento(&string[1]);
    }
       
}