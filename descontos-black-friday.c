#include <stdio.h>

void calculo(double produtos[], int i, int descontos)
{
    if(i >= 10)
    {
        printf("%d\n", descontos);
        return;
    }
    else
    {
        scanf("%lf%lf", &produtos[i], &produtos[i + 1]);

        if(produtos[i] * 0.8 >= produtos[i + 1])
        {
            descontos++;
        }

        calculo(produtos, i + 2, descontos);
    }
}

int main() 
{
    double produtos[10];

    calculo(produtos, 0, 0);

	return 0;
}