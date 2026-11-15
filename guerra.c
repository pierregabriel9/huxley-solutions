#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printar(int n, int m, int tropas[][m])
{
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            if(j + 1 != m - 1)
            {
                printf("%d ", tropas[i][j]);
            }
            else
            {
                printf("%d\n", tropas[i][j]);
            }
        }
    }

    double soma_principal = 0;
    int qtd = 0;
    int i = 1;
    int j = 1;

    while(1)
    {
        soma_principal += tropas[i][j];

        qtd++;

        if(i + 1 == n - 1 || j + 1 == m - 1)
        {
            break;
        }

        i++;
        j++;
    }

    double soma_sec = 0;
    i = 1;
    j = m - 2;

    while(1)
    {
        soma_sec += tropas[i][j];

        if(i + 1 == n - 1 || j - 1 == 0)
        {
            break;
        }

        i++;
        j--;
    }

    soma_principal /= qtd;
    soma_sec /= qtd;

    printf("%.2lf\n", soma_principal);
    printf("%.2lf\n", soma_sec);
}

void executarAtaque(int x, int y, int D, int n, int m, int tropas[][m])
{
    tropas[x][y] -= D;

    D /= 2;

    tropas[x - 1][y] -= D;
    tropas[x][y - 1] -= D;
    tropas[x + 1][y] -= D;
    tropas[x][y + 1] -= D;
    tropas[x + 1][y + 1] -= D;
    tropas[x - 1][y + 1] -= D;
    tropas[x - 1][y - 1] -= D;
    tropas[x + 1][y - 1] -= D;

    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            if(tropas[i][j] < 0)
            {
                tropas[i][j] = 0;
            }
        }
    }
}

void preencherZeros(int n, int m, int tropas[][m])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            tropas[i][j] = 0;
        }
    }
}

void lerMatriz(int n, int m, int matriz[][m])
{
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int tropas[n + 2][m + 2];

    preencherZeros(n + 2, m + 2, tropas);
    lerMatriz(n + 2, m + 2, tropas);

    int qtd_ataques;
    scanf("%d", &qtd_ataques);

    int x, y, D;
    for(int i = 0; i < qtd_ataques; i++)
    {
        scanf("%d%d%d", &x, &y, &D);
        executarAtaque(x + 1, y + 1, D, n + 2, m + 2, tropas);
    }

    printar(n + 2, m + 2, tropas);

	return 0;
}