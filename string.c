#include <stdio.h>
#include <string.h>

int main()
{
    double notas[5][4];
    double media[5] = {0};

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            scanf("%lf", &notas[i][j]);
            media[i] += ((notas[i][j]) / 4);       
        }
    }
    
    for(int i = 0; i < 5; i++)
    {
        printf("Media[%i] = %lf\n", i + 1, media[i]);
    }

    return 0;
}