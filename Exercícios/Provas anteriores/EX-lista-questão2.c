/*Desenvolva um programa em C que receba a quantidade de pontos a serem processados. Em
seguida, solicite ao usuário que insira as coordenadas dos pontos no formato x,y (onde x e y são valores de ponto
flutuante). Os pontos devem ser armazenados em um vetor de ponteiros para uma estrutura chamada ponto.
Após a inserção de todos os pontos, o programa deve calcular e exibir o centro geométrico de todos eles. Para
isso, implemente uma função com o seguinte protótipo:
struct ponto * centro_geo(struct ponto ** lista_pontos);
Requisitos adicionais:
Utilize dinamicamente a estrutura ponto para armazenar as coordenadas.
Certifique-se de liberar a memória alocada no final da execução.
Dica: O centro geométrico de um conjunto de pontos é dado pela média aritmética das coordenadas x e y de
todos os pontos.*/

// Deus tenha piedade das nossas pobres almas...

#include <stdio.h>
#include <stdlib.h>

// struct criada com typedef
typedef struct ponto
{
    float x, y;
} Ponto;

// Função para criar um vetor de ponterios do tipo struct ponto, retorna o vetor criado
Ponto **vet_pontos(int tamanho);
void definir_pontos(Ponto **vetor_pontos, int tamanho);
void exibir_pontos(Ponto **vetor_pontos, int tamanho);
// cria um ponteiro para um Ponto e retorna o ponto criado
Ponto *centro_geometrico(Ponto **vetor_pontos, int tamanho);
void libera_tudo(Ponto **vetor_pontos,int tamanho, Ponto *ponto);

int main()
{
    int n_pontos;
    printf("Defina quantos pontos(>= 3): ");
    scanf("%d", &n_pontos);

    // Vetor de ponteiros 
    Ponto **vetor_pontos = vet_pontos(n_pontos);
    definir_pontos(vetor_pontos, n_pontos);
    printf("\nExibir os pontos:\n");
    exibir_pontos(vetor_pontos, n_pontos);

    // O centro da figura geométrica é um ponto
    Ponto *centro_geo = centro_geometrico(vetor_pontos, n_pontos);
    printf("Centro geometrico: x = %.2f e y = %.2f\n", centro_geo->x, centro_geo->y);
    // acessando com -> pq centro_geo é um pponteiro

    // Liberando a memória alocada
    libera_tudo(vetor_pontos, n_pontos, centro_geo);

    return 0;
}

// cria um vetor de ponteiros ponteiro ponterio ponteiro ponerito AAAAAAAAAAAAAAAAAAaaaa....
Ponto **vet_pontos(int tamanho)
{
    Ponto **pontos = (Ponto **)malloc(tamanho * sizeof(Ponto *));
    if (pontos == NULL)
    {
        printf("Alocacao falhou.");
        exit(1);
    }
    // inicializando todas as posições com NULL
    for (int i = 0; i < tamanho; i++)
    {
        pontos[i] = NULL;
    }

    return pontos;
}
void definir_pontos(Ponto **vetor_pontos, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor_pontos[i] = (Ponto *)malloc(sizeof(Ponto));
        if (vetor_pontos[i] == NULL)
        {
            printf("Alocação falhou.\n");
            exit(1);
        }
        printf("Ponto %d >>\n", i);
        printf("x: ");
        scanf("%f", &vetor_pontos[i]->x);
        printf("y: ");
        scanf("%f", &vetor_pontos[i]->y);
    }
}
void exibir_pontos(Ponto **vetor_pontos, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Ponto %d >>\n", i);
        printf("x: %.2f\n", vetor_pontos[i]->x);
        printf("y: %.2f\n", vetor_pontos[i]->y);
        printf("\n");
    }
}
Ponto *centro_geometrico(Ponto **vetor_pontos, int tamanho)
{
    Ponto *centro = (Ponto *)malloc(sizeof(Ponto));
    if (centro == NULL)
    {
        printf("Alocação de memoria para o ponto centro falhou.");
        exit(1);
    }
    // média dos pontos
    centro->x = 0;
    centro->y = 0;

    for (int i = 0; i < tamanho; i++)
    {
        centro->x += vetor_pontos[i]->x;
        centro->y += vetor_pontos[i]->y;
    }

    centro->x /= tamanho;
    centro->y /= tamanho;

    return centro;
}
void libera_tudo(Ponto **vetor_pontos,int tamanho, Ponto *ponto)
{
    // Liberando a memória alocada
    for (int i = 0; i < tamanho; i++)
    {
        free(vetor_pontos[i]);
    }
    free(vetor_pontos);
    free(ponto);
}