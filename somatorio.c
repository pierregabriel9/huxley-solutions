#include <stdio.h>


int somatorio(int n, int soma)
{
    if (n >= 10)
    {
        soma += n % 10;
        return somatorio(n / 10, soma);
    }
    else
    {
        soma += n;
        return soma;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int soma = somatorio(n, 0);

    printf("%d\n", soma);

    return 0;
}