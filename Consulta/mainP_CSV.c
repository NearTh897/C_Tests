#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//┌────────────────────────────────────────┐
//│ 1. Sistema Operacional recebe o pedido |
//│ 2. Recebe a decisão do usuario         |
//│ 3. Verifica se o arquivo existe        │
//│ 4. Cria uma "ponte" (FILE*) para acesso│
//│ 5. Retorna um número interno           │
//│ 6. Prepara o buffer de leitura         │
//└────────────────────────────────────────┘
    // Variáveis para os dados lidos
    int matricula_lida;
    int opcao;
    char nome_lido[50]; 
    float nota_lida;

void menu(){
    printf("===================================\n"); 
    printf("||         MENU PRINCIPAL        ||\n");
    printf("===================================\n");
    printf("||                               ||\n");
    printf("||  1 - CADASTRAR                ||\n");
    printf("||  2 - LER                      ||\n");
    printf("||  3 - SAIR                     ||\n");
    printf("===================================\n");
    printf("Escolha a opção desejada: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            cadastrarCSV();
            break;
        case 2:
            lerCSV();
            break;
        case 3:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
    }
}

void cadastrarCSV(){
    FILE *arquivo = fopen("dados.CSV", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo dados.CSV!\n");
        return;
    }

    int matricula;
    char nome[50];
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

int main() {
    menu();
    return 0;
}