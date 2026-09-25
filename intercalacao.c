#include <stdio.h>

void print_conc(int array_c[], int i, int n)
{
    if(i == n - 1)
    {
        printf("%d\n", array_c[i]);
        return;
    }
    else
    {
        printf("%d ", array_c[i]);
        print_conc(array_c, i + 1, n);
    }
}

void concatenar(int array_a[], int array_b[], int array_c[], int i, int total)
{
    if(i == total)
    {
        return;
    }
    else
    {
        array_c[i * 2] = array_a[i];
        array_c[(i * 2) + 1] = array_b[i]; 

        concatenar(array_a, array_b, array_c, i + 1, total);
    }
}

void ler_a_b(int array[], int i, int n)
{
    if (i == n)
    {
        return;
    }
    else
    {
        scanf("%d", &array[i]);

        ler_a_b(array, i + 1, n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int array_a[n];
    int array_b[n];
    int array_c[n * 2];

    ler_a_b(array_a, 0, n);
    ler_a_b(array_b, 0, n);

    concatenar(array_a, array_b, array_c, 0, n);

    print_conc(array_c, 0, n * 2);
}