#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int seRepeteQuadrante(int numero, int matriz[][9])
{
    int r = 0;
    int inicio_i = 0;
    int fim_i = 3;

    int inicio_j = 0;
    int fim_j = 3;

    int a = 0;
    while(a < 9)
    {
        for(int i = inicio_i; i < fim_i; i++)
        {
            for(int j = inicio_j; j < fim_j; j++)
            {
                if(numero == matriz[i][j])
                {
                    r++;
                    if(r == 2)
                    {
                        return 0;
                    }
                }
            }
        }

        r = 0;

        if(fim_j == 9)
        {
            inicio_j = 0;
            fim_j = 3;

            inicio_i += 3;
            fim_i += 3;
        }

        inicio_j += 3;
        fim_j += 3;

        a++;
    }

    return 1;
}

int seRepeteColuna(int numero, int matriz[][9])
{
    int r = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(numero == matriz[j][i])
            {
                r++;
                if(r == 2)
                {
                    return 0;
                }
            }
        }
        r = 0;
    }

    return 1;
}

int seRepeteLinha(int numero, int matriz[][9])
{
    int r = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(numero == matriz[i][j])
            {
                r++;
                if(r == 2)
                {
                    return 0;
                }
            }
        }
        r = 0;
    }

    return 1;
}

int conferirValidade(int matriz[][9])
{
    for(int i = 1; i <= 9; i++)
    {
        if(seRepeteLinha(i, matriz) == 0)
        {
            return 0;
        }
        if(seRepeteColuna(i, matriz) == 0)
        {
            return 0;
        }
        if(seRepeteQuadrante(i, matriz) == 0)
        {
            return 0;
        }
    }

    return 1;
}

void preencherMatriz(int matriz[][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main()
{
    int n_matrizes;
    scanf("%d", &n_matrizes);

    int matriz[9][9];

    for(int i = 1; i <= n_matrizes; i++)
    {
        preencherMatriz(matriz);

        if(conferirValidade(matriz) == 1)
        {
            if(i == n_matrizes)
            {
                printf("Instancia %d\nSIM\n", i);
            }
            else
            {
                printf("Instancia %d\nSIM\n\n", i);
            }
        }
        else
        {
            if(i == n_matrizes)
            {
                printf("Instancia %d\nNAO\n", i);
            }
            else
            {
                printf("Instancia %d\nNAO\n\n", i);
            }
        }
    }
    
	return 0;
}