#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void lerMatriz(int m, double matriz[][m], double *ataque, double *defesa)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%lf", &matriz[i][j]);

            if(i == j)
            {
                *ataque += matriz[i][j];
            }
            if(i + j == m - 1)
            {
                *defesa += matriz[i][j];
            }
        }
    }
}

int main()
{
    int m;
    double vr, vk;
    scanf("%d%lf%lf", &m, &vr, &vk);

    double mr[m][m];
    double atk_r = 0;
    double def_r = 0;
    lerMatriz(m, mr, &atk_r, &def_r);

    double mk[m][m];
    double atk_k = 0;
    double def_k = 0;
    lerMatriz(m, mk, &atk_k, &def_k);

    int qtd_acoes;
    scanf("%d", &qtd_acoes);

    char acao_r;
    char acao_k;
    double dano;

    for(int i = 0; i < qtd_acoes; i++)
    {
        scanf(" %c %c", &acao_r, &acao_k);

        if(acao_k == 'A' && acao_r == 'A')
        {
            dano = fabs(atk_k - atk_r);

            if(atk_k > atk_r)
            {
                vr -= dano;
            }
            else if(atk_r > atk_k)
            {
                vk -= dano;
            }
        }
        else if(acao_k == 'A' && acao_r == 'D' && atk_k > def_r)
        {
            dano = (atk_k - def_r) / 2;

            vr -= dano;
        }
        else if(acao_r == 'A' && acao_k == 'D' && atk_r > def_k)
        {
            dano = (atk_r - def_k) / 2;

            vk -= dano;
        }
    }

    if(vr > vk)
    {
        printf("Ryu ganhou a batalha.\n");
    }
    else if(vk > vr)
    {
        printf("Ken ganhou a batalha.\n");
    }
    else
    {
        printf("Houve empate.\n");
    }

	return 0;
}