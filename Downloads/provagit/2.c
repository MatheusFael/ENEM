#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    notebook = 1,
    televisor = 2,
    smartphone = 3
} ESCOLHA;

typedef struct {
    char nome[100];
    int preco;
    ESCOLHA tipo;
    union {
        struct {
            int tela;
            int ram;
        } notebook;
        struct {
            int tela;
            char resolucao[100];
        } televisor;
        struct {
            char so[100];
        } smartphone;
    } info;
} Produto;

void cadastrar(Produto *p) {
    printf("Digite o nome: ");
    scanf(" %99[^\n]", p->nome);
    printf("Digite o preco: ");
    scanf("%d", &p->preco);
    printf("Digite o tipo (1-notebook, 2-televisor, 3-smartphone): ");
    scanf("%d", (int *)&p->tipo);

    if (p->tipo == notebook) {
        printf("Digite a tela (pol): ");
        scanf("%d", &p->info.notebook.tela);
        printf("Digite a ram (GB): ");
        scanf("%d", &p->info.notebook.ram);
    } else if (p->tipo == televisor) {
        printf("Digite a tela (pol): ");
        scanf("%d", &p->info.televisor.tela);
        printf("Digite a resolucao (HD/4K): ");
        scanf(" %99[^\n]", p->info.televisor.resolucao);
    } else if (p->tipo == smartphone) {
        printf("Digite o SO (Android/iOS): ");
        scanf(" %99[^\n]", p->info.smartphone.so);
    }
}

void imprimir(Produto p[]) {
    printf("\n--- PRODUTOS CADASTRADOS ---\n");
    for (int i = 0; i < 2; i++) {
        printf("Nome: %s | Preco: R$ %d | ", p[i].nome, p[i].preco);
        if (p[i].tipo == notebook) {
            printf("Tipo: Notebook | Tela: %d\" | RAM: %dGB\n", p[i].info.notebook.tela, p[i].info.notebook.ram);
        } else if (p[i].tipo == televisor) {
            printf("Tipo: Televisor | Tela: %d\" | Resolução: %s\n", p[i].info.televisor.tela, p[i].info.televisor.resolucao);
        } else if (p[i].tipo == smartphone) {
            printf("Tipo: Smartphone | SO: %s\n", p[i].info.smartphone.so);
        }
    }
}

int main() {
    Produto produtos[2];

    for (int i = 0; i < 2; i++) {
        printf("\nCadastro do Produto %d:\n", i + 1);
        cadastrar(&produtos[i]);
    }

    imprimir(produtos);

    return 0;
}