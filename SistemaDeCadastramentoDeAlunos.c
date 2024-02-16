#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAM 2
#define MAX 4

typedef struct disciplinas_est {
    char codigo[7];
    char nome[50];
    float nota;
    float frequencia;
} disciplinas;

typedef struct alunos_est {
    char matricula[10];
    char nome[50];
    int quantidadeDisciplinas;
    disciplinas dados[MAX];

}alunos;

// bool IgualdadeDeStrings(char s1[], char s2[]){
//     int i=0;
    
//     while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
//         i++;
//     }
//     if(s1[i] == '\0' && s2[i] == '\0'){
//         return 1;
//     }else{
//         return 0;
//     }
// }

int main() {
    alunos prog[TAM];
    disciplinas dados[MAX];
    int opcao, tamanho;
    char pesquisarMatricula[10], pesquisarNome[50];
    
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
            for (int i = 0; i < TAM; i++) {
                printf("Preencha os dados do aluno %d.\n", i + 1);
                printf("Nome: ");
                fflush(stdin);
                fgets(prog[i].nome, sizeof(prog[i].nome), stdin);
                tamanho = strlen(prog[i].nome);
                if(tamanho > 0 && prog[i].nome[tamanho-1] == '\n'){
                    prog[i].nome[tamanho-1] = '\0';
                }
                
                printf("Matricula: ");
                scanf("%s", prog[i].matricula);
                
                printf("Quantidade de Disciplinas: ");
                scanf("%d", &prog[i].quantidadeDisciplinas);
                getchar();
                
                for(int j=0; j<=prog[i].quantidadeDisciplinas-1; j++){
                    printf("\nDisciplina %d do aluno %s:\n", j+1, prog[i].nome);
                    printf("Codigo da Disciplina: ");
                    scanf("%s", dados[j].codigo);
                    getchar();
                    
                    printf("Nome da Discplina: ");
                    fflush(stdin);
                    fgets(dados[j].nome, sizeof(dados[j].nome), stdin);
                    tamanho = strlen(dados[j].nome);
                    if(tamanho > 0 && dados[j].nome[tamanho-1] == '\n'){
                        dados[j].nome[tamanho-1] = '\0';
                    }
                    
                    printf("Nota do aluno na disciplina: ");
                    scanf("%f", &dados[j].nota);
                    getchar();
                    
                    printf("Frequencia do aluno na disciplina: ");
                    scanf("%f", &dados[j].frequencia);
                    getchar();
                }
                i++;
           }
            printf("\n");
            break;
            
        case 2:
            printf("Informe a matricula a ser pesquisada: ");
            scanf("%s", pesquisarMatricula);
            
            int encontrou = 0;
            
            for(int i=0; i<TAM; i++){
                if(strcmp(pesquisarMatricula, prog[i].matricula)){
                    printf("\nNome: %s", prog[i].nome);
                    printf("\nDisciplinas: \n");
                    for(int j=0; j<prog[i].quantidadeDisciplinas; j++){
                        printf("%s - %s | Nota: %.2f Frequencia: %.2f \n", dados[j].codigo, dados[j].nome, dados[j].nota, dados[j].frequencia);
                    }
                    encontrou = 1;
                    break;
                }
            }
            if(encontrou == 0){
                printf("Essa matricula nao foi cadastrada no sistema. Por favor realize o cadastro selecionando a opcao 1.\n");
            }
            printf("\n");
            break;
            
        case 3:
            printf("Informe o nome do aluno a ser pesquisado: ");
            fflush(stdin);
            fgets(pesquisarNome, sizeof(pesquisarNome), stdin);
            tamanho = strlen(pesquisarNome);
            if(tamanho > 0 && pesquisarNome[tamanho-1] == '\n'){
                pesquisarNome[tamanho-1] = '\0';
            }
            
            encontrou = 0;
            
            for(int i=0; i<TAM; i++){
                if(strcmp(pesquisarNome, prog[i].nome)){
                    printf("\nNome: %s", prog[i].nome);
                    printf("\nMatricula: %s", prog[i].matricula);
                    printf("\nDisciplinas: \n");
                    for(int j=0; j<prog[i].quantidadeDisciplinas; j++){
                        printf("%s - %s | Nota: %.2f Frequencia: %.2f \n", dados[j].codigo, dados[j].nome, dados[j].nota, dados[j].frequencia);
                    }
                    encontrou = 1;
                    break;
                }
            }
            if(encontrou == 0){
                printf("Esse nome nao foi cadastrada no sistema. Por favor realize o cadastro selecionando a opcao 1.\n");
            }
            printf("\n");
            
            break;
            
        case 4:
            printf("Lista de alunos cadastradados no sistema\n");
            for(int i=0; i<TAM; i++){
                printf("%d: %s\n", i+1, prog[i].nome);
            }
            printf("\n");
            
            break;
            
        case 5:
            printf("Alunos cadastradados no sistema e suas respectivas disciplinas\n");
            for(int i=0; i<TAM; i++){
                printf("%d: %s\n", i+1, prog[i].nome);
                printf("Disciplinas: %s - %s\n\n", dados[i].codigo, dados[i].nome);
            }
            printf("\n");
            
            break;
            
        case 6:
            printf("Saindo do sistema.");
            break;
            
    } //switch
    }while(opcao != 6);
    
    
    return 0;
}
















