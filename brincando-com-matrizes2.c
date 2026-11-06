#include <stdio.h>

int main()
{
    double numeros[3][3];
    double media = 0;
    double soma = 0;
    int qtd_positivos = 0;
    int menor;


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%lf", &numeros[i][j]);

            if(i == 0 && j == 0)
            {
                menor = numeros[i][j];
            }

            if(numeros[i][j] > 0)
            {
                media += numeros[i][j];
                qtd_positivos++;
            }
            if(numeros[i][j] < menor)
            {
                menor = numeros[i][j];
            }
            if(i != j)
            {
                soma += numeros[i][j];
            }
        }
    }

    printf("%.2lf ", media/qtd_positivos);
    printf("%d ", menor);

    if(menor % 2 == 0)
    {
        printf("1 ");
    }
    else
    {
        printf("0 ");
    }
    printf("%.0lf\n", soma);

    return 0;
}