#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int diagonalSecundaria(int a, int alvo, int matriz[][a])
{
    int qtd = 0;
    int contador;

    // por cima
    for(int i = a - 1; i > 0; i--)
    {
        contador = 0;
        int coluna = i;
        int linha = 0;

        while(coluna >= 0)
        {
            if(matriz[coluna][linha] != alvo)
            {
                contador = 0;
            }
            else
            {
                contador++;
            }

            if(contador == 3)
            {
                qtd += 4;
                break;
            }

            coluna--;
            linha++;
        }
    }

    // por baixo

    for(int i = 1; i < a; i++)
    {
        contador = 0;
        int linha = a - 1;
        int coluna = i;


        while(coluna < a)
        {
            if(matriz[coluna][linha] != alvo)
            {
                contador = 0;
            }
            else
            {
                contador++;
            }

            if(contador == 3)
            {
                qtd += 4;
                break;
            }

            coluna++;
            linha--;
        }
    }

    return qtd;
}

int diagonalPrincipal(int a, int alvo, int matriz[][a])
{
    int qtd = 0;
    int contador;

    // mudando a linha
    for(int i = 0; i < a; i++)
    {
        contador = 0;
        int linha = 0;
        int coluna = i;

        while(coluna < a)
        {
            if(matriz[linha][coluna] != alvo)
            {
                contador = 0;
            }
            else
            {
                contador++;
            }

            if(contador == 3)
            {
                qtd += 3;
                break;
            }

            linha++;
            coluna++;
        }
    }

    //mudando a coluna
    for(int i = 1; i < a; i++)
    {
        contador = 0;
        int linha = i;
        int coluna = 0;

        while(linha < a)
        {
            if(matriz[linha][coluna] != alvo)
            {
                contador = 0;
            }
            else
            {
                contador++;
            }

            if(contador == 3)
            {
                qtd += 3;
                break;
            }

            linha++;
            coluna++;
        }
    }

    return qtd;
}

int vertical(int a, int alvo, int matriz[][a])
{
    int qtd = 0;
    int contador;

    for(int i = 0; i < a; i++)
    {
        contador = 0;
        for(int j = 0; j < a; j++)
        {
            if(matriz[j][i] != alvo)
            {
                contador = 0;
            }
            else
            {
                contador++;
            }

            if(contador == 3)
            {
                qtd += 2;
                break;
            }
        }
    }

    return qtd;
}

int horizontal(int a, int alvo, int matriz[][a])
{
    int qtd = 0;
    int contador;

    for(int i = 0; i < a; i++)
    {
        contador = 0;
        for(int j = 0; j < a; j++)
        {
            if(matriz[i][j] != alvo)
            {
                contador = 0;
            }
            else
            {
                contador++;
            }

            if(contador == 3)
            {
                qtd ++;
                break;
            }
        }
    }

    return qtd;
}

void lerMatriz(int a, int matriz[][a])
{
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < a; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main()
{
    int a, b; scanf("%d%d", &a, &b);

    int matriz[a][a];
    lerMatriz(a, matriz);

    int pontos = 0;
    int sequencias = 0;

    for(int j = 1; j <= b; j++)
    {
        if(horizontal(a, j, matriz))
        {
            pontos += horizontal(a, j, matriz);
            sequencias += horizontal(a, j, matriz);
        }

        if(vertical(a, j, matriz))
        {
            pontos += vertical(a, j, matriz);
            sequencias += (vertical(a, j, matriz)) / 2;
        }
        if(diagonalPrincipal(a, j, matriz))
        {
            pontos += diagonalPrincipal(a, j, matriz);
            sequencias += (diagonalPrincipal(a, j, matriz)) / 3;
        }
        if(diagonalSecundaria(a, j, matriz))
        {
            pontos += diagonalSecundaria(a, j, matriz);
            sequencias += (diagonalSecundaria(a, j, matriz)) / 4;
        }
    }

    if(sequencias == 0)
    {
        printf("Poxa, voce nao pontuou :(\n");
    }
    else if(pontos == 1)
    {
        printf("Voce so fez um ponto :/\n");
    }
    else
    {
        printf("Voce fez %d pontos e foram registradas %d sequencias :)\n", pontos, sequencias);
    }

	return 0;
}