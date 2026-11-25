#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void gotasContinuas(int linha, int coluna, char matriz[][coluna])
{
    for(int i = 1; i < linha - 1; i++)
    {
        for(int j = 1; j < coluna - 1; j++)
        {
            if(matriz[i][j] == 'o' && matriz[i + 1][j] != '#')
            {
                matriz[i + 1][j] = 'o';
            }
        }
    }
}

void propagar(int coluna, int linha_atual, int coluna_atual, char matriz[][coluna])
{
    // direita
    int i = coluna_atual;

    while(matriz[linha_atual][i] == '#')
    {
        matriz[linha_atual - 1][i] = 'o';
        matriz[linha_atual - 1][i + 1] = 'o';
        i++;
    }

    int j = coluna_atual;

    while(matriz[linha_atual][j] == '#')
    {
        matriz[linha_atual - 1][j] = 'o';
        matriz[linha_atual - 1][j - 1] = 'o';
        j--;
    }
}

void preencherMatriz(int linha, int coluna, char matriz[][coluna])
{
    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            matriz[i][j] = '.';
        }
    }
}

void lerMatriz(int linha, int coluna, char matriz[][coluna])
{
    for(int i = 1; i < linha - 1; i++)
    {
        for(int j = 1; j < coluna - 1; j++)
        {
            scanf(" %c", &matriz[i][j]);
        }
    }
}

int main()
{
    int linha, coluna;
    scanf("%d%d", &linha, &coluna);
    linha += 2;
    coluna += 2;

    char matriz[linha][coluna];

    preencherMatriz(linha, coluna, matriz);

    lerMatriz(linha, coluna, matriz);

    for(int i = 1; i < linha - 1; i++)
    {
        for(int j = 1; j < coluna - 1; j++)
        {
            gotasContinuas(linha, coluna, matriz);

            if(matriz[i][j] == 'o' && matriz[i + 1][j] == '#')
            {
                propagar(coluna, i + 1, j, matriz);
            }
        }
    }

    for(int i = 1; i < linha - 1; i++)
    {
        for(int j = 1; j < coluna - 1; j++)
        {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

	return 0;
}