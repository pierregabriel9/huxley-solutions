#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int casaParada(int passo, int indice_atual, int tamanho_tabuleiro, int tabuleiro[])
{
    if(passo + indice_atual > (tamanho_tabuleiro - 1))
    {
        return ((indice_atual + passo) % tamanho_tabuleiro + tamanho_tabuleiro) % tamanho_tabuleiro;
    }
    else if(passo + indice_atual < 0)
    {
        return ((indice_atual + passo) % tamanho_tabuleiro + tamanho_tabuleiro) % tamanho_tabuleiro;
    }
    else
    {
        return passo + indice_atual;
    }
}

int percorrerTabuleiro(int rodadas, int jogador, int tamanho_tabuleiro, int tabuleiro[], int jogadas[][rodadas])
{
    int casa_parada = 0;

    for(int i = 0; i < rodadas; i++)
    {
        casa_parada = casaParada(jogadas[jogador][i], casa_parada, tamanho_tabuleiro, tabuleiro);
        casa_parada = casaParada(tabuleiro[casa_parada], casa_parada, tamanho_tabuleiro, tabuleiro);
    }

    return casa_parada;
}

void preencherJogadas(int n_jogadores, int rodadas, int jogadas[][rodadas])
{
    for(int i = 0; i < rodadas; i++)
    {
        for(int j = 0; j < n_jogadores; j++)
        {
            scanf("%d", &jogadas[j][i]);
        }
    }
}

void preencherTabuleiro(int tabuleiro[], int tamanho_tabuleiro)
{
    for(int i = 0; i < tamanho_tabuleiro; i++)
    {
        scanf("%d", &tabuleiro[i]);
    }
}

int main()
{
    int tamanho_tabuleiro, n_jogadores, rodadas, casa_parada;
    scanf("%d%d%d", &tamanho_tabuleiro, &n_jogadores, &rodadas);

    int tabuleiro[tamanho_tabuleiro];
    int jogadas[n_jogadores][rodadas];

    preencherTabuleiro(tabuleiro, tamanho_tabuleiro);

    preencherJogadas(n_jogadores, rodadas, jogadas);

    for(int i = 0; i < n_jogadores; i++)
    {
        casa_parada = percorrerTabuleiro(rodadas, i, tamanho_tabuleiro, tabuleiro, jogadas);
        printf("%d\n", casa_parada);
    }

	return 0;
}