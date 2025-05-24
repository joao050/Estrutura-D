// Uma lista de alunos

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Todas explicadas no final...

int lenomes(char **alunos);
char *lelinha();
char *duplica(char *string);
int len(char *string);
void imprime_nomes(int qunt, char **alunos);
void libera_memoria(int qunt, char **alunos);

int main()
{
    char *alunos[MAX]; // Um vetor de ponteiros para guardar os nomes

    int n = lenomes(alunos);
    imprime_nomes(n, alunos);
    libera_memoria(n, alunos);

    return 0;
}

int lenomes(char **alunos)
{
    int n = 0;
    do
    {
        printf("Quantos nomes serão armazenados(máximo: 20):"); //...
        scanf("%d", &n);
    } while (n > MAX);
    // um do/while para garantir que o usuario não ultrapasse o limite de nomes

    // for para armazenar os nomes dos alunos no vetor alunos, um por vez, utilizando outra função 'lelinha()'
    for (int i = 0; i < n; i++)
    {
        alunos[i] = lelinha();
    }

    return n; // retorna a quantidade de nomes que o usuario precisou;
}

char *lelinha()
{
    // aqui o usuário ira digitar o nome

    char linha[101]; // string local
    printf("Nome: ");
    scanf(" %100[^\n]%*c", linha); // visto nas outras aulas, basicamente lê até 100 caracteres ou até encontrar \n.
    
    return duplica(linha); 
    // Importante notar que 'lelinha()' retorna um ponteiro da **copia** da string com 'duplica()'
    // já que a linha digitada aqui é uma variavel local(esse aponta e aponta me deixa confusio *-_-)
    // -->> retorna pra 'lenomes()' que será armazenado no vetor alunos
}

char *duplica(char *string)
{
    // utilizando malloc alocamos memoria para a copia da string
    char *copia = (char *)malloc(len(string) + 1 * sizeof(char)); // a função 'len()' aqui basicamente retorna o tamanho da string
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
        copia[i] = string[i]; // copia recebe a string original
    }
    copia[i] = '\0';// lembrando de fechar a cadeia

    return copia; // retorna o ponteiro da string copiada -->> lembrndo que é lá pra função 'lelinha()'
}

int len(char *string)
{
    // Simplesmente o tamanho da string
    int i;
    for (i = 0; string[i] != '\0'; i++);
    return i;
}

void imprime_nomes(int qunt, char **alunos)
{
    // imprimir os nomes, básico
    for (int i = 0; i < qunt; i++)
    {
        printf("%d - %s\n", i + 1, alunos[i]);
    }
}

void libera_memoria(int qunt, char **alunos)
{
    //Lembra que cada nome foi alocado dinamicamente, então sera nescessario liberar cada string que foi alocada com malloc
    for (int i = 0; i < qunt; i++)
    {
        free(alunos[i]);
    }
}