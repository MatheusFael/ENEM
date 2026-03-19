#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[100];
    int nota1;
    int nota2;
} Aluno;

void rodar()
{
    printf("fale o nome pra buscar\n");
    char busca[100];
    scanf("%s", busca);
    FILE *ENTRADA = fopen("../entrada.txt", "r");
    Aluno alunos[100];
    int contador = 0;
    int achou = 0;
    while (fscanf(ENTRADA, " %99[^,],%d,%d", alunos[contador].nome, &alunos[contador].nota1, &alunos[contador].nota2) == 3)
    {
        contador++;
    }

    for (int i = 0; i < contador; i++)
    {
        if (strcmp(busca, alunos[i].nome) == 0)
        {
            achou = 1;
            printf("acho!\n");
            printf("1 - pra mudar o nome, 2- pra mudar o nota1, 3 - pra mudar nota2\n");
            int escolha;
            scanf("%d", &escolha);
            if (escolha == 1)
            {
                printf("FALA O NOME NOVO\n");
                scanf("%s", alunos[i].nome);
            }
            else if (escolha == 2)
            {
                printf("FALA O nota1 NOVO\n");
                scanf("%d", &alunos[i].nota1);
            }
            else if (escolha == 3)
            {
                printf("FALA O nota2 NOVO\n");
                scanf("%d", &alunos[i].nota2);
            }
        }
    }

    if (achou)
    {
        ENTRADA = fopen("../entrada.txt", "w");
        for (int i = 0; i < contador; i++)
        {
            fprintf(ENTRADA, "%s,%d,%d\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2);
        }
        fclose(ENTRADA);
    }
    else
    {
        printf("nao achou\n");
        fclose(ENTRADA);
    }
}

int main()
{

    rodar();

    return 0;
}
