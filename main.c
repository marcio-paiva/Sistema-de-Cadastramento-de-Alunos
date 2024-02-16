#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Alunos.h"

#define NUM_ALUNOS 10

int main() {
    int id = 0, opcao;
    alunos *aluno;
    aluno = (alunos*) malloc(NUM_ALUNOS * sizeof(alunos));

    do{
    printf("Escolha uma das opcoes:\n");
    printf("[1] cadastrar aluno\n");
    printf("[2] pesquisar aluno por matricula\n");
    printf("[3] pesquisar aluno por nome\n");
    printf("[4] exibir lista de alunos \n");
    printf("[5] exibir relacao alunos/disciplina \n");
    printf("[6] sair\n\n");
    
    scanf("%d", &opcao);
    getchar();
    
    
    switch(opcao){
        case 1:
            printf("\nValor do ID: %d\n", id);
            CadastrarAlunos(aluno, id);
            id++;
            break;
        case 4:
            printf("Lista de alunos cadastradados no sistema\n");
            for(int i=0; i<NUM_ALUNOS; i++){
                printf("%d: %s\n", i, aluno[i].nome);
            }
            printf("\n");
            break;
    } //switch
    }while(opcao != 6);



    free(aluno);
    return 0;
}

