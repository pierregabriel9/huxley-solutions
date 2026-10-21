#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3];
    double media = 0;
    int maior;
    int diagonal = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &matriz[i][j]);

            if(i == 0 && j == 0)
            {
                maior = matriz[i][j];
            }

            media += matriz[i][j] / 9.0;

            if(i == j)
            {
                diagonal += matriz[i][j];
            }

            if(matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }
        }
    }

    printf("%.2lf %d ", media, maior);

    if(maior > 0)
    {
        printf("1 ");
    }
    else if(maior < 0)
    {
        printf("-1 ");
    }
    else
    {
        printf("0 ");
    }

    printf("%d\n", diagonal);

	return 0;
}