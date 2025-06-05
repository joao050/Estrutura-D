// Deu trabai @-@

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// struct aluno contendo os dados do aluno, criado com typedef.
typedef struct aluno
{
    int matricula;
    char nome[81];
    char endereco[121];
    char telefone[21];
    int ativo;
} Aluno;

// Funções utilizadas
Aluno *cria_turma(int quant_alunos);
void adicionar_aluno(Aluno *vet_alunos, int position, int quant_alunos);
void remove_aluno(Aluno *vet_alunos, int position, int quant_alunos);
int aluno_ativo(Aluno *vet_alunos, int position);
void exibir_turma(Aluno *vet_alunos, int quant_alunos);
void menu();

int main()
{
    // Pergunta ao usuário a qunatidade de alunos.
    int n_alunos;
    printf("Quantos alunos tem nessa turma:");
    scanf("%d", &n_alunos);

    // aloca memória dinâmicamente para um vetor de structs aluno, utilizando uma função
    Aluno *alunos = cria_turma(n_alunos);
    // caso a alocação falhe a função retorna null
    if (alunos == NULL)
    {
        return 1;
    }

    int op;

    // repetição das tarefas, meio que uma interfa para interação
    do
    {
        // exibir o menu de opções
        menu();
        printf("Acao: ");
        scanf("%d", &op);
        int position;
        // casos para cada opção
        switch (op)
        {
        case 1:
            // adicionar um alunos
            printf("Adicionar aluno.\n");
            printf("Digite a posiao (0 a %d):", n_alunos - 1);
            scanf("%d", &position);
            // alunos aqui é um vetor então basta passar o primeiro elemento do vetor pra função
            adicionar_aluno(alunos, position, n_alunos);
            break;
        case 2:
            // retirar um aluno
            printf("Deseja retirar um aluno.\n");
            printf("Digite a posiao (0 a %d):", n_alunos - 1);
            scanf("%d", &position);
            remove_aluno(alunos, position, n_alunos);
            break;
        case 3:
            // exibir os dados de um aluno especéfico (deveria ter modularizado... vo nao )
            printf("Exibir dados do aluno.\n");
            printf("Digite a posição do aluno(0 a %d):", n_alunos-1);
            scanf("%d", &position);
            // 'aluno ativo()' uma função simples, bem besta, tá explicada no final
            if (aluno_ativo(alunos, position) == 1)
            {
                // como aqui estamos trabalhando com o struct diretamente acessamos os campos com ponto (.)
                printf("Nome do aluno: %s\n", alunos[position].nome);
                printf("Numero de matricula: %d\n", alunos[position].matricula);
                printf("Endereco: %s\n", alunos[position].endereco);
                printf("Numero de telefone: %s\n\n", alunos[position].telefone);
            }
            else
            {
                // quando não tem aluno na posiçao indicada
                printf("Nenhum aluno nessa posição...\n");
            }
            break;
        case 4:
            // exibir alunos ;-;
            exibir_turma(alunos, n_alunos);
            break;

        default:
            break;
        }
        // se o usuário vacilar na digitação da opção (sei que vao digitar errado só pra testar -_-)
        if (op < 0 || op > 4)
        {
            printf("Opção invalida.");
        }

    } while (op != 0);
    // fim do loop, quando o usuário digitar 0

    printf("Fim do programa...");

    // libera a memória que foi alocada 
    free(alunos);

    return 0;
}

// simples menu
void menu()
{
    printf("---Menu---\n");
    printf("0 - Encerrar\n");
    printf("1 - Adicionar aluno\n");
    printf("2 - Retirar aluno\n");
    printf("3 - Exibir dados do aluno\n");
    printf("4 - Exibir turma\n\n");
}

