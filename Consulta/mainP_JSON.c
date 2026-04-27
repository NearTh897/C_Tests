#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//┌────────────────────────────────────────┐
//│ 1. Sistema Operacional recebe o pedido │
//│ 2. Verifica se o arquivo existe        │
//│ 3. Cria uma "ponte" (FILE*) para acesso│
//│ 4. Retorna um número interno           │
//│ 5. Prepara o buffer de leitura         │
//└────────────────────────────────────────┘



void lerJSON() {
    FILE *arquivo = fopen("dados.json", "r");
    
    if (arquivo == NULL) {
        printf("Arquivo dados.json não encontrado!\n");
        printf("Execute o exemplo 1 primeiro para criar o arquivo.\n");
        return;
    }
    
    // Variáveis para os dados lidos
    int matricula_lida;
    char nome_lido[50]; 
    float nota_lida;
    
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
    
    printf("\n--- Dados recuperados do JSON ---\n");
    printf("Matrícula: %d\n", matricula_lida);
    printf("Nome: %s\n", nome_lido);
    printf("Nota: %.2f\n", nota_lida);
}

int main() {
    lerJSON();
    return 0;
}