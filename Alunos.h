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
} alunos;

void CadastrarAlunos(alunos *aluno, int id);