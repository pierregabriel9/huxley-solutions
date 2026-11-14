#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int verificacao(char palavra[], int tamanho_palavra, int y, char matriz[][y])
{
    int contador = 0;
    int letra = 0;

    // Horizontal

    for(int i = 0; i < y; i++)
    {
        contador = 0;
        letra = 0;
        
        for(int j = 0; j < y; j++)
        {
            if(palavra[letra] != matriz[i][j])
            {
                contador = 0;
                letra = 0;
            }
            else
            {
                letra++;
                contador++;
            }

            if(contador == tamanho_palavra)
            {
                return 1;
            }
        }
    }

    // Vertical

    for(int i = 0; i < y; i++)
    {
        contador = 0;
        letra = 0;
        
        for(int j = 0; j < y; j++)
        {
            if(palavra[letra] != matriz[j][i])
            {
                contador = 0;
                letra = 0;
            }
            else
            {
                letra++;
                contador++;
            }

            if(contador == tamanho_palavra)
            {
                return 1;
            }
        }
    }

    // Diagonal parte cima

    int coluna = 0;
    contador = 0;
    letra = 0;

    while(coluna < y)
    {
        contador = 0;
        letra = 0;
        int j = coluna;

        for(int i = 0; i < y; i++, j++)
        {
            if(palavra[letra] != matriz[i][j])
            {
                contador = 0;
                letra = 0;
            }
            else
            {
                letra++;
                contador++;
            }

            if(contador == tamanho_palavra)
            {
                return 1;
            }

            if(j + 1 == y)
            {
                break;
            }
        }

        coluna++;
    }   

    // Diagonal parte baixo

    int linha = 1;
    contador = 0;
    letra = 0;

    while(linha < y)
    {
        contador = 0;
        letra = 0;

        int j = linha;

        for(int i = 0; i < y; i++, j++)
        {
            if(palavra[letra] != matriz[j][i])
            {
                contador = 0;
                letra = 0;
            }
            else
            {
                contador++;
                letra++;
            }

            if(contador == tamanho_palavra)
            {
                return 1;
            }

            if(j + 1 == y)
            {
                break;
            }
        }

        linha++;
    }

    return 0;
}

int main()
{
    int x;
    scanf("%d", &x);

    char palavras[x][100];

    for(int i = 0; i < x; i++)
    {
        scanf("%s", &palavras[i][0]);
    }

    int y;
    scanf("%d", &y);

    char matriz_corrompida[y][y];

    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < y; j++)
        {
            scanf(" %c", &matriz_corrompida[i][j]);
        }
    }

    int qtd = 0;
    int palavrasvalidas[x];

    for(int i = 0; i < x; i++)
    {
        if(verificacao(palavras[i], strlen(palavras[i]), y, matriz_corrompida))
        {
            qtd++;
            palavrasvalidas[i] = 1;
        }
        else
        {
            palavrasvalidas[i] = -1;
        }
    }

    printf("palavras encontradas: %d\n", qtd);

    if(qtd > 0)
    {
        for(int i = 0; i < x; i++)
        {
            if(palavrasvalidas[i] == 1)
            {
                printf("%s\n", palavras[i]);
            }
        }
    }

	return 0;
}