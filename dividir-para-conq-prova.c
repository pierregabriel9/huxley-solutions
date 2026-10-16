#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void busca(int nums[], int alvo, int f, int i, int meio)
{
    if(i > f)
    {
        printf("Nao encontrado\n");
        return;
    }

    printf("%d %d\n", i, f);

    if(nums[meio] == alvo)
    {
        printf("Encontrado na posicao %d\n", meio);
        return;
    }

    if(alvo > nums[meio])
    {
        i = meio + 1;
    }
    else
    {
        f = meio - 1;
    }

    busca(nums, alvo, f, i, (i + f) / 2);
}

void lerNums(int nums[], int n, int i)
{
    if(i == n)
    {
        return;
    }
    scanf("%d", &nums[i]);

    lerNums(nums, n, i + 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];
    lerNums(nums, n, 0);

    int alvo;
    scanf("%d", &alvo);

    busca(nums, alvo, n - 1, 0, (n - 1) / 2);

	return 0;
}