// Utilizando a função principal (int main)
// Executando pelo terminal >> .\nome_do_arquivo.exe argumento1 argumento2 ... <<
// >> .\Aula5_0.exe <<

#include<stdio.h>
// passando parametros 'argc' (contador de argumentos) e 'argv' (vetor de argumentos) 
int main(int argc, char *argv[]){

    switch (argc)
    {
    case 1:
            printf("Quantidade de argumentos: %d\n", argc); // quantidade de argumentos
            printf("Argumento na posicao 0 do vetor argv: %s\n", argv[0]); // por padrão o primairo argumento é o path do arquivo
            printf("Nao foram passados nenhum argumento.\n"); // caso não for passado argumentos pra função
        break;
    default:
            printf("Quantidade de argumentos: %d\n", argc); // ...

            // percorre o vetor e exibe o conteudo em suas posições
            // todos são strings
            for (int i = 0; i < argc; i++)
            {
                printf("posicao %d - %s\n", i, argv[i]);
            }
        
        break;
    }

    return 0;
}

