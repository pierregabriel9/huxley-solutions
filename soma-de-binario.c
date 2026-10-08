#include <stdio.h>

void printResult(int result[], int i, int n)
{
    if(i == n)
    {
        return;
    }

    if(i != n - 1)
    {
        printf("%d ", result[i]);
    }
    else
    {
        printf("%d\n", result[i]);
    }

    printResult(result, i + 1, n);
}

void concatenar(int n1[], int n2[], int result[], int n, int n_copia)
{
    if(n < 0)
    {
        printResult(result, 0, n_copia);
        return;
    }

    if(n1[n] + n2[n] == 0)
    {
        result[n] = 0;
    }
    else if(n1[n] + n2[n] == 1)
    {
        result[n] = 1;
    }
    else if(n1[n] + n2[n] == 2 && n != 0)
    {
        result[n] = 0;
        n1[n - 1] += 1;
    }
    else if(n1[n] + n2[n] == 3 && n != 0)
    {
        result[n] = 1;
        n1[n - 1] += 1;
    }
    else
    {
        printf("OVERFLOW\n");
        return;
    }

    concatenar(n1, n2, result, n - 1, n_copia);
}

void lerNum(int numeros[], int n, int i)
{
    if(i == n)
    {
        return;
    }
    
    scanf("%d", &numeros[i]);

    lerNum(numeros, n, i + 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    int n1[n];
    lerNum(n1, n, 0);

    int n2[n];
    lerNum(n2, n, 0);

    int resultado[n];

    concatenar(n1, n2, resultado, n - 1, n);

	return 0;
}