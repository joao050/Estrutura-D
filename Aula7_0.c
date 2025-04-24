#include <stdio.h>
#include <stdlib.h>

void pree_vet(float *notas, int quant);//Preenche o vetor
void exib_vet(float *notas, int quant);//Exibir o vetor
float media(float *notas, int quant);//Calcula a media
float var(float *notas, int quant);//Calcula a variancia
int main()
{

    int n;

    printf("Digite a quantidade de dados pro vetor: ");
    scanf("%d", &n);

    // Vetor criado com ponteiro
    float *notas = malloc(n * sizeof(float));//'malloc()' Aloca n posições na memoria pra um vetor
    // Malloc() função de alocacao de memoria da lib stdlib.h
    // n >> quantidade de dados para alocar
    // sizeof(tipo_dado) >> tamanho de cada elemento(eu acho)

    if (notas == NULL)// caso a alocacao falhe malloc retorna null, um erro
    {
        printf("Alocacao falhou.");
        return 1;
    }

    pree_vet(notas, n);
    exib_vet(notas, n);
    float m = media(notas, n);
    float varia = var(notas, n);
    printf("\nMedia das notas: %.2f", m);
    printf("\nVariancia da turma: %.2f", varia);

    free(notas); // Libera a memória que não for mais usada


    return 0;
}

void pree_vet(float *notas, int quant)
{
    printf("Preencha o vetor: ");
    for (int i = 0; i < quant; i++)
    {
        scanf("%f", &notas[i]);
    }
}
void exib_vet(float *notas, int quant)
{
    printf("Exibir notas: ");
    for (int i = 0; i < quant; i++)
    {
        printf("%.2f ", notas[i]);
    }
}
float media(float *notas, int quant){
    float media = 0;
    for (int i = 0; i < quant; i++)
    {
        media += notas[i];
    }
    media /= (float)quant;
    return media;
    
}
float var(float *notas, int quant){
    float med = media(notas, quant);
    float var = 0;
    for (int i = 0; i < quant; i++)
    {
        var += (notas[i]-med)*(notas[i]-med);
    }
    return var/(float)quant;
    
}


