#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50 //const MAX=50;


//┌────────────────────────────────────────┐
//│ 1. Sistema Operacional recebe o pedido |
//│ 2. Recebe a decisão do usuario         |
//│ 3. Verifica se o arquivo existe        │
//│ 4. Cria uma "ponte" (FILE*) para acesso│
//│ 5. Retorna um número interno           │
//│ 6. Prepara o buffer de leitura         │
//└────────────────────────────────────────┘
    // Variáveis para os dados lidos
    int op=0, idg=0, idc =0;

    int matricula_lida;
    int opcao;
    char nome_lido[MAX]; 
    float nota_lida;



void menu(){
    printf("#################################\n"); 
    printf("#         MENU PRINCIPAL        #\n");
    printf("#################################\n");
    printf("#                               #\n");
    printf("#  1 - CADASTRAR                #\n");
    printf("#  2 - CONSULTAR                #\n");
    printf("#  3 - REMOVER                  #\n");    
    printf("#  4 - LER                      #\n");
    printf("#  5 - SAIR                     #\n");
    printf("#################################\n");
    printf("Escolha a opção desejada: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            cadastrarCSV();
            break;
        case 2:
            consultarCSV();
            break;
        case 3:
            removerCSV();
            break;
        case 4:
            lerCSV();
            break;
        case 5:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
    }
}

void cadastrarCSV(){
    FILE *arquivo = fopen("dados.CSV", "a"); // Abre o arquivo para escrita (modo "append")
    
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo dados.CSV!\n");
        return;
    }

    int matricula;
    char nome[MAX];
    float nota;
    
    printf("Digite a matrícula: ");
    scanf("%d", &matricula);
    
    printf("Digite o nome: ");
    getchar(); // Limpa o buffer do teclado
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha
    
    printf("Digite a nota: ");
    scanf("%f", &nota);
    
    fprintf(arquivo, "{\n");
    fprintf(arquivo, "  \"matricula\": %d,\n", matricula);
    fprintf(arquivo, "  \"nome\": \"%s\",\n", nome);
    fprintf(arquivo, "  \"nota\": %.2f\n", nota);
    fprintf(arquivo, "}\n");
    
    fclose(arquivo);
    
    printf("Dados salvos com sucesso em dados.CSV!\n");

                    printf("\nDeseja continuar cadastrando [s/n]: ");
        scanf(" %c",&r);
    while((tolower(r)=='s')&&(idg<MAX));

}


void lerCSV() {
    FILE *arquivo = fopen("dados.CSV", "r");
    
    if (arquivo == NULL) {
        printf("Arquivo dados.CSV não encontrado!\n");
        printf("Execute o exemplo 1 primeiro para criar o arquivo.\n");
        return;
    }
    
    
    char linha[200];  // Buffer 
    
    printf("\n--- Lendo o arquivo linha por linha ---\n");
    
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("Li: %s", linha);  
        
        if (strstr(linha, "matricula") != NULL) {
            sscanf(linha, "  \"matricula\": %d,", &matricula_lida);
            printf("  -> Mátrícula: %d\n", matricula_lida);
        }
        
        else if (strstr(linha, "nome") != NULL) {
            sscanf(linha, "  \"nome\": \"%[^\"]\",", nome_lido);
            printf("  -> Nome: %s\n", nome_lido);
        }
        
        else if (strstr(linha, "nota") != NULL) {
            sscanf(linha, "  \"nota\": %f", &nota_lida);
            printf("  -> Nota: %.2f\n", nota_lida);
        }
    }
    
    fclose(arquivo);
    
    printf("\n--- Dados recuperados do CSV ---\n");
    printf("Matrícula: %d\n", matricula_lida);
    printf("Nome: %s\n", nome_lido);
    printf("Nota: %.2f\n", nota_lida);
}

consultarCSV(){
    printf("Função de consulta ainda não implementada.\n");
}

removerCSV(){
    printf("Função de remoção ainda não implementada.\n");
}

int main() {
    menu();
    return 0;
}