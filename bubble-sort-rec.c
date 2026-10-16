#include <stdio.h>

void printOrdenado(int nums[], int n, int i)
{
    if(i == n - 1)
    {
        printf("%d\n", nums[i]);
        return;
    }

    printf("%d ", nums[i]);

    printOrdenado(nums, n, i + 1);
}

void bubbleSort(int nums[], int i, int n)
{
    if(i == n)
    {
        return;
    }

    if(nums[i] > nums[i + 1])
    {
        int aux = nums[i];
        nums[i] = nums[i + 1];
        nums[i + 1] = aux; 
    }

    bubbleSort(nums, i + 1, n);
}

void sort(int nums[], int n)
{
    if(n == 0)
    {
        return;
    }

    bubbleSort(nums, 0, n - 1);

    sort(nums, n - 1);
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

    sort(nums, n);

    printOrdenado(nums, n, 0);
}