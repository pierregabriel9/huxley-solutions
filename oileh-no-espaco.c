#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void palavra(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        char letra;
        scanf(" %c", &letra);

        palavra(n - 1);

        printf("%c", letra);
    }
}

int soma(int numero, int total)
{
    if (numero < 10)
    {
        total += numero;
        return total;
    }
    else
    {
        total += numero % 10;
        return soma(numero / 10, total);
    }
}

void loop(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        int numero;
        scanf("%d", &numero);

        int somatorio = soma(numero, 0);

        palavra(somatorio);

        printf("\n");

        loop(n - 1);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    loop(n);

	return 0;
}