#include <stdio.h>

int backtrack(int n, int linha, int coluna, int labirinto[][n])
{
    if(linha == n - 1 && coluna == n - 1)
    {
        return 1;
    }

    if(labirinto[linha][coluna] == 0)
    {
        return 0;
    }
    if(linha + 1 < n && coluna + 1 < n && labirinto[linha + 1][coluna + 1] == 2)
    {
        return 0;
    }
    if(linha - 1 >= 0 && coluna + 1 < n && labirinto[linha - 1][coluna + 1] == 2)
    {
        return 0;
    }
    if(linha + 1 < n && coluna - 1 >= 0 && labirinto[linha + 1][coluna - 1] == 2)
    {
        return 0;
    }
    if(linha - 1 >= 0 && coluna - 1 >= 0 && labirinto[linha - 1][coluna - 1] == 2)
    {
        return 0;
    }
    if(linha - 1 >= 0 && labirinto[linha - 1][coluna] == 2)
    {
        return 0;
    }
    if(coluna - 1 >= 0 && labirinto[linha][coluna - 1] == 2)
    {
        return 0;
    }
    if(coluna + 1 < n && labirinto[linha][coluna + 1] == 2)
    {
        return 0;
    }
    if(linha + 1 < n && labirinto[linha + 1][coluna] == 2)
    {
        return 0;
    }

    if(coluna + 1 < n && labirinto[linha][coluna + 1] == 1)
    {
        if(backtrack(n, linha, coluna + 1, labirinto))
        {
            return 1;
        }
    }
    if(linha + 1 < n && labirinto[linha + 1][coluna] == 1)
    {
        if(backtrack(n, linha + 1, coluna, labirinto))
        {
            return 1;
        }
    }

    return 0;
}

void encontrarCaminhos(int n, int labirinto[][n])
{
    if(backtrack(n, 0, 0, labirinto))
    {
        printf("Ekul conseguiu ludibriar a dragoa!\n");
        return;
    }

    printf("Ekul tomou o nhac da dragoa :(\n");
    return;
}

void lerLabirinto(int n, int labirinto[][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &labirinto[i][j]);
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    int labirinto[n][n];

    lerLabirinto(n, labirinto);

    encontrarCaminhos(n, labirinto);

	return 0;
}