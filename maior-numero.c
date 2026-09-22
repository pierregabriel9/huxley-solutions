#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int procura(int conjunto[], int maior, int i, int tamanho)
{
    if(i >= tamanho)
    {
        return maior;
    }
    else
    {
        if(conjunto[i] > maior)
        {
            maior = conjunto[i];
        }

        return procura(conjunto, maior, i + 1, tamanho);
    }
}

void loop(int i, int conjunto[])
{
    int num;
    scanf("%d", &num);

    if(num == 0)
    {
        int maior_num = procura(conjunto, 0, 0, i);
        printf("%d\n", maior_num);
    }
    else
    {
        conjunto[i] = num;

        loop(i + 1, conjunto);
    }
}

int main() 
{
    int conjunto[100];
    loop(0, conjunto);
	return 0;
}