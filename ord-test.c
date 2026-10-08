#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordenar(int numeros_rodada[], int i, int n, int fim)
{
    if(fim < 0)
    {
        return;
    }

    if(i == n)
    {
        fim--;
        i = 0;
    }
    else if(numeros_rodada[i] < numeros_rodada[i + 1])
    {
        int aux = numeros_rodada[i];
        numeros_rodada[i] = numeros_rodada[i + 1];
        numeros_rodada[i + 1] = aux;
    }

    ordenar(numeros_rodada, i + 1, n, fim);
}

int main()
{
    int nums[] = {4, 3, 2, 1};

    int j = 4;
    ordenar(nums, 0, j, j);

    int i = 0;
    int n = 4;

    while(i < n)
    {
        printf("%d ", nums[i]);
        i++;
    }
}