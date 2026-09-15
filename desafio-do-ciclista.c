#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double calculo(char sexo, int idade)
{
    if (sexo == 'M')
    {
        if (idade >= 18 && idade <= 29)
        {
            return idade * 1.4;
        }
        else if (idade <= 49)
        {
            return idade * 1.2;
        }
        else
        {
            return idade;
        }
    }
    else
    {
        if (idade >= 18 && idade <= 29)
        {
            return idade * 1.2;
        }
        else if (idade <= 49)
        {
            return idade;
        }
        else
        {
            return idade * 0.9;
        }
    }
}


void loop(int n, int i)
{
    if (i - 1 == n)
    {
        return;
    }
    else
    {
        char sexo;
        int idade;
        double distancia;

        scanf(" %c%d%lf", &sexo, &idade, &distancia);

        double meta = calculo(sexo, idade);

        if (distancia >= meta)
        {
            printf("Ciclista %d: Atingiu a meta\n", i);
        }
        else
        {
            printf("Ciclista %d: Nao atingiu a meta\n", i);
        }

        loop(n, i + 1);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    loop(n, 1);

	return 0;
}