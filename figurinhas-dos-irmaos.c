#include <stdio.h>

#define MAX 13001

void executarSoma(int pont_joao, int pont_maria, int figs_joao, int figs_maria, int figurinhas[], int ja_lidas[], int n, int i)
{
    if(i == n)
    {
        printf("%d\n", figs_joao);
        printf("%d\n", figs_maria);

        if(pont_joao > pont_maria)
        {
            printf("%d\n", pont_joao);
        }
        else
        {
            printf("%d\n", pont_maria);
        }

        return;
    }

    if(ja_lidas[figurinhas[i]] == 0)
    {
        ja_lidas[figurinhas[i]]++;

        if(figurinhas[i] % 2 == 0)
        {
            pont_joao += figurinhas[i];
        }
        else
        {
            pont_maria += figurinhas[i];
        }
    }

    if(figurinhas[i] % 2 == 0)
    {
        figs_joao++;
    }
    else
    {
        figs_maria++;
    }

    executarSoma(pont_joao, pont_maria, figs_joao, figs_maria, figurinhas, ja_lidas, n, i + 1);
}

void lerFigurinhas(int figurinhas[], int n, int i)
{
    if(i == n)
    {
        return;
    }

    scanf("%d", &figurinhas[i]);

    lerFigurinhas(figurinhas, n, i + 1);
}

int main() 
{
    int n;
    scanf("%d", &n);

    int figurinhas[n];
    int ja_lidas[MAX] = {0};

    int pont_joao = 0;
    int figs_joao = 0;

    int pont_maria = 0;
    int figs_maria = 0;

    lerFigurinhas(figurinhas, n, 0);

    executarSoma(pont_joao, pont_maria, figs_joao, figs_maria, figurinhas, ja_lidas, n, 0);

	return 0;
}