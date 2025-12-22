#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

int main() {
    // Configura o gerador de números aleatórios
    srand(time(0));

    int numerosecreto = rand() % 50 + 1;
    int pontos = 100;
    int theo = 1234;  // Segredo do criador
    int chute;
    int acertou = 0;  // 0 = não acertou, 1 = acertou

    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    // Loop principal com 4 tentativas (1 inicial + 3 no loop)
    for(int i = 0; i < 4; i++) {
        if(i == 0) {
            printf("Qual é o seu chute? De 1 a 50: ");
        } else {
            printf("Tentativa %d de 3 - Qual é o seu chute? ", i);
        }
        
        scanf("%d", &chute);
        printf("Seu chute foi: %d\n", chute);

        // Verifica se é o segredo do criador
        if (chute == theo) {
            printf("Ops! Você me achou. Criador: Theo\n");
            printf("      _______________\n");
            printf("    |@@@@|     |####|\n");
            printf("    |@@@@|     |####|\n");
            printf("    |@@@@|     |####|\n");
            printf("    \\@@@@|     |####/\n");
            printf("     \\@@@|     |###/\n");
            printf("      `@@|_____|##'\n");
            printf("           (O)\n");
            printf("        .-'''''-.\n");
            printf("      .'  * * *  `.\n");
            printf("     :  *       *  :\n");
            printf("    : ~ A S C I I ~ :\n");
            printf("    : ~ A W A R D ~ :\n");
            printf("     :  *       *  :\n");
            printf("jgs   `.  * * *  .'\n");
            printf("        `-.....-'\n");
            
            printf("O número secreto era: %d\n", numerosecreto);
            break;
        }

        // Verifica se é número negativo
        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            i--;  // Não conta esta tentativa
            continue;
        }

        // Verifica se acertou o número secreto
        if (chute == numerosecreto) {
            printf("Parabéns! Você ACERTOU!\n");
            printf("O número secreto era: %d\n", numerosecreto);
            
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n");
            
            acertou = 1;
            break;
        } 
        else {
            // Se errou, dá dica e calcula pontos
            printf("Você ERROU! ");
            
            if(chute > numerosecreto) {
                printf("Seu chute foi MAIOR que o número secreto.\n");
            } else {
                printf("Seu chute foi MENOR que o número secreto.\n");
            }
            
            int pontosperdidos = abs(chute - numerosecreto) / 2;
            pontos = pontos - pontosperdidos;
            printf("Pontos perdidos: %d | Pontos restantes: %d\n\n", pontosperdidos, pontos);
        }
    }

    // Mensagem final se não acertou
    if (!acertou && chute != theo) {
        printf("\nVocê perdeu! O número secreto era: %d\n", numerosecreto);
        printf("Total de pontos finais: %d\n", pontos);
    }

    return 0;
}