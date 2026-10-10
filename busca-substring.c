#include <stdio.h>
#include <string.h>

int busca(char frase[], int tamanho, char padrao[], int tamanho_padrao, int i, int j)
{
    if(i == tamanho)
    {
        return 0;
    }
    if(j == tamanho_padrao)
    {
        return 1;
    }

    if(frase[i] == padrao[j])
    {
        j++;
        i++;
    }
    else
    {
        j = 0;
        i++;
    }

    busca(frase, tamanho, padrao, tamanho_padrao, i, j);
}

int main()
{
    char frase[300];
    fgets(frase, 300, stdin);

    char padrao[100];
    scanf("%s", padrao);

    int validade = busca(frase, strlen(frase), padrao, strlen(padrao), 0, 0);

    if(validade == 1)
    {
        printf("Verdadeiro\n");
    }
    else
    {
        printf("Falso\n");
    }
}