#include <stdio.h>

int main() {
    int num, primeiro = 0, segundo = 1, proximo = 0, flag = 0;
    
    printf("Digite um número: ");
    scanf("%d", &num);
    
    if (num == 0 || num == 1) {
        printf("O número %d pertence à sequência de Fibonacci.", num);
        return 0;
    }
    
    while (proximo <= num) {
        if (proximo == num) {
            flag = 1;
            break;
        }
        proximo = primeiro + segundo;
        primeiro = segundo;
        segundo = proximo;
    }
    
    if (flag == 1) {
        printf("O número %d pertence à sequência de Fibonacci.", num);
    } else {
        printf("O número %d não pertence à sequência de Fibonacci.", num);
    }
    
    return 0;
}