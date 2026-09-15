#include <stdio.h>
#include <stdlib.h>


int calculo(int letra, int i, int total_soma)
{
    if ((i - 1) == letra)
    {

        return abs(total_soma);
    }
    else
    {
        if (i % 3 == 1)
        {
            total_soma += i;
        }
        else if (i % 3 == 2)
        {
            total_soma += (i * (i + 1));
        }
        else
        {
            total_soma -= (i * i);
        }

        return calculo(letra, i + 1, total_soma);
    }
}

void loop (int n)
{
    int soma = 0;
    
    if (n == 0)
    {
        return;
    }
    else
    {
        int letra;
        scanf("%d", &letra);

        soma = calculo(letra, 1, 0);
        
        printf("%c", soma + 65);

        loop(n - 1);
    }
}


int main()
{
    int n;
    scanf("%d", &n);

    loop(n);

    printf("\n");
}