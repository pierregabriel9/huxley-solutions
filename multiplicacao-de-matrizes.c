#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void formarMatrizResultado(int n, int m, int o, int m_a[][m], int m_b[][o], int resultado[][o])
{
    int linha = 0; 
    int coluna = 0;
    while(linha < n)
    {
        for(int i = 0; i < m; i++)
        {
            resultado[linha][coluna] += (m_a[linha][i] * m_b[i][coluna]);
        }

        if(coluna + 1 != o)
        {
            printf("%d ", resultado[linha][coluna]);
        }
        else
        {
            printf("%d\n", resultado[linha][coluna]);
        }

        coluna++;

        if(coluna == o)
        {
            linha++;
            coluna = 0;
        }
    }
}

void zerarMatriz(int linha, int coluna, int matriz[][coluna])
{
    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

void lerMatriz(int linha, int coluna, int matriz[][coluna])
{
    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main()
{
    int n, m, o;
    scanf("%d%d%d", &n, &m, &o);

    int matriz_a[n][m];
    lerMatriz(n, m, matriz_a);

    int matriz_b[m][o];
    lerMatriz(m, o, matriz_b);

    int matriz_resultado[n][o];
    zerarMatriz(n, o, matriz_resultado);

    formarMatrizResultado(n, m, o, matriz_a, matriz_b, matriz_resultado);

	return 0;
}