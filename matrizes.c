#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define int long long

double resultado(int n, int m, int matriz[][m], int soma_total)
{
    int a = 0;

    for(int i = 0; i < n; i++)
    {
        a += matriz[i][0];
    }

    int b = 0;

    for(int i = 0; i < n; i++)
    {
        b += matriz[i][m - 1];
    }

    int c = 0;

    for(int i = 0; i < m; i++)
    {
        c += matriz[0][i];
    }

    int d = 0;

    for(int i = 0; i < m; i++)
    {
        d += matriz[n - 1][i];
    }

    int x = 0;

    int linha = 0;
    int coluna = 0;

    while(1)
    {
        x += matriz[linha][coluna];

        linha++;
        coluna++;

        if(linha > n - 1 || coluna > m - 1)
        {
            break;
        }
    }

    int y = 0;
    linha = n - 1;
    coluna = m - 1;

    while(1)
    {
        y += matriz[linha][coluna];

        linha--;
        coluna--;

        if(linha < 0 || coluna < 0)
        {
            break;
        }
    }

    return ((double) (soma_total - (x + y) + (a * b) - (c * d))) / (n * m);
}

signed main()
{
    int contador = 1;
    int soma = 0;
    int n;
    int m;

    while(1)
    {
        soma = 0;
        contador = 1;
        scanf("%lld%lld", &n, &m);

        if(n == 0 && m == 0)
        {
            break;
        }
        if(n == 0 || m == 0)
        {
            printf("0.00\n");
            continue;
        }

        int matriz[n][m];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                matriz[i][j] = contador;
                soma += matriz[i][j];
                contador++;
            }
        }

        printf("%.2lf\n", resultado(n, m, matriz, soma));
    }

	return 0;
}