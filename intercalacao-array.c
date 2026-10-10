#include <stdio.h>
#include <string.h>

void printFinal(int array[], int tamanho, int i)
{
    if(i != tamanho - 1)
    {
        printf("%d ", array[i]);
    }
    else
    {
        printf("%d\n", array[i]);
        return;
    }

    printFinal(array, tamanho, i + 1);
}

void intercalar(int a1[], int a2[], int array_novo[], int tamanho, int i, int j, int k)
{
    if(k == tamanho)
    {
        return;
    }

    if(i == tamanho / 2)
    {
        array_novo[k] = a2[j];
        j++;
    }
    else if(j == tamanho / 2)
    {
        array_novo[k] = a1[i];
        i++;
    }
    else if(a1[i] < a2[j])
    {
        array_novo[k] = a1[i];
        i++;
    }
    else
    {
        array_novo[k] = a2[j];
        j++;
    }

    intercalar(a1, a2, array_novo, tamanho, i, j, k + 1);
}

void lerArray(int array[], int i, int tamanho)
{
    if(i == tamanho)
    {
        return;
    }

    scanf("%d", &array[i]);

    lerArray(array, i + 1, tamanho);
}

int main()
{
    int tamanho;
    scanf("%d", &tamanho);
    
    int a1[tamanho];
    lerArray(a1, 0, tamanho);

    int a2[tamanho];
    lerArray(a2, 0, tamanho);

    int array_novo[tamanho * 2];

    intercalar(a1, a2, array_novo, tamanho * 2, 0, 0, 0);

    printFinal(array_novo, tamanho * 2, 0);
}