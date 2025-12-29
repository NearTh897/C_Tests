#include <stdio.h>

int main() {

        int numero;
        
        printf("Digite um numero inteiro: ");
        scanf("%d", &numero);
        
        for(int i = 1; i <= 10; i++) {
            int resultado = numero * i;
            printf("%dx%d=%d\n", numero, i, resultado);
        }
            return 0;        
}
