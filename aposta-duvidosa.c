#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ehQuadradoMagico(int tamanho)
{
    int matriz[tamanho][tamanho];
    int linha = 0;
    int coluna = 0;
    int diagonal_p = 0;
    int diagonal_s = 0;

    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j < tamanho; j++)
        {
            scanf("%d", &matriz[i][j]);

            if(i == j)
            {
                diagonal_p += matriz[i][j];
            }
            if(i + j == tamanho - 1)
            {
                diagonal_s += matriz[i][j];
            }
        }
    }

    if(diagonal_p != diagonal_s)
    {
        return 0;
    }

    for(int i = 0; i < tamanho; i++)
    {
        linha = 0;

        for(int j = 0; j < tamanho; j++)
        {
            linha += matriz[i][j];
        }

        if(linha != diagonal_p)
        {
            return 0;
        }
    }

    for(int i = 0; i < tamanho; i++)
    {
        coluna = 0;
        
        for(int j = 0; j < tamanho; j++)
        {
            coluna += matriz[j][i];
        }

        if(coluna != diagonal_p)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int tamanho;
        scanf("%d", &tamanho);

        if(ehQuadradoMagico(tamanho))
        {
            printf("Eh quadrado magico!!!\n");
        }
        else
        {
            printf("Nao eh!!!\n");
        }
    }
	return 0;
}