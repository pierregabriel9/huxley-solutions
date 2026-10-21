#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000

int kgsQtd(char frutas[], int n, int qtd)
{
    for(int i = 0; i < n; i ++)
    {
        if(frutas[i] == ' ')
        {
            qtd++;
        }
    }

    return qtd;
}

int main()
{
    int n;
    scanf("%d", &n);

    int kg_frutas = 0;
    double valores = 0;

    for(int i = 0; i < n; i++)
    {
        double valor_atual;
        scanf("%lf", &valor_atual);
        getchar();

        valores += valor_atual;

        char frutas[MAX];
        fgets(frutas, MAX, stdin);

        kg_frutas += kgsQtd(frutas, strlen(frutas), 1);

        printf("dia %d: %d kg\n", i + 1, kgsQtd(frutas, strlen(frutas), 1));
    }

    printf("%.2lf kg por dia\n", kg_frutas / (double) n);
    printf("R$ %.2lf por dia\n", valores / (double) n);

	return 0;
}