#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int fator_de_quebra, n_elementos;
    scanf("%d%d", &fator_de_quebra, &n_elementos);

    for(int i = 1; i <= n_elementos; i ++)
    {
        if(i % fator_de_quebra == 0)
        {
            printf("%d\n", i);
        }
        else
        {
            printf("%d ", i);
        }
    }

	return 0;
}