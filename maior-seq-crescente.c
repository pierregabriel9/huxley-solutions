#include <stdio.h>
#include <string.h>

int seq(int nums[], int n, int i, int qtd)
{
    if(i == n)
    {
        return qtd;
    }
    if(nums[i - 1] < nums[i])
    {
        qtd++;
    }
    else
    {
        return qtd;
    }
    
    return seq(nums, n, i + 1, qtd);
}

void maiorSeq(int nums[], int n, int i, int qtd)
{
    if(i == n)
    {
        printf("%d\n", qtd);
        return;
    }

    int seq_atual = seq(nums, n, i, 1);

    if(qtd < seq_atual)
    {
        qtd = seq_atual;
    }

    maiorSeq(nums, n, i + 1, qtd);
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

    maiorSeq(nums, n, 1, 0);
}