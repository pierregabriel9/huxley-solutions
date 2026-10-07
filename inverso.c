#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void leitura_print(int nums[], int n, int i)
{
    if(i == n)
    {
        return;
    }

    scanf("%d", &nums[i]);

    leitura_print(nums, n, i + 1);

    if(i == 0)
    {
        printf("%d\n", nums[i]);
    }
    else
    {
        printf("%d ", nums[i]);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    int nums[n];

    leitura_print(nums, n, 0);

	return 0;
}