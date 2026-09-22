#include <stdio.h>

double calculo(int n_carros)
{
    return (n_carros - 2) * 12.89;
}

void loop(double valor_multa, int qtd_casas)
{
    int n_carros;
    scanf("%d", &n_carros);

    if(n_carros == 999)
    {
        printf("%.2lf\n%d\n", valor_multa, qtd_casas);
    }
    else
    {
        if(n_carros > 2)
        {
            valor_multa += calculo(n_carros);
            qtd_casas++;
        }
        
        loop(valor_multa, qtd_casas);
    }
}


int main() 
{
    loop(0, 0);

	return 0;
}