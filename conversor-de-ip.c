#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int conversor(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int soma, int i)
{
    if (i == 7)
    {
        soma += (pow(2, i) * n1);
        return soma;
    }
    else if (i == 0)
    {
        soma += (pow(2, i) * n8);
        return conversor(n1, n2, n3, n4, n5, n6, n7, n8, soma, i + 1);
    }
    else if (i == 1)
    {
        soma += (pow(2, i) * n7);
        return conversor(n1, n2, n3, n4, n5, n6, n7, n8, soma, i + 1);
    }
    else if (i == 2)
    {
        soma += (pow(2, i) * n6);
        return conversor(n1, n2, n3, n4, n5, n6, n7, n8, soma, i + 1);
    }
    else if (i == 3)
    {
        soma += (pow(2, i) * n5);
        return conversor(n1, n2, n3, n4, n5, n6, n7, n8, soma, i + 1);
    }
    else if (i == 4)
    {
        soma += (pow(2, i) * n4);
        return conversor(n1, n2, n3, n4, n5, n6, n7, n8, soma, i + 1);
    }
    else if (i == 5)
    {
        soma += (pow(2, i) * n3);
        return conversor(n1, n2, n3, n4, n5, n6, n7, n8, soma, i + 1);
    }
    else if (i == 6)
    {
        soma += (pow(2, i) * n2);
        return conversor(n1, n2, n3, n4, n5, n6, n7, n8, soma, i + 1);
    }
}

void loop(int n)
{
    if (n == 1)
    {
        int n1, n2, n3, n4, n5, n6, n7, n8;
        scanf("%d%d%d%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8);

        int num = conversor(n1, n2, n3, n4, n5, n6, n7, n8, 0, 0);
        printf("%d\n", num);

        return;
    }
    else
    {
        int n1, n2, n3, n4, n5, n6, n7, n8;
        scanf("%d%d%d%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8);

        int num = conversor(n1, n2, n3, n4, n5, n6, n7, n8, 0, 0);
        printf("%d.", num);

        loop(n - 1);
    }
}


int main() 
{
    loop(4);

	return 0;
}