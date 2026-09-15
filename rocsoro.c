#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ganhador(int p, int a, int h)
{
    if (p > a && p > h)
    {
        printf("Pedro ganhou\n");
    }
    else if(a > p && a > h)
    {
        printf("Anderson ganhou\n");
    }
    else
    {
        printf("Hugo ganhou\n");
    }
}

int som(int num, int soma)
{
    if (num < 10)
    {
        soma += num;
        return soma;
    }
    else
    {
        soma += (num % 10);
        return som(num / 10, soma);
    }
}

void loop(int n, int pedro, int anderson, int hugo, int empates)
{
    if (n == 0)
    {
        printf("Pontuacao Pedro: %d\n", pedro);
        printf("Pontuacao Anderson: %d\n", anderson);
        printf("Pontuacao Hugo: %d\n", hugo);
        printf("Empates: %d\n", empates);

        ganhador(pedro, anderson, hugo);

        return;
    }
    else
    {
        int n_pedro, n_anderson, n_hugo;

        int num_resultado, ultimo_digito;

        scanf("%d%d%d", &n_pedro, &n_anderson, &n_hugo);

        if ((n_pedro + n_anderson + n_hugo) % 2 == 1)
        {
            num_resultado = (n_pedro * n_anderson * n_hugo) / 2;
        }
        else if ((n_pedro + n_anderson + n_hugo) % 2 == 0)
        {
            num_resultado = som(n_pedro, 0) * som(n_anderson, 0) * som(n_hugo, 0);
        }

        ultimo_digito = num_resultado % 10;

        if (ultimo_digito >= 1 && ultimo_digito <= 3)
        {
            pedro += num_resultado;
        }
        else if (ultimo_digito >= 4 && ultimo_digito <= 6)
        {
            anderson += num_resultado;
        }
        else if (ultimo_digito >= 7 && ultimo_digito <= 9)
        {
            hugo += num_resultado;
        }
        else
        {
            empates++;
        }

        loop(n - 1, pedro, anderson, hugo, empates);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    loop(n, 0, 0, 0, 0);

	return 0;
}