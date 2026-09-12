#include <stdio.h>

int moda(int array2[], int a[], int maior, int i, int n, int indice)
{
    if (i == n)
    {
        printf("MODA: %d\n", indice);
        return 0;
    }
    else
    {
        if(array2[a[i]] > maior)
        {
            maior = array2[a[i]];
            indice = a[i];
            return moda(array2, a, maior, i + 1, n, indice);
        }
        else
        {
            return moda(array2, a, maior, i + 1, n, indice);
        }
    }
}

int freq(int array2[], int a[], int i, int n)
{
    if (i == n)
    {
        int maior = 0;
        int indice = a[0];
        moda(array2, a, maior, 0, n, indice);
        return 0;
    }
    else
    {
        array2[a[i]]++;
        return freq(array2, a, i + 1, n);
    }
}

void lervalores(int a[], int n, int i, int array2[])
{
    if (i == n)
    {
        freq(array2, a, 0, n);
        return;
    }
    else
    {
        scanf("%d", &a[i]);
        array2[i] = 0;
        lervalores(a, n, i + 1, array2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int array2[n];

    lervalores(a, n, 0, array2);
}
