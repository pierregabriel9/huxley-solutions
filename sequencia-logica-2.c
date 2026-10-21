#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int fator_de_quebra, n_elementos, incremento;
    scanf("%d%d%d", &fator_de_quebra, &n_elementos, &incremento);
    int numero = 1;

    for(int i = 1; numero <= n_elementos; i ++)
    {
        if(i % fator_de_quebra == 0)
        {
            printf("%d\n", numero);
        }
        else if(numero + incremento > n_elementos)
        {
            printf("%d\n", numero);
        }
        else
        {
            printf("%d ", numero);
        }

        numero += incremento;
    }

	return 0;
}