/*
-- Crie uma struct para criar um cadastro de um aluno[nome, matricula, prova1, prova2, prova3, media]
-- implemente uma função que exibe somente os alunos aprovados(calcular a média das provas de cada aluno)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[81];
    char matricula[8];
    float prova1;
    float prova2;
    float prova3;
    float media;
} Aluno;

Aluno **cria_turma(int n);
void cadastra_alunos(Aluno **turma, int n_alunos);
float media(Aluno *al);
void exib_aprovados(Aluno **turma, int n_alunos);
void libera_turma(Aluno **turma, int n_alunos);
float media_turma(Aluno **turma, int n_alunos); // exercicío 6_4 do livro

int main()
{
    int n_alunos;
    printf("Quantos alunos na classe: ");
    scanf("%d", &n_alunos);
    getchar();

    Aluno **classe = cria_turma(n_alunos);
    cadastra_alunos(classe, n_alunos);

    exib_aprovados(classe, n_alunos);

    //exercício 6_4 do livro
    printf("\nMedia da turma: %.2f\n", media_turma(classe, n_alunos));

    libera_turma(classe, n_alunos);

    return 0;
}

Aluno **cria_turma(int n)
{
    Aluno **turma = (Aluno **)malloc(n * sizeof(Aluno *));
    if (!turma)
    {
        exit(1);
    }

    return turma;
}
float media(Aluno *al)
{
    float media = al->prova1 + al->prova2 + al->prova3;
    return media /= 3;
}
void cadastra_alunos(Aluno **turma, int n_alunos)
{
    for (int i = 0; i < n_alunos; i++)
    {
        turma[i] = (Aluno *)malloc(sizeof(Aluno));
        if (!turma[i])
        {
            for (int j = 0; j < i; j++)
            {
                free(turma[j]);
            }
            free(turma);
            exit(1);
        }

        printf("Aluno %d\n", i);
        printf("Informe>>");
        getchar();

        printf("Nome: ");
        fgets(turma[i]->nome, 81, stdin);
        turma[i]->nome[strcspn(turma[i]->nome, "\n")] = '\0';

        printf("Matricula: ");
        fgets(turma[i]->matricula, 8, stdin);
        turma[i]->matricula[strcspn(turma[i]->matricula, "\n")] = '\0';

        printf("Provas:\n");
        printf("Prova 1: ");
        scanf("%f", &turma[i]->prova1);
        printf("Prova 2: ");
        scanf("%f", &turma[i]->prova2);
        printf("Prova 3: ");
        scanf("%f", &turma[i]->prova3);
        getchar();

        turma[i]->media = media(turma[i]);
    }
}
void exib_aprovados(Aluno **turma, int n_alunos)
{
    printf("Alunos aprovados(media >= 7)>>>\n");
    for (int i = 0; i < n_alunos; i++)
    {
        if (turma[i]->media >= 7)
        {
            printf("Aluno %d: %s\n", i, turma[i]->nome);
        }
    }
}
void libera_turma(Aluno **turma, int n_alunos)
{
    for (int i = 0; i < n_alunos; i++)
    {
        free(turma[i]);
    }
    free(turma);
}
// exercicío 6_4 do livro
float media_turma(Aluno **turma, int n_alunos)
{
    float m_turma = 0;
    for (int i = 0; i < n_alunos; i++)
    {
        m_turma += turma[i]->media;
    }

    return m_turma /= n_alunos;
}