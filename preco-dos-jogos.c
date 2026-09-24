#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double calculo(double taxa, double preco, int i)
{
    if(i == 3)
    {
        return preco;
    }
    else
    {
        if(preco > 100)
        {
            preco *= (1 - taxa);
            return calculo(taxa, preco, i + 1);
        }     
        else if(preco <= 45)
        {
            return preco;
        }
        else
        {
            if(preco * (1 - (taxa / 2)) > 45)
            {
                preco *= (1 - (taxa / 2));
                return calculo(taxa, preco, i + 1);
            }
            else
            {
                return 45;
            }
        }
    }
}

double taxa_decaimento(int dificuldade, double preco)
{
    double taxa;

    if(dificuldade == 0)
    {
        taxa = 0.25;    
    }
    else if(dificuldade == 1)
    {
        taxa = 0.2;    
    }
    else if(dificuldade == 2)
    {
        taxa = 0.18;    
    }
    else if(dificuldade == 3)
    {
        taxa = 0.15;    
    }
    else if(dificuldade == 4)
    {
        taxa = 0.12;    
    }
    else
    {
        taxa = 0.1;    
    }

    return calculo(taxa, preco, 0);
}

void loop(int i, int qtd)
{
    if(i == qtd)
    {
        return;
    }
    else
    {
        int dificuldade;
        double preco;

        scanf("%d%lf", &dificuldade, &preco);

        double valor_final = taxa_decaimento(dificuldade, preco);

        printf("Jogo[%d] = R$%.2lf\n", i, valor_final);

        loop(i + 1, qtd);
    }
}

int main() 
{
    int qtd;
    scanf("%d", &qtd);

    loop(0, qtd);

	return 0;
}