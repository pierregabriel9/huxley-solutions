#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int doacao (int numero, char tipo)
{
    if (tipo == 'p' || tipo == 'P')
    {
        return numero * 10;
    }
    else
    {
        return numero * 16;
    }
}

int loop(int n, int qtd_total)
{
    if (n == 0)
    {
        return qtd_total;
    }
    else
    {
        int numero;
        char tipo;
        
        scanf("%d %c", &numero, &tipo);

        qtd_total += doacao(numero, tipo);

        return loop(n - 1, qtd_total);
    }
}


int main() 
{
    int total_capsulas = loop(7, 0);

    int xicaras = (total_capsulas * 2) / 7;

    printf("%d\n", total_capsulas);
    printf("%d\n", xicaras);

	return 0;
}