#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void achar_maior(int nums[], int **maior, int max, int i)
{
    if(i == max)
    {
        return;
    }

    if(nums[i] > **maior)
    {
        *maior = &nums[i];
    }

    achar_maior(nums, maior, max, i + 1);
}

void achar_menor(int nums[], int **menor, int max, int i)
{
    if(i == max)
    {
        return;
    }

    if(nums[i] < **menor)
    {
        *menor = &nums[i];
    }

    achar_menor(nums, menor, max, i + 1);
}

void ler(int nums[], int MAX, int i)
{
    if(i == MAX)
    {
        return;
    }
    
    scanf("%d", &nums[i]);

    ler(nums, MAX, i + 1);
}

int main()
{
    int MAX = 6;
    int nums[MAX];

    ler(nums, MAX, 0);

    int *menor = &nums[0];
    int *maior = &nums[0];

    achar_menor(nums, &menor, MAX, 0);
    achar_maior(nums, &maior, MAX, 0);

    printf("%d\n", *menor);
    printf("%d\n", *maior);

	return 0;
}