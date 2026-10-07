#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 10
#define MAIOR 1000

void frequencia(int nums[], int freq[], int alvo, int i)
{
    if(i == MAX)
    {
        printf("%d\n", freq[alvo]);
        return;
    }

    freq[nums[i]]++;

    frequencia(nums, freq, alvo, i + 1);
}

void ler(int nums[], int i)
{
    if(i == MAX)
    {
        return;
    }

    scanf("%d", &nums[i]);

    ler(nums, i + 1);
}

int main() 
{
    int nums[MAX];
    int freq[MAIOR + 1] = {0};

    ler(nums, 0);

    int alvo;
    scanf("%d", &alvo);

    frequencia(nums, freq, alvo, 0);

	return 0;
}