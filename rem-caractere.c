#include <stdio.h>
#include <string.h>

void remover(char palavra[], char caractere, char nova_palavra[], int tamanho, int i, int indice)
{
    if(i == tamanho)
    {
        nova_palavra[indice] = '\0';
        return;
    }

    if(palavra[i] != caractere)
    {
        nova_palavra[indice] = palavra[i];
        indice++;
    }

    remover(palavra, caractere, nova_palavra, tamanho, i + 1, indice);
}

int main()
{
    char palavra[50];
    scanf("%s", palavra);

    char caractere;
    scanf(" %c", &caractere);

    char nova_palavra[50];

    remover(palavra, caractere, nova_palavra, strlen(palavra), 0, 0);

    printf("%s\n", nova_palavra);
}