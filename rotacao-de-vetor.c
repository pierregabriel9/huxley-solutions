#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void deslocar(int nums[], int array_novo[], int n, int desloc, int i)
{
    if(i == n)
    {
        return;
    }

    if(i + desloc <= n - 1)
    {
        array_novo[i + desloc] = nums[i];
    }
    else
    {
        array_novo[(i + desloc) % n] = nums[i];
    }

    deslocar(nums, array_novo, n, desloc, i + 1);
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

    int fator_deslocamento;
    scanf("%d", &fator_deslocamento);

    int array_novo[n];

    deslocar(nums, array_novo, n, fator_deslocamento, 0);

    for(int i = 0; i < n; i ++)
    {
        printf("%d ", array_novo[i]);
    }
}