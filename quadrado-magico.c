#include <stdio.h>

int verificar(int n, int matriz[][n])
{
    int validade = 1;

    int soma_h_inicial = 0;
    int soma_h_atual = 0;

    for(int i = 0; i < n; i++)
    {
        soma_h_atual = 0;

        for(int j = 0; j < n; j++)
        {
            if(i == 0)
            {
                soma_h_inicial += matriz[i][j];
            }
            else
            {
                soma_h_atual += matriz[i][j];
            }
        }

        if(i != 0 && soma_h_atual != soma_h_inicial)
        {
            validade = 0;
        }
    }

    int soma_v_inicial = 0;
    int soma_v_atual = 0;

    for(int i = 0; i < n; i++)
    {
        soma_v_atual = 0;

        for(int j = 0; j < n; j++)
        {
            if(i == 0)
            {
                soma_v_inicial += matriz[j][i];
            }
            else
            {
                soma_v_atual += matriz[j][i];
            }
        }

        if(i != 0 && soma_v_atual != soma_v_inicial)
        {
            validade = 0;
        }
    }

    if(soma_h_inicial != soma_v_inicial)
    {
        validade = 0;
    }

    int soma_dp = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                soma_dp += matriz[i][j];
            }
        }
    }

    if(soma_dp != soma_h_inicial)
    {
        validade = 0;
    }

    int soma_ds = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i + j == n - 1)
            {
                soma_ds += matriz[i][j];
            }
        }
    }

    if(soma_dp != soma_ds)
    {
        validade = 0;
    }

    if(validade)
    {
        return soma_dp;
    }
    else
    {
        return 0;
    }
}

void preencherMatriz(int n, int matriz[][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main()
{
    int verificacao;

    int n;
    scanf("%d", &n);

    int matriz[n][n];

    preencherMatriz(n, matriz);

    verificacao = verificar(n, matriz);

    if(verificacao)
    {
        printf("%d\n", verificacao);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}