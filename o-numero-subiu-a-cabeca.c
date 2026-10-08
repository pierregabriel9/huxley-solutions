#include <stdio.h>

void contarIsolados(int nums[], int i, int qtd, int n)
{
    if(i == n)
    {
        printf("%d\n", qtd);
        return;
    }
    if(i - 1 < 0)
    {
        if(nums[i] > nums[n -1] && nums[i] > nums[i + 1])
        {
            qtd++;
        }
    }
    else if(i + 1 == n)
    {
        if(nums[i] > nums[i - 1] && nums[i] > nums[0])
        {
            qtd++;
        }
    }
    else
    {
        if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            qtd++;
        }
    }

    contarIsolados(nums, i + 1, qtd, n);
}

void lerNums(int numeros[], int i, int n)
{
    if(i == n)
    {
        return;
    }

    scanf("%d", &numeros[i]);

    lerNums(numeros, i + 1, n);
}

int main()
{
    int n;
    scanf("%d", &n);

    int numeros[n];

    lerNums(numeros, 0, n);

    contarIsolados(numeros, 0, 0, n);

	return 0;
}