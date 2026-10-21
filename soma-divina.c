#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void lerMatriz(int n, int i, int matriz[][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    return;
}

int main()
{
    int n;
    scanf("%d", &n);

    if(n == 0)
    {
        printf("Vazia\n");
        return 0;
    }

    int m1[n][n];
    lerMatriz(n, 0, m1);

    int m2[n][n];
    lerMatriz(n, 0, m2);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\n", m1[i][j] + m2[i][j]);
        }
    }

	return 0;
}