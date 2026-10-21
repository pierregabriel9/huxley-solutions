#include <stdio.h>
#include <math.h>

double calc_var(double numeros[], double media, int i, double variancia, int n)
{
    if (i == n)
    {
        return variancia / (n - 1);
    }
    else
    {
        variancia += pow(media - numeros[i], 2);
        return calc_var(numeros, media, i + 1, variancia, n);
    }
}

double calc_media(double numeros[], int i, double total, int n)
{
    if (i == n)
    {
        double media = total / (double) n;
        return calc_var(numeros, media, 0, 0, n);
    }
    else
    {
        total += numeros[i];
        return calc_media(numeros, i + 1, total, n);
    }
}

double calc_desvio(double numeros[], int n)
{
    return sqrt(calc_media(numeros, 0, 0, n));
}

void ler_nums(double numeros[], int i, int n)
{
    if(i == n)
    {
        return;
    }
    else
    {
        double num;
        scanf("%lf", &num);

        numeros[i] = num;

        ler_nums(numeros, i + 1, n);
    }
}

int main()
{
    // Rodrigo falor para deixar mais na main

    int n;
    scanf("%d", &n);

    double numeros[n];

    ler_nums(numeros, 0, n);

    printf("%.2lf\n", calc_desvio(numeros, n));
}