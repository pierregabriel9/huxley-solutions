#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double valor(double itens[], double total, int i)
{
    if(i >= 7)
    {
        return total;
    }
    else
    {
        if(i == 0)
        {
            total += itens[0];
            return valor(itens, total, i + 1);
        }
        else
        {
            total += itens[i] * itens[i + 1];
            return valor(itens, total, i + 2);
        }    
    }
}

void calculo(double itens[], int i)
{
    if(i >= 7)
    {
        double total = valor(itens, 0, 0);
        printf("%.2lf\n", total);
        printf("%.2lf\n", total / 21);
    }
    else
    {
        scanf("%lf", &itens[i]);

        calculo(itens, i + 1);
    }
}

int main() 
{
    double itens[7];

    calculo(itens, 0);

	return 0;
}