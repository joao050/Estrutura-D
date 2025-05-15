// realizar a soma de números positivos utilizando o continue;

#include <stdio.h>
#include<math.h>

int primos(int num);// função utilizada no exercício

int main()
{

    int numbers[8];
    int soma = 0;

    printf("Preencha o vetor co valores positivos e negativos:");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (int ii = 0; ii < 8; ii++)
    {
        if (numbers[ii] < 0)
        {
            continue;
        }

        soma += numbers[ii];
    }

    printf("O resultado da soma dos numeros positivos: %d\n", soma);

    /*
    EXERCÍCIO:
    Implemente um programa em C que percorra um vetor de números
    inteiros e calcule a soma de todos os números primos presentes
    nele. Caso um número não seja primo, ele deve ser ignorado.
    Exiba o resultado da soma ao final da execução.
    */

    printf("Exercício.\n");

    int nums[8];
    int somas_p = 0;

    printf("Preencha o vetor com números inteiros: ");
    for (int j = 0; j < 8; j++)
    {
       scanf("%d", &nums[j]); 
    }

    for (int ii = 0; ii < 8; ii++)
    {
        if (primos(nums[ii])) // caso return 1
        {
            somas_p += nums[ii]; // somando primos
        }
        
    }
    printf("Resultado da soma dos numeros primos: %d\n", somas_p);
    
    
    return 0;
}

int primos(int num)
{
    if (num <=1) // os números 0 e 1 não são primos
    {
        return 0;
    }
    if (num == 2) // 2 é primo
    {
        return 1;
    }
    if (num % 2 == 0) // os multiplos de 2 não são primos
    {
        return 0;
    }

    for (int i = 3; i < sqrt(num); i+=2) // testa os números impares
    {
        if (num % i == 0)
        {
            return 0;
        }
        
    }

    return 1; // o número é primo
      
}