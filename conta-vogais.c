#include <stdio.h>
#include <string.h>

#define MAX 150

void contVogais(char frase[], int n, int i, int qtd)
{
    if(i == n)
    {
        printf("%d\n", qtd);
        return;
    }
    if(frase[i] < 97)
    {
        frase[i] += 32;
    }
    if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u')
    {
        qtd++;
    }

    contVogais(frase, n, i + 1, qtd);
}

int main()
{
    char frase[MAX];
    fgets(frase, MAX, stdin);

    contVogais(frase, strlen(frase), 0, 0);
}