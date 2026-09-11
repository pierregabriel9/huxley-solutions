#include <stdio.h>
#include <math.h>

int coprimo(int a, int b)
{
    if (a == 1 && b == 1)
    {
        return 1;
    }
    else if (b == 0)
    {
        if (a == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return coprimo(b, a % b);
    }
}

int divisivel(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    else if ((a % b) == 0)
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
    if (num >= 10)
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

void loop(int i, double p1, char kc, double p2, char or, double k_diaria, double o_diaria, int dia_inicial)
{
    if (i > dia_inicial)
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
        p1 += k_diaria;
        p2 += o_diaria;

        if (kc == 'k')
        {
            if (prim(i, 2) == 1)
            {
                p1 += (k_diaria * 0.05);
            }

            int fatorial1 = fat(i);
            int soma1 = som(fatorial1, 0);

            if (prim(soma1, 2) == 1)
            {
                p1 += (p2 * 0.1);
                p2 *= 0.9;
            }
        }

        if (or == 'o')
        {
            int fatorial2 = fat(i);
            int soma2 = som(fatorial2, 0);
            int mdc2 = divisivel(o_diaria, soma2);

            if (mdc2 == 1)
            {
                p2 += 30;
            }

            if (coprimo(o_diaria, i) == 1)
            {
                p2 += (p1 * 0.1);
                p1 *= 0.9;
            }
        }
        
        loop(i + 1, p1, kc, p2, or, k_diaria, o_diaria, dia_inicial);
    }
}

int main()
{
    double dias, p1, p2;
    scanf("%lf%lf%lf", &dias, &p1, &p2);
    
    int dia_inicial = dias;
    double k_diaria = p1;
    double o_diaria = p2;

    loop(1, 0, 'k', 0, 'o', k_diaria, o_diaria, dia_inicial);

    return 0;
}