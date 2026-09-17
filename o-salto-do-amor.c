#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int soma(int tronco, int total)
{
    if (tronco < 10)
    {
        total += tronco;
        return total;
    }
    else
    {
        total += tronco % 10;
        return soma(tronco / 10, total);
    }
}

int primo(int tronco, int i)
{
    if (tronco == 1 || tronco == 0)
    {
        return 0;
    }
    else if (i > sqrt(tronco))
    {
        return 1;
    }
    else
    {
        if (tronco % i == 0)
        {
            return 0;
        }
        else
        {
            return primo(tronco, i + 1);
        }
    }
}

int calcfibo(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return calcfibo(n - 1) + calcfibo(n - 2);
    }
}

int fibo(int tronco, int atual)
{
    if (tronco == calcfibo(atual) || tronco == 0)
    {
        return 1;
    }
    else if (tronco < calcfibo(atual))
    {
        return 0;
    }
    else
    {
        return fibo(tronco, atual + 1);
    }
}

void loop(int sapato, int n)
{
    if (n == 0)
    {
        printf("Muack!\n");
    }
    else
    {
        int tronco;
        scanf("%d", &tronco);

        if (sapato == 1)
        {
            if (fibo(tronco, 0) == 1)
            {
                loop(sapato, n - 1);
            }
            else
            {
                printf("Nhac!\n");
                return;
            }
        }
        else if (sapato == 2)
        {
            if (primo(tronco, 2) == 1)
            {
                loop(sapato, n - 1);
            }
            else
            {
                printf("Nhac!\n");
                return;
            }
        }
        else
        {
            if (soma(tronco, 0) % 2 == 0)
            {
                loop(sapato, n - 1);
            }
            else
            {
                printf("Nhac!\n");
                return;
            }
        }
    }
}


int main() 
{
    int sapato, n_troncos;
    scanf("%d%d", &sapato, &n_troncos);

    loop(sapato, n_troncos);

	return 0;
}