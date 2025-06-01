// Aninhamento de structs

#include <stdio.h>
#include <math.h>

// struct Ponto utilizando typedef permitindo utilizar apenas 'Ponto' ao inves de 'struct ponto'
typedef struct ponto
{
    float x;
    float y;
} Ponto;

// struct Circulo utilizando typedef
typedef struct circulo
{
    Ponto centro; // o centro do circulo é uma struct ponto
    float raio;
} Circulo;

float distancia(Ponto *p1, Ponto *p2);           // distancia entre dois pontos
int centro_circunferencia(Circulo *c, Ponto *p); // se determinado Ponto esta dentro do circulo

int main()
{
    // crinado um Ponto
    Ponto p_qulquer;
    // acessando com '.' já que estamos trabalhando diretamnete com a struct
    p_qulquer.x = 1.0;
    p_qulquer.y = 2.0;

    // Criando um Circulo
    Circulo cir_qulquer;
    // '.' diretamnte na struct Circulo
    cir_qulquer.centro.x = 1.0;
    cir_qulquer.centro.y = 3.0;
    cir_qulquer.raio = 1.5;

    printf("O ponto x:%.2f, y:%.2f esta ", p_qulquer.x, p_qulquer.y);
    // '&' passagem dos **endereços** das structs
    if (centro_circunferencia(&cir_qulquer, &p_qulquer)) // se a função retorna um valor diferente de 0 então a condição é verdadeira
    {
        printf("dentro da circunferencia.\n");
    }
    else
    {
        printf("fora da circunferencia.");
    }

    return 0;
}
// passsamos o ponteiro para as structs como parametros
float distancia(Ponto *p1, Ponto *p2)
{
    // calcula a distância entre dois pontos
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
    // acessando os campos das structs com '->' porque aqui estamos trabalhando com ponteiro das structs
}

// passamos novamente um ponteiro para as structs
int centro_circunferencia(Circulo *c, Ponto *p)
{
    // caso a distância entre centro do circulo e o ponto qualquer for menor que o raio da circunferencia
    // a função retorna um valor maior que 0, ou seja um VERDADEIRO (TRUE)
    return distancia(&c->centro, p) < c->raio;
    // acessando os campos das structs com '->'
}