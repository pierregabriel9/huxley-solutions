#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void preencherMatriz(int n, int matriz[n][n])
{
    int num = 1;

    for(int i = 0; i < n; i++)
    {
        num = 1;
        for(int j = 0; j < n; j++)
        {
            matriz[i][j] = num;
            num++;
        }
    }
}

int main()
{
    int n; scanf("%d", &n);

    int matriz[n][n];

    preencherMatriz(n, matriz);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j < i)
            {
                printf("  ");
            }
            else
            {
                if(j + 1 == n)
                {
                    printf("%d\n", matriz[i][j]);
                }
                else
                {
                    printf("%d ", matriz[i][j]);
                }
            }
        }
    }

	return 0;
}