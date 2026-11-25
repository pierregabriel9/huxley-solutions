#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int linha, coluna;
    scanf("%d%d", &linha, &coluna);

    int matriz[linha][coluna];

    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    int contador;
    int qtd = 0;
    scanf("%d", &contador);
    
    if(linha % 2 == 0)
    {
        for(int i = 0; i < linha; i++)
        {
            for(int j = 0; j < coluna; j++)
            {
                if(matriz[i][j] == 1 && contador > 0)
                {
                    matriz[i][j] = 0;
                    contador--;
                }
                else if(matriz[i][j] == 1 && contador <= 0)
                {
                    qtd++;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < coluna; i++)
        {
            for(int j = 0; j < linha; j++)
            {
                if(matriz[j][i] == 1 && contador > 0)
                {
                    matriz[j][i] = 0;
                    contador--;
                }
                else if(matriz[j][i] == 1 && contador <= 0)
                {
                    qtd++;
                }
            }
        }
    }

    for(int i = 0; i < linha; i++)
    {
        for(int j = 0; j < coluna; j++)
        {
            if(j + 1 != coluna)
            {
                printf("%d ", matriz[i][j]);
            }
            else
            {
                printf("%d\n", matriz[i][j]);
            }
        }
    }
    
    printf("%d %d\n", contador, qtd);

	return 0;
}