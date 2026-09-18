#include <stdio.h>

long long int calcfibo(long long int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return calcfibo(n - 1) + calcfibo(n - 2);
    }
}

void fibo(long long int n, long long int i)
{
    if (i == n)
    {
        long long int num1 = calcfibo(i);
        long long int num2 = calcfibo(i - 1);

        printf("%lld\n", num1 - num2);
    }
    else
    {
        long long int num1 = calcfibo(i);
        long long int num2 = calcfibo(i - 1);

        printf("%lld ", num1 - num2);

        fibo(n, i + 1);
    }
}

void loop(int n)
{
    scanf("%d", &n);

    if (n == 0)
    {
        return;
    }
    else
    {
        fibo(n, 1);
        loop(n);
    }
}

int main()
{
    loop(1);
}