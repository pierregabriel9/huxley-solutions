#include <stdio.h>
#include <math.h>

double calc_var(double numeros[], double media, int i, double variancia)
{
    if (i == 10)
    {
        return variancia / 10;
    }
    else
    {
        variancia += pow(media - numeros[i], 2);
        return calc_var(numeros, media, i + 1, variancia);
    }
}

double calc_media(double numeros[], int i, double total)
{
    if (i == 10)
    {
        double media = total / 10;
        return calc_var(numeros, media, 0, 0);
    }
    else
    {
        total += numeros[i];
        return calc_media(numeros, i + 1, total);
    }
}

double calc_desvio(double numeros[])
{
    return sqrt(calc_media(numeros, 0, 0));
}

void ler_nums(double numeros[], int i)
{
    if(i == 10)
    {
        return;
    }
    else
    {
        double n;
        scanf("%lf", &n);

        numeros[i] = n;

        ler_nums(numeros, i + 1);
    }
}

int main()
{
    // Rodrigo falor para deixar mais na main

    double numeros[10];

    ler_nums(numeros, 0);

    printf("Desvio Padrão: %lf\n", calc_desvio(numeros));
}