#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calc(int num, int qtd)
{
    if(num == 1 || num == 0)
    {
        qtd++;
        return qtd;
    }
    else
    {
        if(num % 2 == 0)
        { 
            qtd++;
            return calc(num / 2, qtd);
        }
        else
        {
            qtd++;
            return calc((3 * num) + 1, qtd);
        }
    }
}

int loopcalc(int n1, int n2, int qtd_atual, int qtd_maior)
{
    if(n1 == n2 + 1)
    {
        return qtd_maior;
    }
    else
    {
        qtd_atual = calc(n1, 0);

        if(qtd_atual > qtd_maior)
        {
            qtd_maior = qtd_atual;
        }

        loopcalc(n1 + 1, n2, qtd_atual, qtd_maior);
    }
}

void loop(int qtd)
{
    int n1, n2;
    int entradas = scanf("%d%d", &n1, &n2);
    
    if(n1 == 0 && n2 == 0)
    {
        return;
    }
    else if(entradas == 2)
    {
        if(n2 > n1)
        {
            qtd = loopcalc(n1, n2, 0, 0);
        }
        else
        {
            qtd = loopcalc(n2, n1, 0, 0);
        }

        printf("%d %d %d\n", n1, n2, qtd);
        loop(qtd);
    }
}

int main() 
{
    loop(0);

	return 0;
}