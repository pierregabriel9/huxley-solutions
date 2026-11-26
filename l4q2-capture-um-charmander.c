#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void determinarMes(int mes)
{
    if(mes == 1)
    {
        printf("Janeiro\n");
    }
    else if(mes == 2)
    {
        printf("Fevereiro\n");
    }
    else if(mes == 3)
    {
        printf("Marco\n");
    }
    else if(mes == 4)
    {
        printf("Abril\n");
    }
    else if(mes == 5)
    {
        printf("Maio\n");
    }
    else if(mes == 6)
    {
        printf("Junho\n");
    }
    else if(mes == 7)
    {
        printf("Julho\n");
    }
    else if(mes == 8)
    {
        printf("Agosto\n");
    }
    else if(mes == 9)
    {
        printf("Setembro\n");
    }
    else if(mes == 10)
    {
        printf("Outubro\n");
    }
    else if(mes == 11)
    {
        printf("Novembro\n");
    }
    else
    {
        printf("Dezembro\n");
    }
}

void ordinal(int ordem)
{
    if(ordem == 1)
    {
        printf("Primeiro");
    }
    else if(ordem == 2)
    {
        printf("Segundo");
    }
    else if(ordem == 3)
    {
        printf("Terceiro");
    }
    else if(ordem == 4)
    {
        printf("Quarto");
    }
}


int main()
{
    int mes;
    int ordem[12][2] = {0};
    int dom_sabado = 0;
    double qtd_dia;
    double menor = INFINITY;

    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            scanf("%lf", &qtd_dia);

            if(qtd_dia < menor)
            {
                menor = qtd_dia;
                mes = i;

                if(j % 2 == 0)
                {
                    ordem[i][0] = j/2;
                    dom_sabado = 1;
                }
                else
                {
                    ordem[i][1] = j/2;
                    dom_sabado = 2;
                }
            }
        }
    }

    if(menor > 0.5)
    {
        printf("Proximo ano eu tento denovo...\n");
        return 0;
    }

    if(dom_sabado == 1)
    {
        printf("O melhor dia e no ");
        ordinal(ordem[mes][0] + 1);
        printf(" Sabado de ");
        determinarMes(mes + 1);
    }
    else
    {
        printf("O melhor dia e no ");
        ordinal(ordem[mes][1] + 1);
        printf(" Domingo de ");
        determinarMes(mes + 1);
    }

	return 0;
}