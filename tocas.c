#include <stdio.h>

int ciclo(int buraco[], int alvo, int indice)
{
    if(alvo == buraco[indice])
    {
        buraco[indice] = -1;
        return 1;
    }

    int resultado = ciclo(buraco, alvo, buraco[indice]);

    buraco[indice] = -1;

    return resultado;
}

void contarTocas(int buracos[], int n, int i, int qtd_tocas)
{
    if(i == n)
    {
        printf("%d\n", qtd_tocas);
        return;
    }
    
    if(buracos[i] != -1 && ciclo(buracos, i, i) == 1)
    {
        qtd_tocas++;
    }

    contarTocas(buracos, n, i + 1, qtd_tocas);
}

void lerBuracos(int buracos[], int n, int i)
{
    if(i == n)
    {
        return;
    }
    scanf("%d", &buracos[i]);
    lerBuracos(buracos, n, i + 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    int buracos[n];

    lerBuracos(buracos, n, 0);

    contarTocas(buracos, n, 0, 0);

    return 0;
}