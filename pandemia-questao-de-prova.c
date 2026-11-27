#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void preencherMatriz(int l, int c, int reunioes[][c])
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            reunioes[i][j] = 0;
        }
    }
}

void lerMatriz(int l, int c, int reunioes[][c])
{
    int qtd_por_reuniao;

    for(int i = 0; i < l; i++)
    {
        scanf("%d", &qtd_por_reuniao);

        for(int j = 0; j < qtd_por_reuniao; j++)
        {
            scanf("%d", &reunioes[i][j]);
        }
    }
}

int determinarInfectados(int l, int c, int reunioes[][c], int infectado, int reuniao_infectado, int ja_infectado[])
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(reunioes[i][j] == 0)
            {
                break;
            }
            if(i == reuniao_infectado - 1)
            {
                ja_infectado[reunioes[i][j] - 1]++;
            }
            else if(i > reuniao_infectado - 1 && ja_infectado[reunioes[i][j] - 1] > 0)
            {
                for(int p = 0; p < c; p++)
                {
                    if(reunioes[i][p] == 0)
                    {
                        break;
                    }
                    if(reunioes[i][p] != infectado)
                    {
                        ja_infectado[reunioes[i][p] - 1]++;
                    }
                }
            }
        }
    }

    int contador = 0;

    for(int i = 0; i < c; i++)
    {
        if(ja_infectado[i] > 0)
        {
            contador++;
        }
    }

    return contador;
}

void preencherAlunos(int n, int alunos[])
{
    for(int i = 0; i < n; i++)
    {
        alunos[i] = 0;
    }
}

int main()
{
    int total_amigos, total_reunioes;
    scanf("%d%d", &total_amigos, &total_reunioes);

    int reunioes[total_reunioes][total_amigos];

    preencherMatriz(total_reunioes, total_amigos, reunioes);

    int infectado, reuniao_infectado;
    scanf("%d%d", &infectado, &reuniao_infectado);

    lerMatriz(total_reunioes, total_amigos, reunioes);

    int freq_alunos[total_amigos];

    preencherAlunos(total_amigos, freq_alunos);

    int qtd_infectados = determinarInfectados(total_reunioes, total_amigos, reunioes, infectado, reuniao_infectado, freq_alunos);

    printf("%d\n", qtd_infectados);

	return 0;
}