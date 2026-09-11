#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int coprimo(int a, int b)
{
    if (a % b == 1)
    {
        return 1;
    }
    else
    {
        if (a % b == 0)
        {
            return 0;
        }
        else
        {
            return coprimo(b, a % b);
        }
    }
}

int mdc(int a, int b)
{
    if ((a % b) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int som(int num, int soma)
{
    if (num / 10 >= 10)
    {
        soma += num % 10;
        return som(num / 10, soma);
    }
    else
    {
        soma += num;
        return soma;
    }
}

int fat(int dia)
{
    if (dia <= 1)
    {
        return 1;
    }
    else
    {
        return dia * fat(dia - 1);
    }
}


int prim(int dia, int i)
{
    if (dia == 0 || dia == 1)
    {
        return 0;
    }
    else if (i > sqrt(dia))
    {
        return 1;
    }
    else
    {
        if (dia % i == 0)
        {
            return 0;
        }
        else
        {
            return prim(dia, i + 1);
        }
    }
}

void loop(int i, double p1, char kc, double p2, char or, double k_diaria, double o_diaria)
{
    if (i == 0)
    {
        if (p1 > p2)
        {
            printf("Kcaj Ganhou!\n");
            printf("%.2lf\n", p1);
        }
        else
        {
            printf("Ordep Ganhou!\n");
            printf("%.2lf\n", p2);      
        }
    }
    else
    {
        if (kc == 'k')
        {
            if (prim(i, 2) == 1) //ok
            {
                p1 += (k_diaria * 1.05);
            }

            int fatorial1 = fat(i);
            int soma1 = som(fatorial1, 0);

            if (prim(soma1, 2) == 1) //ok
            {
                p1 += (p2 * 0.1);
                p2 *= 0.9;
            }
        }

        if (or == 'o')
        {
            int fatorial2 = fat(i);
            int soma2 = som(fatorial2, 0);
            int mdc2 = mdc(o_diaria, soma2);

            if (mdc2 == 1) //ok
            {
                p2 += 30;
            }

            if (coprimo(o_diaria, i) == 1) //ok
            {
                p2 += (p1 * 0.1);
                p1 *= 0.9;
            }
        }
        printf("%lf - p1\n", p1);
        printf("%lf - p2\n", p2);

        loop(i - 1, p1, kc, p2, or, k_diaria, o_diaria);
    }
}

int main()
{
    double dias, p1, p2;
    scanf("%lf%lf%lf", &dias, &p1, &p2);
    
    double k_diaria = p1;
    double o_diaria = p2;

    loop(dias, p1, 'k', p2, 'o', k_diaria, o_diaria);

    return 0;
}