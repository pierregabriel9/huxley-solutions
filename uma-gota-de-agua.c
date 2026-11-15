#include <stdio.h>

void caminhoGota(int matriz[][5], int coluna)
{
    int linha = 0;
    while(linha != 4)
    {
        if(matriz[linha][coluna] == 1)
        {
            coluna++;
        }
        else if(matriz[linha][coluna] == 2)
        {
            coluna--;
        }

        linha++;

        if(coluna < 0 || coluna > 4)
        {
            printf("Tenho sede\n");
            return;
        }
    }

    if(matriz[linha][coluna] == 3)
    {
        printf("Me molhou!\n");
    }
    else
    {
        printf("AGUA\n");
    }
}

void lerMatriz(int matriz[][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main()
{
    int c;
    scanf("%d", &c);

    int matriz[5][5];
    lerMatriz(matriz);

    caminhoGota(matriz, c);
}