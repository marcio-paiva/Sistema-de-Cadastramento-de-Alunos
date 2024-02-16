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
            printf("\n");
            break;
        case 2:
            if(BuscaMatricula(aluno, id) == 0){
                printf("Essa matricula nao foi cadastrada no sistema. Realize o cadastro selecionando a opcao 1.\n");
            }
            printf("\n");
            break;
        case 3:
            if(BuscaNome(aluno, id) == 0){
                printf("Esse nome nao foi cadastrada no sistema. Realize o cadastro selecionando a opcao 1.\n");
            }
            printf("\n");
            break;
        case 4:
            if(id > 0){
                printf("Lista de alunos cadastradados no sistema\n");
                for(int i=0; i<id; i++){
                    printf("%d: %s\n", i+1, aluno[i].nome);
                }
            }else{
                printf("Nenhum aluno cadastrado no sistema. Realize o cadastro selecionando a opcao 1.\n");
            }
            printf("\n");
            break;
        case 5:
            if(id > 0){
                printf("Alunos cadastradados no sistema e suas respectivas disciplinas\n");
                for(int i=0; i<id; i++){
                    printf("%d - Nome: %s\n", i+1, aluno[i].nome);
                    printf("Disciplinas: \n");
                    for(int j=0; j<aluno[i].quantidadeDisciplinas; j++){
                        printf("%s - %s\n", aluno[i].dados[j].codigo, aluno[i].dados[j].nome);
                    }
                printf("\n");
                }
            }else{
                printf("Nenhum aluno cadastrado no sistema. Realize o cadastro selecionando a opcao 1.\n");
            }
            printf("\n");    
            break;
            
        case 6:
            printf("Saindo do sistema.");
            break;
    } //switch
    }while(opcao != 6);

    free(aluno);
    return 0;
}

