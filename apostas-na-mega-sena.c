#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define colunas 10

int estaNoArray(int resultado, int apostas[][colunas], int linha)
{
    for(int j = 0; j < colunas; j++)
    {
        if(resultado == apostas[linha][j])
        {
            return 1;
        }
    }

    return 0;
}

void preencherApostas(int apostas[][colunas], int linhas)
{
    int atual;
    char separador;

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            scanf("%d%c", &atual, &separador);

            apostas[i][j] = atual;

            if(separador != ',')
            {
                break;
            }
        }
    }
}

void preencherMatriz(int apostas[][colunas], int linhas)
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            apostas[i][j] = 0;
        }
    }
}

int main()
{
    int linhas;
    scanf("%d", &linhas);

    int apostas[linhas][colunas];

    preencherMatriz(apostas, linhas);

    preencherApostas(apostas, linhas);

    int resultado[6];
    for(int i = 0; i < 6; i++)
    {
        scanf("%d", &resultado[i]);
    }

    int ganhadores = 0;
    int validade = 1;

    for(int i = 0; i < linhas; i++)
    {
        validade = 1;

        for(int j = 0; j < 6; j++)
        {
            if(!estaNoArray(resultado[j], apostas, i))
            {
                validade = 0;
                break;
            }
        }

        if(validade == 1)
        {
            ganhadores++;
        }
    }

    printf("Total de ganhadores: %d\n", ganhadores);

	return 0;
}