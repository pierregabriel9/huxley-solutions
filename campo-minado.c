#include <stdio.h>

void printarResultado(int n, int m, int matriz[][m])
{
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            if(matriz[i][j] != -1)
            {
                if(matriz[i + 1][j] == -1)
                {
                    matriz[i][j]++;
                }
                if(matriz[i][j + 1] == -1)
                {
                    matriz[i][j]++;
                }
                if(matriz[i - 1][j] == -1)
                {
                    matriz[i][j]++;
                }
                if(matriz[i][j - 1] == -1)
                {
                    matriz[i][j]++;
                }
                if(matriz[i - 1][j + 1] == -1)
                {
                    matriz[i][j]++;
                }
                if(matriz[i + 1][j + 1] == -1)
                {
                    matriz[i][j]++;
                }
                if(matriz[i + 1][j - 1] == -1)
                {
                    matriz[i][j]++;
                }
                if(matriz[i - 1][j - 1] == -1)
                {
                    matriz[i][j]++;
                }
            }
        }
    }

    char bomba = '*';

    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            if(matriz[i][j] != -1)
            {
                if(j != m - 2)
                {
                    printf("%d ", matriz[i][j]);
                }
                else
                {
                    printf("%d", matriz[i][j]);
                }
                
            }
            else
            {
                if(j != m - 2)
                {
                    printf("%c ", bomba);
                }
                else
                {
                    printf("%c", bomba);
                }
            }
        }
        printf("\n");
    }
}

void preencherMatriz(int n, int m, int matriz[][m])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

void lerMatriz(int n, int m, int matriz[][m])
{
    char simbolo;

    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            scanf(" %c", &simbolo);

            if(simbolo == '.')
            {
                matriz[i][j] = 0;
            }
            else
            {
                matriz[i][j] = -1;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    n += 2;
    m += 2;

    int matriz[n][m];

    preencherMatriz(n, m, matriz);

    lerMatriz(n, m, matriz);

    printarResultado(n, m, matriz);

    return 0;
}