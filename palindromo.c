#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 256

void verificacao(char frase[], int n, int i)
{
    if(i >= n)
    {
        printf("SIM\n");
        return;
    }
    else
    {
        if(frase[i] == ' ')
        {
            verificacao(frase, n, i + 1);
            return;
        }
        else if(frase[n - 1] == ' ')
        {
            verificacao(frase, n - 1, i);
            return;
        }

        if(frase[i] < 97)
        {
            frase[i] += 32;
        }
        if(frase[n - 1] < 97)
        {
            frase[n - 1] += 32;
        }
        
        if(frase[i] != frase[n - 1])
        {
            printf("NAO\n");
            return;
        }
        else
        {
            verificacao(frase, n - 1, i + 1);
        }
    }
}

void verificaFrase(int i, int n)
{
    if(i == n)
    {
        return;
    }

    char frase[MAX];

    fgets(frase, MAX, stdin);

    verificacao(frase, strlen(frase) - 1, 0);

    verificaFrase(i + 1, n);
}

int main()
{
    int qtd_frases;
    scanf("%d", &qtd_frases);

    getchar();

    verificaFrase(0, qtd_frases);

	return 0;
}