#include <stdio.h>
#include <string.h>

void inverte_string(char *str, int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }
    char temp = *(str + inicio); // salva o primeiro caractere
    *(str + inicio) = *(str + fim); // substitui o primeiro caractere pelo último
    *(str + fim) = temp; // substitui o último caractere pelo primeiro
    inverte_string(str, inicio + 1, fim - 1); // chama a função recursivamente com o intervalo e reduz em 1 as extremidade
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    scanf("%s", str);
    int tamanho = strlen(str);
    inverte_string(str, 0, tamanho - 1);
    printf("String invertida: %s\n", str);
    return 0;
}