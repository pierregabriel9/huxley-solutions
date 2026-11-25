#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ehPrimo(int num)
{
    double raiz = sqrt(num);
    int i = 2;

    while(i <= raiz)
    {
        if(num % i == 0)
        {
            return 0;
        }
        
        i++;
    }

    return 1;
}

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    if(n <= 0 || n > 10 || m <= 0 || m > 10)
    {
        printf("Han??\n");
        return 0;
    }

    int qtd_primo = 0;
    int soma = 0;
    int matriz[n][m];

    for(int i = 0; i < n; i++)
    {
        soma = 0;
        
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);
            soma += matriz[i][j];
        }

        if(soma >= 2 && ehPrimo(soma))
        {
            qtd_primo++;
        }
    }

    if(qtd_primo > n - qtd_primo)
    {
        printf("Chama\n");
    }
    else
    {
        printf("Não chama\n");
    }

	return 0;
}