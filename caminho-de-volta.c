#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ida_final(int base, int i, int distancia_total)
{
    if(i > base)
    {
        printf("Destino alcancado, distancia percorrida: %d\n", distancia_total);
    }
    else
    {
        printf("Indo, posicao %d\n", i);
        distancia_total++;

        ida_final(base, i + 1, distancia_total);
    }
}

void volta(int distancia, int esquecimento)
{
    if(esquecimento < 0)
    {
        return;
    }
    else
    {
        printf("Voltando, posicao %d\n", esquecimento);
        volta(distancia, esquecimento - 1);
    }
}

int ida_normal(int base, int esquecimento, int i, int distancia)
{
    if(i > esquecimento)
    {
        volta(distancia, esquecimento - 1);
        return distancia * 2;
    }
    else
    {
        printf("Indo, posicao %d\n", i);
        distancia++;
        return ida_normal(base, esquecimento, i + 1, distancia);
    }
}

void loop(int d_base, int qtd_esquecimentos, int distancia_total)
{
    if(qtd_esquecimentos == 0)
    {
        ida_final(d_base, 1, distancia_total);
    }
    else
    {
        int esquecimento_atual;
        scanf("%d", &esquecimento_atual);

        distancia_total += ida_normal(d_base, esquecimento_atual, 1, 0);

        loop(d_base, qtd_esquecimentos - 1, distancia_total);
    }
}

int main() 
{
    int distancia_base, qtd_esquecimentos;
    scanf("%d%d", &distancia_base, &qtd_esquecimentos);

    if(qtd_esquecimentos == 0)
    {
        ida_final(distancia_base, 1, 0);
    }
    else
    {
        loop(distancia_base, qtd_esquecimentos, 0);
    }

	return 0;
}