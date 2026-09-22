#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordenacao(double num[], int i)
{
    double aux;
    if(i == 4)
    {
        printf("%.2lf\n", num[0]);
        printf("%.2lf\n", num[1]);
        printf("%.2lf\n", num[2]);
        printf("%.2lf\n", num[3]);
        
        return;
    }
    else
    {
        if(num[0] > num[i])
        {
            aux = num[0];
            num[0] = num[i];
            num[i] = aux;
        }

        if(num[2] < num[i])
        {
            aux = num[2];
            num[2] = num[i];
            num[i] = aux;
        }

        if(num[1] < num[3])
        {
            aux = num[1];
            num[1] = num[3];
            num[3] = aux;
        }

        ordenacao(num, i + 1);
    }
}


int main()
{
    double num[4];
    scanf("%lf%lf%lf%lf", &num[0], &num[1], &num[2], &num[3]);

    ordenacao(num, 0);

	return 0;
}