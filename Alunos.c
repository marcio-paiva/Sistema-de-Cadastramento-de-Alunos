#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Alunos.h"
    
void CadastrarAlunos(alunos *aluno, int id){
    printf("Preencha os dados do aluno %d.\n", id + 1);
    printf("Nome: ");
    fflush(stdin);
    fgets(aluno[id].nome, sizeof(aluno[id].nome), stdin);
    int tamanho = strlen(aluno[id].nome);
    if(tamanho > 0 && aluno[id].nome[tamanho-1] == '\n'){
        aluno[id].nome[tamanho-1] = '\0';
    }
    
    printf("Matricula: ");
    scanf("%s", aluno[id].matricula);
    
    printf("Quantidade de Disciplinas: ");
    scanf("%d", &aluno[id].quantidadeDisciplinas);
    getchar();
    
    for(int j=0; j<=aluno[id].quantidadeDisciplinas-1; j++){
        printf("\nDisciplina %d do aluno %s:\n", j+1, aluno[id].nome);
        printf("Codigo da Disciplina: ");
        scanf("%s", aluno[id].dados[j].codigo);
        getchar();
        
        printf("Nome da Discplina: ");
        fflush(stdin);
        fgets(aluno[id].dados[j].nome, sizeof(aluno[id].dados[j].nome), stdin);
        tamanho = strlen(aluno[id].dados[j].nome);
        if(tamanho > 0 && aluno[id].dados[j].nome[tamanho-1] == '\n'){
            aluno[id].dados[j].nome[tamanho-1] = '\0';
        }
        
        printf("Nota do aluno na disciplina: ");
        scanf("%f", &aluno[id].dados[j].nota);
        getchar();
        
        printf("Frequencia do aluno na disciplina: ");
        scanf("%f", &aluno[id].dados[j].frequencia);
        getchar();
    }
}

int BuscaMatricula(alunos *aluno, int QTD){
    char pesquisarMatricula[10];
    printf("Informe a matricula a ser pesquisada: ");
    scanf("%s", pesquisarMatricula);

    for(int i=0; i<QTD; i++){
        if(strcmp(pesquisarMatricula, aluno[i].matricula) == 0){
            printf("\nNome: %s", aluno[i].nome);
            printf("\nDisciplinas: \n");
            for(int j=0; j<aluno[i].quantidadeDisciplinas; j++){
                printf("%s - %s | Nota: %.2f Frequencia: %.2f \n", aluno[i].dados[j].codigo, aluno[i].dados[j].nome, aluno[i].dados[j].nota, aluno[i].dados[j].frequencia);
            }
            return 1;
        }
    }
    return 0;
}

int BuscaNome(alunos *aluno, int QTD){
    char pesquisarNome[50];
    printf("Informe o nome do aluno a ser pesquisado: ");
    fflush(stdin);
    fgets(pesquisarNome, sizeof(pesquisarNome), stdin);
    int tamanho = strlen(pesquisarNome);
    if(tamanho > 0 && pesquisarNome[tamanho-1] == '\n'){
        pesquisarNome[tamanho-1] = '\0';
    }
    
    for(int i=0; i<QTD; i++){
        if(strcmp(pesquisarNome, aluno[i].nome) == 0){
            printf("\nNome: %s", aluno[i].nome);
            printf("\nMatricula: %s", aluno[i].matricula);
            printf("\nDisciplinas: \n");
            for(int j=0; j<aluno[i].quantidadeDisciplinas; j++){
                printf("%s - %s | Nota: %.2f Frequencia: %.2f \n", aluno[i].dados[j].codigo, aluno[i].dados[j].nome, aluno[i].dados[j].nota, aluno[i].dados[j].frequencia);
            }
            return 1;
        }
    }
    return 0;
}