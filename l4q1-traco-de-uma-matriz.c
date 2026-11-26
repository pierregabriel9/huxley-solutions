#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    int m;
    scanf("%d%d", &n, &m);

    int matriz[n][m];
    int dp = 0;
    int ds = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);

            if(i == j && n == m)
            {
                dp += matriz[i][j];
            }
            if(i + j == n - 1 && n == m)
            {
                ds += matriz[i][j];
            }
        }
    }

    if(n != m)
    {
        printf("A matriz nao possui traco\n");
    }
    else
    {
        printf("%d\n", dp);
        printf("%d\n", ds);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(j + 1 != m)
            {
                printf("%d ", matriz[i][j]);
            }
            else
            {
                printf("%d\n", matriz[i][j]);
            }
        }
    }

	return 0;
}