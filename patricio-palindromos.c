#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LETRAS 50

void printfPal(char palindromo[][MAX_LETRAS], int n, int i)
{
    if(i == n)
    {
        return;
    }
    if(strcmp(palindromo[i], "0") != 0)
    {
        printf("%s\n", palindromo[i]);
    }

    printfPal(palindromo, n, i + 1);
}

int verificacao(char palavra[], int tamanho, int i)
{
    if(i == ((tamanho/2) + 1))
    {
        return 1;
    }
    if(palavra[i] != palavra[tamanho - i])
    {
        return 0;
    }

    return verificacao(palavra, tamanho, i + 1);
}

void lerPalavras(int i, int n, int pal, char palindromo[][MAX_LETRAS])
{
    if(i == n)
    {
        if(pal == 0)
        {
            printf("Nenhuma palavra palíndroma encontrada\n");
        }
        else
        {
            printfPal(palindromo, n, 0);
            printf("Total: %d\n", pal);
        }
        return;
    }

    char palavra[MAX_LETRAS];

    scanf("%s", palavra);

    if(verificacao(palavra, strlen(palavra) - 1, 0))
    {
        strcpy(palindromo[i], palavra);
        pal++;
    }
    else
    {
        strcpy(palindromo[i], "0");
    }

    lerPalavras(i + 1, n, pal, palindromo);
}

int main() 
{
    int n;
    scanf("%d", &n);

    char palindromos[n][MAX_LETRAS];

    lerPalavras(0, n, 0, palindromos);

	return 0;
}