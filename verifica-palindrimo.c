#include <stdio.h>
#include <string.h>

void verificacao(char palavra[], int i, int tamanho)
{
    if(i == (tamanho/2) + 1)
    {
        printf("É palindromo\n");
        return;
    }
    if(palavra[i] != palavra[tamanho - 1 - i])
    {
        printf("Não é palíndromo\n");
        return;
    }

    verificacao(palavra, i + 1, tamanho);
}

int main()
{
    char palavra[50];
    scanf("%s", palavra);

    verificacao(palavra, 0, strlen(palavra));
}