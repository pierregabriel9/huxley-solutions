#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double ingredientes[3][4];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            scanf("%lf", &ingredientes[i][j]);
        }
    }

    double produtos[4];
    
    for(int i = 0; i < 4; i++)
    {
        scanf("%lf", &produtos[i]);
    }

    double preco;

    for(int i = 0; i < 3; i++)
    {
        preco = 0;

        for(int j = 0; j < 4; j++)
        {
            preco += ingredientes[i][j] * produtos[j];
        }

        printf("%.2lf\n", preco);
    }

	return 0;
}