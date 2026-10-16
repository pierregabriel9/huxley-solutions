#include <stdio.h>

void remover(int nums[], int n, int i, int alvo)
{
    if(i == n)
    {
        return;
    }
    if(i != alvo)
    {
        if(i == n - 1)
        {
            printf("%d\n", nums[i]);
        }
        else
        {
            printf("%d ", nums[i]);
        }
    }

    remover(nums, n, i + 1, alvo);
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

    remover(nums, n, 0, alvo);
}