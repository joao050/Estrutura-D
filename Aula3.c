// Programa para converter altura em pés e polegadas
#include<stdio.h>
int main(){

    int pes;
    float altura, polegadas;

    printf("Digite sua altura em metros:");
    scanf("%f", &altura);

    //converter altura de metros para centimetros
    altura = altura * 100;

    pes = (int) (altura / 30.48); //calcula número de pés
    /*30.48 é definido como double. Nesse operação o resultado seria double, porém 
    pes recebe números inteiros então foi nescessário casting (int)*/

    polegadas = (altura - pes * 30.48) / 2.54; // calcula o número de polegadas

    printf("Altura convertida: %d pes e %.1f polegadas.", pes, polegadas);
    return 0;
}