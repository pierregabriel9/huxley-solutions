#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void percorrerPosicoesEPrintarFinal(int pos_x, int pos_y, int qtd_jogadas, int linhas, int colunas, char jogadas[], int labirinto[][colunas])
{
    for(int i = 0; i < qtd_jogadas; i++)
    {
        if(jogadas[i] == 'D')
        {
            if(pos_x + 1 < colunas && labirinto[pos_y][pos_x + 1] == 1)
            {
                pos_x++;
            }
        }
        else if(jogadas[i] == 'E')
        {
            if(pos_x - 1 >= 0 && labirinto[pos_y][pos_x - 1] == 1)
            {
                pos_x--;
            }
        }
        else if(jogadas[i] == 'C')
        {
            if(pos_y - 1 >= 0 && labirinto[pos_y - 1][pos_x] == 1)
            {
                pos_y--;
            }
        }
        else
        {
            if(pos_y + 1 < linhas && labirinto[pos_y + 1][pos_x] == 1)
            {
                pos_y++;
            }
        }
    }

    printf("(%d,%d)\n", pos_y, pos_x);
}

void armazenarJogadas(int qtd_jogadas, char jogadas[])
{
    for(int i = 0; i < qtd_jogadas; i++)
    {
        scanf(" %c", &jogadas[i]);
    }
}

void preencherLabirinto(int linhas, int colunas, int labirinto[][colunas])
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            scanf("%d", &labirinto[i][j]);
        }
    }
}

int main()
{
    int linhas, colunas;
    scanf("%d%d", &linhas, &colunas);
    int labirinto[linhas][colunas];

    preencherLabirinto(linhas, colunas, labirinto);

    int qtd_jogadas;
    scanf("%d", &qtd_jogadas);
    char jogadas[qtd_jogadas];
    
    armazenarJogadas(qtd_jogadas, jogadas);

    int pos_ini_x, pos_ini_y;
    scanf("%d%d", &pos_ini_x, &pos_ini_y);

    percorrerPosicoesEPrintarFinal(pos_ini_x, pos_ini_y, qtd_jogadas, linhas, colunas, jogadas, labirinto);

	return 0;
}