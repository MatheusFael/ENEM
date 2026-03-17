#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char nome[100];
    int idade;
    char cargo[100];
    int salario;
} Funcionario;

void cadastrar(Funcionario *f){
    printf("Fala o nome: ");
    scanf("%s", f->nome);
    printf("Fala a idade: ");
    scanf("%d", &f->idade);
    printf("Fala o salario: ");
    scanf("%d", &f->salario);
    printf("Fala o cargo: ");
    scanf("%s", f->cargo);
    printf("\n");
}

void buscar(Funcionario f[]){
    char nomeprabuscar[100];
    printf("Fala o nome pra buscar: ");
    scanf("%s", nomeprabuscar); 

    for (int i = 0; i < 2; i++){
        if (strcmp(nomeprabuscar, f[i].nome) == 0){
            printf("\nAchou!\n");
            printf("O funcionario %s tem %d anos, tem o cargo %s e ganha %d\n", f[i].nome, f[i].idade, f[i].cargo, f[i].salario);
        }
    }
}

int main(){
    Funcionario funcionarios[2];

    for (int i = 0; i < 2; i++){
        cadastrar(&funcionarios[i]);
    }

    buscar(funcionarios);

    return 0;
}
