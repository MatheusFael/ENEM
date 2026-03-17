#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    float nota1;
    float nota2;
} Aluno;

int main() {
    int n = 2; 
    Aluno alunos[n];
    float somaMedias = 0;
    int aprovados = 0, reprovados = 0;

    for (int i = 0; i < n; i++) {
        printf("Nome do aluno %d: ", i + 1);
        scanf(" %99[^\n]", alunos[i].nome);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        
        float mediaIndividual = (alunos[i].nota1 + alunos[i].nota2) / 2.0;
        somaMedias += mediaIndividual;

        if (mediaIndividual >= 7.0) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    float mediaClasse = somaMedias / n;
    float percAprovados = ((float)aprovados / n) * 100;

    FILE *file = fopen("relatorio.txt", "w");
    if (file == NULL) {
        return 1;
    }

    fprintf(file, "Média da classe: %.2f\n", mediaClasse);
    fprintf(file, "Quantidade de aprovados: %d\n", aprovados);
    fprintf(file, "Quantidade de reprovados: %d\n", reprovados);
    fprintf(file, "Porcentagem de aprovados: %.2f%%\n", percAprovados);
    fclose(file);
    
    FILE *fileDados = fopen("dados.txt", "w");
    if (fileDados != NULL) {
        for(int i = 0; i < n; i++) {
            fprintf(fileDados, "%s, %.2f, %.2f\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2);
        }
        fclose(fileDados);
    }

    printf("\nRelatórios gerados com sucesso.\n");

    return 0;
}