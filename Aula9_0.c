// Tabela ASCII
// 'A' == 65 até 'Z' == 90
// 'a' == 97 até 'z' == 122
//  '0' == 48 até '9' == 57

int eh_letra(char caractere); // função simples pra saber se o caractere digitado foi uma letra
int eh_num(char caractere); // mesmo caso pra números
char upper(char caractere); // entra minusculo e sai maiusculo
char lower(char caractere); // contrario da anterior

#include <stdio.h>
int main()
{

    char c;

    printf("Digite um caractere qualquer:");
    scanf("%c", &c);

    printf("Caractere digitado: %c\n", c);
    printf("Representacao ASCII: %d\n", c);

    // Condições
    
    if (eh_letra(c)) //return 1
    {
        //se for uma letra
        printf(" \'%c\' eh uma letra.\n ", c);

        if (c >= 97 && c <= 122) // 97 == 'a' e 122 == 'z'
        {
            //retorna maiusculo
            printf("Em maiusculo: %c\n", upper(c));
        }
        if (c >= 65 && c <= 90) // 65 == 'A' e 90 == 'Z'
        {
            //retorna minusculo
            printf("Em minusculo: %c\n", lower(c));
        }
    }
    else
    {
        // se não for uma letra
        printf("\'%c\' nao eh uma letra\n", c);

        if (eh_num(c)) // return 1
        {
            printf("\'%c\' eh um digito.\n", c);
        }
        else
        {
            // nem letra nem numero
            printf("Tambem nao eh digito\n");
            printf("Entao eh um caractere especial.\n");
        }
    }

    return 0;
}

int eh_letra(char caractere)
{

    // forma simples
    return ((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z'));
    // se a condiçao for verdadeira retorna 1 (true), caso não for retorna 0 (false)

    // if ((caractere >= 65 && caractere <= 90) || (caractere >= 97 && caractere <= 122))
    // {
    //     return 1;
    // }
    // return 0;
}
int eh_num(char caractere)
{
    // De outra forma
    return (caractere >= '0' && caractere < '9'); //...

    // if (caractere >= 48 && caractere <= 57)
    // {
    //     return 1;
    // }
    // return 0;
}
char upper(char caractere)
{
    if (caractere >= 'a' && caractere <= 'z')
    {
        // return caractere - 32;
        // também >>
        return caractere - 'a' + 'A';
    }
    return 0;
}
char lower(char caractere)
{
    if (caractere >= 'A' && caractere <= 'Z')
    {
        // return caractere + 32;
        // também >>
        return caractere - 'A' + 'a';
    }
    return 0;
}
