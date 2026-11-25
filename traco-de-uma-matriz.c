#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    printf("tr(A) = ");

    double matriz[n][n];
    double soma = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%lf", &matriz[i][j]);
            if(i == j)
            {   
                soma += matriz[i][j];
                if(i != n - 1)
                {
                    printf("(%.2lf) + ", matriz[i][j]);
                }
                else
                {
                    printf("(%.2lf)", matriz[i][j]);
                }     
            }
        }
    }

    printf(" = %.2lf\n", soma);

	return 0;
}