// Função para criar um vetor com aloção dinâmica, perceba que ela retorna um vetor então o ponteiro(*)
Aluno *cria_turma(int quant_alunos)
{
    // criando o vetor
    Aluno *turma = malloc(quant_alunos * sizeof(Aluno));
    if (!turma)
    {
        printf("Falha na alocacao de memoria!!");
        return NULL;
        // deu errado, retorna null
    }

    // aqui inicializamos o campo 'ativo" de todos os alunos com 0, indicando que na posição não tem um aluno registrado
    for (int i = 0; i < quant_alunos; i++)
    {
        turma[i].ativo = 0;
    }

    // retornamos o vetor criado
    return turma;
}
// função para verificar se tem um aluno em tal posição, simples
int aluno_ativo(Aluno *vet_alunos, int position)
{
    // Retorna 1 se o campo "ativo" do aluno na posição for igual a 1, senão 0
    return vet_alunos[position].ativo == 1 ? 1 : 0;
}
// Função que adiciona um aluno ne posição determinada pelo usuário
// trabalhando com ponteiros para um vetor de alunos mas acesamos os campos com ponto(.)
void adicionar_aluno(Aluno *vet_alunos, int position, int quant_alunos) 
{
    // condição que verifica se pelomenos o caba digitou uma posição aceitável
    if (position < 0 || position >= quant_alunos)
    {
        printf("Posição fora do intervalo de posicoes.\n");
        return;
    }
    // 'aluno_ativo()' trabalhando, se em tal posição aluno estiver inativo '0' então adiciona um aluno
    if (aluno_ativo(vet_alunos, position) == 0)
    {
        printf("Matricula: ");
        scanf("%d", &vet_alunos[position].matricula);
        // limpando o buffer
        while (getchar() != '\n');
        // obtendo os dados
        printf("Nome: ");
        fgets(vet_alunos[position].nome, 81, stdin); // obtendo os dados com fgets(melhor que com scanf())
        vet_alunos[position].nome[strcspn(vet_alunos[position].nome, "\n")] = '\0';
        // bagui mei doido mas ele so encontra o '\n' digitado pelo usuário e substitui por '\0'(fim da string)
        printf("Endereco: ");
        fgets(vet_alunos[position].endereco, 121, stdin);
        vet_alunos[position].endereco[strcspn(vet_alunos[position].endereco, "\n")] = '\0';
        printf("Telefone: ");
        fgets(vet_alunos[position].telefone, 21, stdin);
        vet_alunos[position].telefone[strcspn(vet_alunos[position].telefone, "\n")] = '\0';

        // não pode esquecer de atualizar o campo ativo do aluno
        vet_alunos[position].ativo += 1;

        printf("Aluno adicionado.\n");
    }
    else
    {
        // se a posição estiver como ativo (1) não pode só colocar um novo aluno porriba
        printf("\nPosicao ja esta ocupada\n");
        printf("Para adicionar um aluno nessa posicao e nescessario remover o aluno da posicao atual.\n\n");
    }
    
}
// função que remove o aluno
void remove_aluno(Aluno *vet_alunos, int position, int quant_alunos)
{
    // (deveria ter modularizado... vo nada)
    if (position < 0 || position >= quant_alunos)
    {
        printf("Posição fora do intervalo de posicoes.\n");
        return;
    }
    // se tiver um aluno na posição indicada (ativo = 1) remove aluno
    if(aluno_ativo(vet_alunos, position) == 1)
    {
        vet_alunos[position].ativo -= 1; // alterando o campo ativo
        memset(&vet_alunos[position], 0, sizeof(Aluno)); // rapaz, gpt recomendou isso
        // "Apaga o conteúdo dos campos da struct, limpando os dados antigos.
        // evita que o programa mostre informações de um aluno já removido."
        printf("Aluno removido\n");
    }
    else
    {
        // se a posição já não tinha alunos né
        printf("\nPosicao ja esta vazia.\n");
        printf("Voce pode adicionar um aluno.\n\n");
    }
    
}
// exibir os alunos
void exibir_turma(Aluno *vet_alunos, int quant_alunos)
{
    printf("\n>>>>Alunos<<<<\n");
    for (int i = 0; i < quant_alunos; i++)
    {
        if (aluno_ativo(vet_alunos, i) == 1)
        {
            printf("%d. %s", i, vet_alunos[i].nome);
        }
        else
        {
            printf("%d. \"vazio\"", i);
        }
        printf("\n");
    }
    
}