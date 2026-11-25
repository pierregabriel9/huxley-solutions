#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double tabela[12][2];
    double custo_m0 = 0;
    double lucro_m0 = 0;
    double custo_m1 = 0;
    double lucro_m1 = 0;

    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%lf", &tabela[i][j]);
        }
    }

    double precos[2][2];

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%lf", &precos[i][j]);
        }
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            printf("Motor[%d], ", i);
            printf("Mes[%d], ", j + 1);
            if(i == 0)
            {
                custo_m0 += precos[i][0] * tabela[j][i];
                lucro_m0 += precos[i][1] * tabela[j][i];
                printf("custo=[%.2lf], ", precos[i][0] * tabela[j][i]);
                printf("lucro=[%.2lf]\n", precos[i][1] * tabela[j][i]);
            }
            else
            {
                custo_m1 += precos[i][0] * tabela[j][i];
                lucro_m1 += precos[i][1] * tabela[j][i];
                printf("custo=[%.2lf], ", precos[i][0] * tabela[j][i]);
                printf("lucro=[%.2lf]\n", precos[i][1] * tabela[j][i]);
            }
        }
    }
    printf("Motor[0], anual, custo=[%.2lf], lucro=[%.2lf]\n", custo_m0, lucro_m0);
    printf("Motor[1], anual, custo=[%.2lf], lucro=[%.2lf]\n", custo_m1, lucro_m1);
    
	return 0;
}