#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int encontrarLivres(int x, int linha, int c, int poltronas[][c])
{
    int qtd = 0;

    for(int i = 0; i < c; i++)
    {
        if(0 != poltronas[linha][i])
        {
            qtd = 0;
        }
        else
        {
            qtd++;
        }
        if(qtd >= x)
        {
            break;
        }
    }

    if(qtd >= x)
    {
        return 1;
    }

    return 0;
}

void preencher(int f, int c, int poltronas[][c])
{
    for(int i = 0; i < f; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &poltronas[i][j]);
        }
    }
}

int main()
{
    int x, f, c;
    scanf("%d%d%d", &x, &f, &c);

    int poltronas[f][c];

    preencher(f, c, poltronas);

    int resultado = 0;

    for(int i = 0; i < f; i++)
    {
        if(encontrarLivres(x, i, c, poltronas))
        {
            resultado++;
        }
    }
    
    printf("%d\n", resultado);

	return 0;
}