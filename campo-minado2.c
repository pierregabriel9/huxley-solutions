#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void preencherMatriz(int n, int m, char matriz[][m])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            matriz[i][j] = '.';
        }
    }
}

void lerMatriz(int n, int m, char matriz[][m])
{
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < m - 1; j++)
        {
            scanf(" %c", &matriz[i][j]);
        }
    }
}

int bombasAdjacentes(int i, int j, int m, char matriz[][m], int qtd)
{
    if(matriz[i - 1][j] == '*')
    {
        qtd++;
    }
    if(matriz[i - 1][j + 1] == '*')
    {
        qtd++;
    }
    if(matriz[i][j + 1] == '*')
    {
        qtd++;
    }
    if(matriz[i + 1][j + 1] == '*')
    {
        qtd++;
    }
    if(matriz[i + 1][j] == '*')
    {
        qtd++;
    }
    if(matriz[i + 1][j - 1] == '*')
    {
        qtd++;
    }
    if(matriz[i][j - 1] == '*')
    {
        qtd++;
    }
    if(matriz[i - 1][j - 1] == '*')
    {
        qtd++;
    }

    return qtd;
}

void printarNovaMatriz(int rodada, int n, int m, char matriz[][m])
{
    printf("Field #%d:\n", rodada);

    int qtd = 0;
    for(int i = 1; i < n - 1; i++)
    {
        qtd = 0;
        for(int j = 1; j < m - 1; j++)
        {
            if(matriz[i][j] != '*')
            {
                qtd = bombasAdjacentes(i, j, m, matriz, 0);

                printf("%d", qtd);
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    int contador = 1;
    while(!(n == 0 && m == 0))
    {
        if(contador != 1)
        {
            printf("\n");
        }

        n += 2;
        m += 2;

        char matriz[n][m];

        preencherMatriz(n, m, matriz);

        lerMatriz(n, m, matriz);

        printarNovaMatriz(contador, n, m, matriz);

        scanf("%d%d", &n, &m);

        contador++;
    }
    
	return 0;
}