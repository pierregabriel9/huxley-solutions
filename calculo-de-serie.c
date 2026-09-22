#include <stdio.h>
#include <math.h>

void calculo(int n, int i, int rodada_impar, double total)
{
    if(i == n)
    {
        printf("S: %.2lf\n", total);

        return;
    }
    else
    {
        if(i % 2 == 0)
        {
            total += (i + 1) / pow(2, i);
        }
        else
        {
            rodada_impar++;
            total += pow(2, i) / (3 * rodada_impar);
        }

        calculo(n, i + 1, rodada_impar, total);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    calculo(n, 0, 0, 0);

	return 0;
}