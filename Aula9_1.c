// Cadeia de caracteres

#include <stdio.h>
int main()
{

    // uma cadeia de caracteres é sempre finalizado com '\0'
    // char cidade[] = {'F','o','r','t','a','l','e','z','a','\0'};
    // char cidade[] = "Fortaleza";
    char nome[41];
    char nasc[21];

    printf("Digite seu nome completo");
    scanf("%40[^\n]", nome); // obtem até 40 caracteres
    // formato pra obter uma cadeia de caractere digitado pelo usuário

    // Caso tenha digitado mais de 40 caracteres,
    // retira-se tudo até o '\n'.
    while (getchar() != '\n');

    printf("Onde nasceu: ");
    scanf("%20[^\n]", nasc); // obtem até 20 caracteres

    // Caso tenha digitado mais de 20 caracteres,
    // retira-se tudo até o '\n'.
    while (getchar() != '\n');

    printf("%s nasceu em %s.", nome, nasc);

    return 0;
}

//