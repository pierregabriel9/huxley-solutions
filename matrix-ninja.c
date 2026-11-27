#include <stdio.h>

void imprimirCorreta(char mov, int l, int c, int matriz[][c])
{
    if(mov == 'V')
    {
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(j >= (c / 2))
                {
                    printf("%02d ", matriz[l - 1 - i][j]);
                }
                else
                {
                    printf("%02d ", matriz[i][j]);
                }
            }
            printf("\n");
        } 
    }
    else
    {
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(i >= (l / 2))
                {
                    printf("%02d ", matriz[i][c - 1 - j]);
                }
                else
                {
                    printf("%02d ", matriz[i][j]);
                }
            }
            printf("\n");
        }
    }
}

void lerMatriz(int l, int c, int matriz[][c])
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main()
{
    char corte;
    int l, c;

    scanf(" %c%d%d", &corte, &l, &c);

    int matriz[l][c];

    lerMatriz(l, c, matriz);

    imprimirCorreta(corte, l, c, matriz);

	return 0;
}