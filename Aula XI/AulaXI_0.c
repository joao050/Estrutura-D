// Comparar strings

#include <stdio.h>

int compara(char *s1, char *s2);
int main()
{

    char *cidade1 = "Aracati";
    char *cidade2 = "aracati";

    printf("Na escala alfabetica ");
    switch (compara(cidade1, cidade2))
    {
    case -1:
        printf("a cidade 1 \"%s\" vem antes da cidade2 \"%s\"\n", cidade1, cidade2);
        break;
    case 0:
        printf("os nomes das cidades sao iguais.\n");
        break;
    case 1:
        printf("a cidade2 \"%s\" vem antes da cidade1 \"%s\"\n", cidade2, cidade1);
        break;
    }

    return 0;
}
int compara(char *s1, char *s2)
{
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        // se o caractere de s1 for maior que o de s2 significa que s2 vem antes na escala alfabetica
        // Exemplo: s1[i] == 'a' e s2[i] == 'A' >> aqui o 'A' maiusculo de s2 vem antes na escala alfabetica (65)
        // logo vem antes de 'a' minusculo de s1 (97)
        if (s1[i] > s2[i])
        {
            return 1;
        }
        // aqui seria o caso inverso ao anterior
        //  se o caractere de s2 for maior na escala alfabetica então significa que o caractere de s1 vem antes
        if (s1[i] < s2[i])
        {
            return -1;
        }
    }
    // aqui as duas strings terminaram iguais com '\0'
    if (s1[i] == s2[i])
    {
        return 0;
    }
    // se s1 terminar antes, então ele fica vem antes na escala alfabetica
    if (s1[i] == '\0')
    {
        return -1;
    }
    // aqui o s2 terminou antes
    if (s2[i] == '\0')
    {
        return 1;
    }
}
