// usando break; para fazer uma busca eficiente

#include<stdio.h>
int main(){

    int nums[] = {1, 8, 4, 3, 9, 0, 5, 9};
    int tam = sizeof(nums) / sizeof(nums[0]);
    int procura;
    int encontrado = 0;
    printf("Procure um numero no vetor: ");
    scanf("%d", &procura);

    
    for (int i = 0; i < tam; i++)
    {
        if (nums[i] == procura)
        {
            printf("Numero %d foi encontrado na posicao %d\n",procura, i);
            encontrado = 1;
            break; // interronpe o loop assim que emcontra o primeiro numero
        }
        
    }
    if (!encontrado)
    {
        printf("Numero nao encontrado.\n");
    }

    encontrado = 0;
     
    /*
    EXERCÍCIO
    Implemente um programa em C que, dado um vetor ordenado de números inteiros,
    realize uma busca eficiente por um número fornecido pelo usuário. 
    Se o número estiver presente, exiba seu índice; caso contrário, informe 
    que ele não foi encontrado.
    */

    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("Qual numero procurar: ");
    scanf("%d", &procura);

    for (int j = 0; j < tam && vet[j] <= procura; j++) // em vetor ordenado a busca fica mais eficiente com essa condição
    {
        if (procura == vet[j])
        {
            printf("O numero %d foi encontrado na posicao %d\n", procura, j);
            encontrado ++;
            break;
        }
        
    }
    if (!encontrado)
    {
        printf("O numero não foi encontrado.\n");
    }
    
    


    return 0;
}
