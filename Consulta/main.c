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

void cor(){
    int opc;
    printf("************************\n");
    printf("* 0 - Reset            *\n");
    printf("* 1 - Vermelho         *\n");
    printf("* 2 - Verde            *\n");
    printf("* 3 - Amarelo          *\n");
    printf("* 4 - Azul             *\n");
    printf("* 5 - Roxo             *\n");
    printf("* 6 - Ciano            *\n");
    printf("************************\n");
    printf("Escolha a cor: ");
    scanf("%d",&opc);
    system("clear");
    switch(opc){
        case 0:
            printf("\033[0m");
            break;
        case 1:
            printf("\033[1;31m");
            break;
        case 2:
            printf("\033[1;32m");
            break;
        case 3:
            printf("\033[1;33m");
            break;
        case 4:
            printf("\033[1;34m");
            break;
        case 5:
            printf("\033[1;35m");
            break;
        case 6:
            printf("\033[1;36m");
            break;
    }
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

_Bool consultar(int matricula){
    _Bool enc=false;
    idc = 0;
    
    while((idc<idg) && (enc == false)){
        if(matricula == turma[idc].matricula){
            enc = true; 
        }else{
            idc++;
        }
    }
    return enc;
}

void alterar(){
    system("clear");
    printf("***********************************\n");
    printf("*          Nome : %s         *\n",turma[idc].nome);
    printf("***********************************\n");
    printf("*            Matricula : %d       *\n",turma[idc].matricula);
    printf("*   Nota da prova 1: %f     *\n",turma[idc].nota1);
    printf("*   Nota da prova 2: %f     *\n",turma[idc].nota2);
    printf("***********************************\n");



}

void cadastrar(){
    char r;
    do{
        system("clear");
        printf("Digite a matricula: ");
        scanf("%d",&a.matricula);
        
        printf("Digite o nome: ");
        getchar(); // limpa o buffer do teclado
        fgets(a.nome, sizeof(a.nome), stdin);
        a.nome[strcspn(a.nome, "\n")] = '\0';
        
        printf("Digite a nota 1: ");
        scanf("%f",&a.nota1);
        printf("Digite a nota 2: ");
        scanf("%f",&a.nota2);
        
        turma[idg++]=a;
        
                printf("\nDeseja continuar cadastrando [s/n]: ");
        scanf(" %c",&r);
    }while((tolower(r)=='s')&&(idg<MAX));
}

void imprimir(){
    for (int i=0;i<idg;i++){
        printf("Matricula: %d \n", turma[i].matricula);
        printf("Nome: %s \n", turma[i].nome);
        printf("Nota 1: %.2f \n", turma[i].nota1);
        printf("Nota 2: %.2f \n", turma[i].nota2);
        printf("Media: %.2f \n\n",calcularMedia(a));
    }
    sleep(3);
}

void excluir(int matri) {
    int aux = -1;
    
    for(int i = 0; i < idg; i++) {
        if(matri == turma[i].matricula) {
            aux = i;
            break;
        }
    }
    
    if(aux != -1) {
        for(int i = aux; i < (idg - 1); i++) {
            turma[i] = turma[i + 1];
        }
        idg--;
        printf("Matricula excluida com sucesso \n");
    }else {
        printf("Matricula não encontrada... \n");
    }
}


void ordenarcrescente(){
    struct Aluno aux;
    
    for (int i = 0; i < (idg - 1); i++) {
        for (int y = i + 1; y < idg; y++) {
            if(turma[i].matricula > turma[y].matricula){
                aux = turma[i];
                turma[i] = turma[y];
                turma[y] = aux;
            }
        }
    }
    
    printf("Lista ordenada com sucesso!\n");
    sleep(3);
}

void ordenardecrescente(){
    struct Aluno aux;
    
    for (int i = 0; i < (idg - 1); i++) {
        for (int y = i + 1; y < idg; y++) {
            if(turma[i].matricula < turma[y].matricula) {
                aux = turma[i];
                turma[i] = turma[y];
                turma[y] = aux;
            }
        }
    }
    
    printf("Lista ordenada com sucesso!\n");
    sleep(3);
}

void main()
{
    setlocale(LC_ALL,"português");
    do{
        int proc;
        menu();
        printf("Escolha a opção desejada: ");
        scanf("%d",&op);
        system("clear");
        switch(op){
            case 1:
                cadastrar();
                break;
            case 2:
                printf("Digite a matrícula que você deseja consultar: ");
                scanf("%d",&proc);
                
                if(consultar(proc) == true){
                    printf("Matrícula encontrada!");
                    sleep(3);
                }else{
                    printf("Matrícula não encontrada!");
                    sleep(3);
                }
                break;
            case 3:
                printf("Digite a matricula que deseja altera:");
                scanf("%d",&proc);
            
                if(consultar(proc) == true){
                    alterar();
                    printf("Deseja altera a Nota 1 ou 2 [1 ou 2]");
                    scanf("%d",&op);
                        switch(op){
                    case 1:
                    printf("Digite o novo valor da nova nota 1:");
                    scanf("%f",&new1);
                    turma[idc].nota1 = new1;
                    break;
                    case 2:
                    printf("Digite o novo valor da nova nota 2:");
                    scanf("%f",&new2);
                    turma[idc].nota2 = new2;
                    break;
                    printf("Nota alterada com sucesso!");
                    sleep(3);
                }
                }else{
                    printf("Matricula não encontrada!");
                }
             break;       
            case 4:
                //excluir
                printf("Se atente ao número da matricula a ser excluida a seguir \n");
                imprimir();
                printf("Insira o número da matricula do aluno que deseja excluir (deve existir na lista mostrada): \n");
                scanf("%d", &proc);
                
                excluir(proc);
                break;
            case 5:
                ordenarcrescente();
                break;
            case 6:
                ordenardecrescente();
                break;
            case 7:
                imprimir();
                break;
            case 8:
                cor();
                break;
            default: 
                if (op!=9){
                    printf("Opção inválida!\n");
                    sleep(3);
                    break;
                }
        }
    }while(op!=9);
    system("clear");
    printf("Sistema finalizado com sucesso!");
}
