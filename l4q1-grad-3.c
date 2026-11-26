#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char simbolo;
    double distancia;
    double tempo;

    double estatisticas[50][4] = {0};

    int indice = 0;
    int computadores = 0;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            scanf(" %c", &simbolo);

            if(simbolo != '*')
            {
                distancia = sqrt(pow(i, 2) + pow(j, 2));
                tempo = distancia * 20;

                if(simbolo - '0' == 0)
                {
                    tempo += 40;
                }

                estatisticas[indice][0] = i;
                estatisticas[indice][1] = j;
                estatisticas[indice][2] = tempo;

                indice++;
                computadores++;
            }
        }
    }

    if(computadores == 0)
    {
        printf("Tristemente voce vai ter que aturar os PCs do grad 4\n");
        return 0;
    }

    int menor = 0;

    for(int k = 0; k < indice; k++)
    {
        if(estatisticas[menor][2] > estatisticas[k][2])
        {
            menor = k;
        }
    }

    printf("Vai la pro computador %d da fileira %d\n", (int) estatisticas[menor][1], (int) estatisticas[menor][0]);

	return 0;
}