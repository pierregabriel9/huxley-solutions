#include <stdio.h>
#include <string.h>

void comprimir(char letras[], char compress[], int n, int i, int j, int qtd)
{
    if(i == n)
    {
        compress[j] = '\0';
        return;
    }

    if(letras[i] != letras[i + 1] || i == n - 1)
    {
        compress[j] = letras[i];
        compress[j + 1] = qtd + '0';
        j += 2;
        qtd = 1;
    }
    else
    {
        qtd++;
    }

    comprimir(letras, compress, n, i + 1, j, qtd);
}

int main()
{
    char letras[100];
    scanf("%s", letras);

    char compress[100];

    comprimir(letras, compress, strlen(letras), 0, 0, 1);

    printf("%s\n", compress);
}