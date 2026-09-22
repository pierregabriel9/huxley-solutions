#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int comparar(int mult_n1[], int mult_n2[], int total, int i, int j, int tam_n1, int tam_n2)
{
    if(i >= tam_n1)
    {
        return total;
    }
    else
    {
        if(j >= tam_n2)
        {
            return comparar(mult_n1, mult_n2, total, i + 1, 0, tam_n1, tam_n2);
        }
        else
        {
            if(mult_n1[i] == mult_n2[j])
            {
                total++;
            }
            return comparar(mult_n1, mult_n2, total, i, j + 1, tam_n1, tam_n2);
        }
    }
}

void loop(int n1, int n2, int mult_n1[], int mult_n2[], int i, int tam_n1, int tam_n2)
{
    if(i >= tam_n1 && i >= tam_n2)
    {
        int total = comparar(mult_n1, mult_n2, 0, 0, 0, tam_n1, tam_n2);
        printf("%d\n", total);
    }
    else
    {
        if(i < tam_n1)
        {
            mult_n1[i] = n1 * (i + 1);
        }
        if(i < tam_n2)
        {
            mult_n2[i] = n2 * (i + 1);
        }

        loop(n1, n2, mult_n1, mult_n2, i + 1, tam_n1, tam_n2);
    }
}

int main() 
{
    int n1, n2;

    scanf("%d%d", &n1, &n2);

    int tam_n1 = (49 / n1);
    int tam_n2 = (49 / n2);
    
    int multiplos_n1[tam_n1];
    int multiplos_n2[tam_n2];

    loop(n1, n2, multiplos_n1, multiplos_n2, 0, tam_n1, tam_n2);

	return 0;
}