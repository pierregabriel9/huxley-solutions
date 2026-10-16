#include <stdio.h>

int verificacao(int pos_botoes[], int n, int i)
{
    if(i == n)
    {
        return 1;
    }
    if(pos_botoes[i] != -1)
    {
        return 0;
    }

    return verificacao(pos_botoes, n, i + 1);
}

void ehBotao(int alvo, int botoes[], int qtd, int i)
{
    if(i == qtd)
    {
        return;
    }
    if(alvo == botoes[i])
    {
        botoes[i] = -1;
    }

    ehBotao(alvo, botoes, qtd, i + 1);
}

int passos(int posicao, int tam_corredor, int pos_botoes[], int passos_parada[], int i, int qtd_botoes, int qtd_paradas)
{
    if(i == qtd_paradas)
    {
        return verificacao(pos_botoes, qtd_botoes, 0);
    }

    posicao = (posicao + passos_parada[i]) % tam_corredor;

    ehBotao(posicao, pos_botoes, qtd_botoes, 0);

    return passos(posicao, tam_corredor, pos_botoes, passos_parada, i + 1, qtd_botoes, qtd_paradas);
}

void leitura(int array[], int n, int i)
{
    if(i == n)
    {
        return;
    }

    scanf("%d", &array[i]);

    leitura(array, n, i + 1);
}

int main()
{
    int tam_corredor, qtd_botoes, pos_inicial, qtd_paradas;

    scanf("%d%d", &tam_corredor, &qtd_botoes);

    int pos_botoes[qtd_botoes];

    leitura(pos_botoes, qtd_botoes, 0);

    scanf("%d%d", &pos_inicial, &qtd_paradas);

    int passos_parada[qtd_paradas];

    leitura(passos_parada, qtd_paradas, 0);

    int resultado = passos(pos_inicial, tam_corredor, pos_botoes, passos_parada, 0, qtd_botoes, qtd_paradas);

    if(resultado)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

	return 0;
}