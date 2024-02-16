#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Alunos.h"
    
void CadastrarAlunos(alunos *prog, int id){
    printf("Preencha os dados do aluno %d.\n", id + 1);
    printf("Nome: ");
    fflush(stdin);
    fgets(prog[id].nome, sizeof(prog[id].nome), stdin);
    int tamanho = strlen(prog[id].nome);
    if(tamanho > 0 && prog[id].nome[tamanho-1] == '\n'){
        prog[id].nome[tamanho-1] = '\0';
    }
    
    printf("Matricula: ");
    scanf("%s", prog[id].matricula);
    
    printf("Quantidade de Disciplinas: ");
    scanf("%d", &prog[id].quantidadeDisciplinas);
    getchar();
    
    for(int j=0; j<=prog[id].quantidadeDisciplinas-1; j++){
        printf("\nDisciplina %d do aluno %s:\n", j+1, prog[id].nome);
        printf("Codigo da Disciplina: ");
        scanf("%s", prog[id].dados[j].codigo);
        getchar();
        
        printf("Nome da Discplina: ");
        fflush(stdin);
        fgets(prog[id].dados[j].nome, sizeof(prog[id].dados[j].nome), stdin);
        tamanho = strlen(prog[id].dados[j].nome);
        if(tamanho > 0 && prog[id].dados[j].nome[tamanho-1] == '\n'){
            prog[id].dados[j].nome[tamanho-1] = '\0';
        }
        
        printf("Nota do aluno na disciplina: ");
        scanf("%f", &prog[id].dados[j].nota);
        getchar();
        
        printf("Frequencia do aluno na disciplina: ");
        scanf("%f", &prog[id].dados[j].frequencia);
        getchar();
    }
}