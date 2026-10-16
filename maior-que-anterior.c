#include <stdio.h>

int comparacao(int nums[], int n, int i, int qtd)
{
    if(i == n)
    {
        return qtd;
    }

    if(nums[i - 1] < nums[i])
    {
        qtd++;
    }

    return comparacao(nums, n, i + 1, qtd);
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

    int result = comparacao(nums, n, 1, 0);

    printf("%d\n", result);
}
