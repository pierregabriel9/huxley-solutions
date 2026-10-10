#include <stdio.h>
#include <string.h>

int contagem(char frase[], int tamanho, char anterior, int qtd, int i)
{
    if(i == tamanho)
    {
        return qtd;
    }

    if((frase[i] == ' ' && frase[i - 1] != anterior) || i == 0)
    {
        qtd++;
    }

    return contagem(frase, tamanho, anterior, qtd, i + 1);
}

int main()
{
    char frase[200];
    fgets(frase, 200, stdin);

    char anterior = ' ';

    int qtd = contagem(frase, strlen(frase), anterior, 0, 0);

    printf("%d\n", qtd);
}