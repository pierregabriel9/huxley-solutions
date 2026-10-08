#include <stdio.h>

void calc_fib(int n, int i, long long int nums[])
{
    if(i == n - 1)
    {
        printf("%lld\n", nums[2]);
        return;
    }

    nums[2] = nums[1] + nums[0];
    
    nums[0] = nums[1];
    nums[1] = nums[2];

    calc_fib(n, i + 1, nums);
}

int main()
{
    int n;
    scanf("%d", &n);

    if(n == 0)
    {
        printf("0\n");
        return 0;
    }
    if(n == 1)
    {
        printf("1\n");
        return 0;
    }

    long long int nums[3];
    nums[0] = 0;
    nums[1] = 1;

    calc_fib(n, 0, nums);

	return 0;
}