#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void verificarAmbrosio(int n_candidatos, int vagas, double parcial[][2])
{
    if(parcial[0][0] == -1 && parcial[0][1] == -1)
    {
        printf("Ambrosio foi desclassificado\n");
        return;
    }

    int grupo_de_ambrosio;
    if(parcial[0][0] < parcial[0][1])
    {
        // vermelho
        grupo_de_ambrosio = 1;
    }
    else
    {
        // azul
        grupo_de_ambrosio = 0;
    }
    
    int classificacao_ambrosio = 1;

    for(int i = 1; i < n_candidatos; i++)
    {
        if(grupo_de_ambrosio == 0)
        {
            if(parcial[0][0] < parcial[i][0] && parcial[i][0] != -1 && parcial [i][0] >= parcial[i][1])
            {
                classificacao_ambrosio++;
            }
        }
        else
        {
            if(parcial[0][1] < parcial[i][1] && parcial[i][1] != -1 && parcial [i][1] > parcial[i][0])
            {
                classificacao_ambrosio++;
            }
        }
    }

    printf("Candidato: Ambrosio\n");

    if(grupo_de_ambrosio == 0)
    {
        printf("Grupo: Azul\n");
    }
    else
    {
        printf("Grupo: Vermelho\n");
    }

    printf("Classificacao: %do lugar\n", classificacao_ambrosio);

    int vagas_azul, vagas_vermelho;

    if(vagas % 2 == 0)
    {
        vagas_azul = vagas / 2;
        vagas_vermelho = vagas / 2;
    }
    else
    {
        vagas_azul = (vagas / 2) + 1;
        vagas_vermelho = vagas / 2;
    }

    if(grupo_de_ambrosio == 0)
    {
        if(classificacao_ambrosio > vagas_azul)
        {
            printf("Situacao: Nao convocado\n");
        }
        else
        {
            printf("Situacao: Convocado\n");
        }
    }
    else
    {
        if(classificacao_ambrosio > vagas_vermelho)
        {
            printf("Situacao: Nao convocado\n");
        }
        else
        {
            printf("Situacao: Convocado\n");
        }
    }
}

void contabilizarParciais(int n_candidatos, double parciais[][2], double pontuacoes[][4])
{
    for(int i = 0; i < n_candidatos; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(j % 2 == 0)
            {
                // vaga azul
                if(pontuacoes[i][3] >= 50)
                {
                    parciais[i][0] = -1;
                    parciais[i][1] = -1;
                    break;
                }
                else
                {
                    parciais[i][j] = (pontuacoes[i][1] * 0.25) + ((50 - pontuacoes[i][3]) * 0.2);
                }
            }
            else
            {
                // vaga vermelho
                if(pontuacoes[i][2] >= 100)
                {
                    parciais[i][0] = -1;
                    parciais[i][1] = -1;
                    break;
                }
                else
                {
                    parciais[i][j] = (pontuacoes[i][0] * 0.3) + ((100 - pontuacoes[i][2]) * 0.25);
                }
            }
        }
    }
}

void lerPontuacoes(int n_candidatos, double pontuacoes[n_candidatos][4])
{
    for(int i = 0; i < n_candidatos; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            scanf("%lf", &pontuacoes[i][j]);
        }
    }
}

int main()
{
    int n_candidatos, vagas;
    scanf("%d%d", &n_candidatos, &vagas);

    double pontuacoes[n_candidatos][4];

    lerPontuacoes(n_candidatos, pontuacoes);

    double parciais[n_candidatos][2];

    contabilizarParciais(n_candidatos, parciais, pontuacoes);

    verificarAmbrosio(n_candidatos, vagas, parciais);

	return 0;
}