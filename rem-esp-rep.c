#include <stdio.h>
#include <string.h>

void remover(char frase[], int tamanho, char nova_frase[], int i, int j)
{
    if(i == tamanho)
    {
        nova_frase[j] = '\0';
        return;
    }

    if(i == 0 && frase[i] != ' ')
    {
        nova_frase[j] = frase[i];
        j++;
    }
    else if(frase[i - 1] == ' ' && frase[i] != ' ')
    {
        if(j == 0)
        {
            nova_frase[j] = frase[i];
            j++;
        }
        else
        {
            nova_frase[j] = ' ';
            j++;

            nova_frase[j] = frase[i];
            j++;
        }
    }
    else if(frase[i - 1] != ' ' && frase[i] != ' ')
    {
        nova_frase[j] = frase[i];
        j++;
    }

    remover(frase, tamanho, nova_frase, i + 1, j);
}

int main()
{
    char frase[300];
    fgets(frase, 300, stdin);

    char nova_frase[300];

    remover(frase, strlen(frase), nova_frase, 0, 0);

    printf("[%s]\n", nova_frase);
}