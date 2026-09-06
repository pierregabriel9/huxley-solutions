#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calcprim(int n, double raiz, int i)
{
    if (i > raiz)
    {
        return 1;
    }
    else
    {
        if (n % i == 0)
        {
            return 0;
        }
        else
        {
            i++;
            return calcprim(n, raiz, i);
        }
    }
}

int prim(int n)
{
    int r = calcprim(n, sqrt(n), 2);
    if (r == 1)
    {
        return n;
    }
    else
    {
        return prim(n + 1);
    }
}

int fat(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * fat(n - 1);
    }
}

double loop (int n, double soma, double fatorial, double primo, int i)
{
    i++;
    if (i == n)
    {
        fatorial = fat(i);
        primo = prim(i);
        soma += (fatorial / primo);
        printf("%d!/%0.lf\n", i, primo);
        return soma;
    }
    else
    {
        fatorial = fat(i);
        primo = prim(i);
        soma += (fatorial / primo);

        printf("%d!/%.0lf + ", i, primo);

        return loop(n, soma, fatorial, primo, i);
    }
}


int main() 
{
    int n;
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("0.00\n");
    }
    else
    {
        double resultado = loop(n, 0, 1, 1, 0);
        printf("%.2lf\n", resultado);
    }
	return 0;
}