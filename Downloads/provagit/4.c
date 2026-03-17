#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    float n1;
    float n2;
} Aluno;

void modificar() {
    FILE *arq = fopen("entrada.txt", "r");
    if (arq == NULL) return;

    Aluno alunos[100];
    int total = 0;

    while (fscanf(arq, " %99[^,], %f, %f", alunos[total].nome, &alunos[total].n1, &alunos[total].n2) == 3) {
        total++;
    }
    fclose(arq);

    char busca[100];
    int achou = 0;
    printf("Nome para buscar: ");
    scanf(" %99[^\n]", busca);

    for (int i = 0; i < total; i++) {
        if (strcmp(alunos[i].nome, busca) == 0) {
            achou = 1;
            int opcao;
            printf("Alterar: 1-Nome, 2-Nota1, 3-Nota2: ");
            scanf("%d", &opcao);

            if (opcao == 1) {
                printf("Novo nome: ");
                scanf(" %99[^\n]", alunos[i].nome);
            } else if (opcao == 2) {
                printf("Nova Nota 1: ");
                scanf("%f", &alunos[i].n1);
            } else if (opcao == 3) {
                printf("Nova Nota 2: ");
                scanf("%f", &alunos[i].n2);
            }
        }
    }

    if (achou) {
        arq = fopen("entrada.txt", "w");
        for (int i = 0; i < total; i++) {
            fprintf(arq, "%s, %.1f, %.1f\n", alunos[i].nome, alunos[i].n1, alunos[i].n2);
        }
        fclose(arq);
        printf("Arquivo atualizado!\n");
    } else {
        printf("Não encontrado.\n");
    }
}

int main() {
    modificar();
    return 0;
}



/////



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar() {
    FILE *arquivo = fopen("../entrada.txt", "r+");
    if (arquivo == NULL) return;

    char nome_busca[50], linha[150];
    printf("Digite o nome para buscar: ");
    scanf(" %49[^\n]", nome_busca);

    long inicio_linha = ftell(arquivo);
    int encontrou = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[50];
        float n1, n2;

        if (sscanf(linha, " %49[^,], %f, %f", nome, &n1, &n2) == 3) {
            if (strcmp(nome, nome_busca) == 0) {
                encontrou = 1;
                int tam_antigo = strlen(linha);

                printf("Novo nome: ");
                scanf(" %49[^\n]", nome);
                printf("Nova Nota 1: ");
                scanf("%f", &n1);
                printf("Nova Nota 2: ");
                scanf("%f", &n2);


                fseek(arquivo, inicio_linha, SEEK_SET);

                char nova_linha[150];
                sprintf(nova_linha, "%s, %.1f, %.1f\n", nome, n1, n2);

                int novo_tam = strlen(nova_linha);
                while (novo_tam < tam_antigo) {
                    nova_linha[novo_tam - 1] = ' ';
                    nova_linha[novo_tam] = '\n';
                    nova_linha[novo_tam + 1] = '\0';
                    novo_tam++;
                }

                fputs(nova_linha, arquivo);
                fseek(arquivo, 0, SEEK_CUR);
                printf("Alteracao salva direto no original!\n");
                break;
            }
        }
        inicio_linha = ftell(arquivo);
    }
    fclose(arquivo);
    if (!encontrou) printf("Aluno nao encontrado.\n");
}

int main() {
    trocar();
    return 0;
}
