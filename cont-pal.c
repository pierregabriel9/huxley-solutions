#include <stdio.h>
#include <string.h>

int contPalavras(char frase[], int n, int i, int qtd)
{
    if(i == n)
    {
        return qtd;
    }

    if(frase[i - 1] == ' ' && frase[i] != ' ')
    {
        qtd++;
    }
    
    return contPalavras(frase, n, i + 1, qtd);
}

int main()
{
    char frase[300];
    fgets(frase, 300, stdin);

    int qtd = contPalavras(frase, strlen(frase), 1, 0);

    printf("%d\n", qtd);
}