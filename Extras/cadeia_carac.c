/*

  **** Cadeia de Caracteres ****

    Fundamental saber que:

    Cadeia de caracteres (strings) são basicamente vetores do tipo char, obrigatoriamente
    sempre tem que reservar a ultima posição para o caractere nulo '\0'.

    Exemplos
     char string[41]; >> pode receber até 40 caracteres o último tem que reservar pro '\0'
     char string[] = {'A','r','a','c','a','t','i','\0'};
     ou
     char string[] = "Aracati";

     basicamente >> string[0] = 'A' ; string[1] = 'r'; string[2] = 'a' .....

    Para imprimir uma cadeia de caracters devemos usar o especificador %s no printf.
    Basicamente ela imprime o vetor, posição por posição, até encontrar o '\0'.

    O mesmo especificador é utilizado para obter uma cadeia de caracteres (scanf("%s", string)).
    Não é nescessário o '&' pois a cadeia de caracters é um vetor e o nome da variavel
    representa o endereço da primeira posição do vetor. 

    Porém seu uso é limitado pq se o usuário digitar
    "Ola Mundo", ele só vai capturar "Ola" pq o '%s' só captura uma sequência de caracteres não brancos
    *Caracteres brancos(tipo o espaço, o enter, \t).


    ** Pra obter um caractere digitado pelo usuário é um pouco diferente dos tipos %d e %f,
    o especificador %c não pula os espaços em branco, então por exemplo se o usuário apertar um espaço antes
    de digitar o caractere ele vai capturar apenas o espaço '\n' (o enter digitado) e o caractere só será capturado em uma
    outra chamada do scanf:

    int num;
    scanf("%d", &num); >> o usuário digita um número e logo em seguida aperta enter;
    char carac;
    scanf ("%c", &carac); >> consequentimente ira receber o espaço digitado (enter) do scanf anterior
    char carac2;
    scanf("%c", &carac2); >> só aqui o usuário conseguiria digitar um caractere

    pra isso não ocorrer adicionamos um espaço antes do especificador:
    scanf(" %c", &carac);

*/

#include <stdio.h>
int main()
{

    // **Caracteres

    // erros de captura do tipo char
    int num;
    printf("D. Num: ");
    scanf("%d", &num); // o usuário digita um número e logo em seguida aperta enter;
    printf("D. Carac: ");
    char carac;
    scanf("%c", &carac); // consequentimente ira receber o espaço digitado (enter) do scanf anterior
    printf("D. Carac: ");
    char carac2;
    scanf("%c", &carac2); // aqui o usuário conseguiria digitar um caractere
    printf("Numero: %d\n", num);
    printf("Caractere 1: %c\n", carac);
    printf("Caractere 2: %c\n", carac2);

    // Corrigindo:
    printf("\n\nManeira certa:\n");

    // reutilizando as variaveis criadas anteriormente
    // Utilizando os espaçamento antes do especificador %c
    printf("D. Num: ");
    scanf("%d", &num);
    printf("D. Carac: ");
    scanf(" %c", &carac);
    printf("D. Carac: ");
    scanf(" %c", &carac2);
    printf("Saida:\n");
    printf("NUmero: %d\n", num);
    printf("Caractere 1: %c\n", carac);
    printf("Caractere 2: %c\n", carac2);

    // **** Strings (Cadeia de caracteres)


    // Depois de fazer alguma leitura de dados com scanf ele deixa um '\n' no buffer, o que gera aquele problema
    // na leitura do scanf ser "pulada" as vezes, então...

    // Lembra do 'fflush(stdin)' bom... não é uma maneira recomendada de limpar o buffer, psé...
    
    // Então o recomendado é ussar isso
    while (getchar() != '\n');
    // tem a função de limpar o buffer do teclado, ou seja, descartar todos os caracteres restantes
    // da entrada padrão (stdin) até encontrar um caractere de nova linha ('\n').(ChatGPT)
    
    // Obtendo nomes compostos >>
    char nome[81];
    printf("Digite seu nome:");
    scanf("%80[^\n]", nome);
    printf("Nome: %s", nome);

    /*
    por partes:
    1 - '%[...]' esse formato, dentro dele especificamos o que será capturado
    por exemplo: scanf("%[aeiou]", vet_caract) >> lê apenas as vogais.
    2 - Se o primeiro caractere for um acento circunflexo '^'
    tera um sentido de negação.
    3 - No caso onde utilizamos '%[^\n]' tera o seguinte efeito >>
    ** a leitura dos dados vai proseguir até encontrar o '\n' (quando a gente digita enter).
    4 - Outro ponto importante é o limite de caracteres que serão guardados **(scanf("%80[...]")**, caso não
    definir um limite e o usuário digitar mais de 80 caracteres havera uma "invasão" na memória,
    seignifica que os dados ocuparão uma memória que não foi reservada para eles e pode da problema...

    */

    // exemplos também no arquivo Aula9_1.c

    return 0;
}