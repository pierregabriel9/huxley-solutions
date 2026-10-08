#include <stdio.h>

#define DADOS 4
#define ATRIBUTOS 6

void printFicha(int somas[], int prioridade[])
{
    printf("For = %d\n", somas[prioridade[0] - 1]);
    printf("Des = %d\n", somas[prioridade[1] - 1]);
    printf("Con = %d\n", somas[prioridade[2] - 1]);
    printf("Sab = %d\n", somas[prioridade[3] - 1]);
    printf("Int = %d\n", somas[prioridade[4] - 1]);
    printf("Car = %d\n", somas[prioridade[5] - 1]);
}

void lerPrioridades(int prioridade[], int i, int n)
{
    if(i == n)
    {
        return;
    }

    scanf("%d", &prioridade[i]);

    lerPrioridades(prioridade, i + 1, n);
}

void ordenar(int numero[], int i, int n, int fim)
{
    if(fim == 0)
    {
        return;
    }

    if(i == n - 1)
    {
        fim--;
        i = 0;
        ordenar(numero, i, n, fim);
    }
    else if(numero[i] < numero[i + 1])
    {
        int aux = numero[i];
        numero[i] = numero[i + 1];
        numero[i + 1] = aux;
    }

    ordenar(numero, i + 1, n, fim);
}

int lerNums(int i, int n, int numeros_rodada[])
{
    if(i == n)
    {
        ordenar(numeros_rodada, 0, DADOS, DADOS);

        return numeros_rodada[0] + numeros_rodada[1] + numeros_rodada[2];
    }

    scanf("%d", &numeros_rodada[i]);

    return lerNums(i + 1, n, numeros_rodada);
}

void guardarSomas(int somas[], int i, int n)
{
    if(i == n)
    {
        return;
    }

    int numeros_rodada[DADOS];
    somas[i] = lerNums(0, DADOS, numeros_rodada);

    guardarSomas(somas, i + 1, n);
}

int main()
{
    int somas[ATRIBUTOS] = {0};

    guardarSomas(somas, 0, ATRIBUTOS);

    ordenar(somas, 0, ATRIBUTOS, ATRIBUTOS);

    int prioridade[ATRIBUTOS];

    lerPrioridades(prioridade, 0, ATRIBUTOS);

    printFicha(somas, prioridade);

    return 0;
}