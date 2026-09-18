#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void loop(int n, int ano_base, int validade)
{
    if (n == 1)
    {
        if (validade == 1)
        {
            printf("idades corretas\n");
        }
        else
        {
            printf("mentiu a idade\n");
        }
        return;
    }
    else
    {
        int ano_atual, ano, idade;
        scanf("%d%d", &ano, &idade);

        ano_atual = ano - idade;
        
        if(ano_atual != ano_base)
        {
            validade = 0;
        }
        loop(n - 1, ano_base, validade);
    }
}


int main() 
{
    int n, ano, idade, ano_base;
    scanf("%d", &n);
    scanf("%d%d", &ano, &idade);

    ano_base = ano - idade;

    loop(n, ano_base, 1);

	return 0;
}