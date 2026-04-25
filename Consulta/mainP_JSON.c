// Importações de Bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <ctype.h>

// Defiinir Espaço Máximo de 50 Caracteres
#define MAX 50 //const MAX=50;

// Estrutura
struct Aluno{
    int matricula;
    char nome[MAX];
    float nota1;
    float nota2;
};

int op=0, idg=0, idc =0;
struct Aluno a;
struct Aluno turma[MAX];
float new1=0,new2=0;

float calcularMedia(struct Aluno a){
    return (a.nota1+a.nota2)/2;
}
// Importações de Bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <ctype.h>

// Defiinir Espaço Máximo de 50 Caracteres
#define MAX 50 //const MAX=50;

// Estrutura
struct Aluno{
    int matricula;
    char nome[MAX];
    float nota1;
    float nota2;
};

int op=0, idg=0, idc =0;
struct Aluno a;
struct Aluno turma[MAX];
float new1=0,new2=0;

float calcularMedia(struct Aluno a){
    return (a.nota1+a.nota2)/2;
}

void menu(){
    system("clear");
    printf("***********************************\n");
    printf("*          MENU PRINCIPAL         *\n");
    printf("***********************************\n");
    printf("*                                 *\n");
    printf("*   1 - CADASTRAR                 *\n");
    printf("*   2 - CONSULTAR                 *\n");
    printf("*   3 - ALTERAR                   *\n");
    printf("*   4 - EXCLUIR                   *\n");
    printf("*   5 - ORDENAR CRESCENTE         *\n");
    printf("*   6 - ORDENAR DECRESCENTE       *\n");
    printf("*   7 - IMPRIMIR                  *\n");
    printf("*   8 - COR DA TELA               *\n");
    printf("*   9 - FINALIZAR                 *\n");
    printf("*                                 *\n");
    printf("***********************************\n");
}
