#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    printf("Digite a ordem N da matriz:\n");
    int n;
    scanf("%d", &n);
    int matriz[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                matriz[i][j] = 1;
            }
            else if(j > i)
            {
                matriz[i][j] = 10;
            }
            else
            {
                matriz[i][j] = -10;
            }


            printf("%-7d", matriz[i][j]);
        }
        printf("\n");
    }

	return 0;
}