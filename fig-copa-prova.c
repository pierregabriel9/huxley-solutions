#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int foiComprada(int num, int compradas[], int i, int qtd_compradas)
{
    if(i == qtd_compradas)
    {
        return 0;
    }
    if(num == compradas[i])
    {
        compradas[i] = -1;
        return 1;
    }
    return foiComprada(num, compradas, i + 1, qtd_compradas);
}

void contarTotais(int compradas[], int qtd_compradas, int figs_totais, int i, int total)
{
    if(i > figs_totais)
    {
        printf("%d\n", figs_totais - total);
        return;
    }

    if(compradas[i] != -1 && foiComprada(i, compradas, 0, qtd_compradas))
    {
        total++;
    }

    contarTotais(compradas, qtd_compradas, figs_totais, i + 1, total);
}

void lerCompradas(int compradas[], int n, int i)
{
    if(i == n)
    {
        return;
    }

    scanf("%d", &compradas[i]);

    lerCompradas(compradas, n, i + 1);
}

int main()
{
    int fig_totais;
    scanf("%d", &fig_totais);

    int qtd_compradas;
    scanf("%d", &qtd_compradas);

    int compradas[qtd_compradas];

    lerCompradas(compradas, qtd_compradas, 0);

    contarTotais(compradas, qtd_compradas, fig_totais, 1, 0);

	return 0;
}