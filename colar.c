#include <stdio.h>

void ler_maior(int qtd[], int n, int i, int maior)
{
    if(i == n)
    {
        printf("%d\n", maior);
        return;
    }
    else
    {
        if(qtd[i] > maior)
        {
            maior = qtd[i];
        }

        ler_maior(qtd, n, i + 1, maior);
    }
}

int ler_dir(char colar[], int ponto_quebra, char cor_base, int n, int j)
{
    if(j == n)
    {
        return j;
    }
    else
    {
        if(ponto_quebra == n - 1)
        {
            if((colar[ponto_quebra] == 'w' || colar[ponto_quebra] == cor_base) && (colar[0] == 'w' || colar[0] == cor_base))
            {
                j++;
                return ler_dir(colar, 0, cor_base, n, j);
            }
            else
            {
                return j;
            }
        }
        else
        {
            if((colar[ponto_quebra] == 'w' || colar[ponto_quebra] == cor_base) && (colar[ponto_quebra + 1] == 'w' || colar[ponto_quebra + 1] == cor_base))
            {
                j++;
                return ler_dir(colar, ponto_quebra + 1, cor_base, n, j);
            }
            else
            {
                return j;
            }
        }
    }
}

int ler_esq(char colar[], int ponto_quebra, char cor_base, int n, int j)
{
    if(j == n)
    {
        return j;
    }
    else
    {
        if(ponto_quebra == 0)
        {
            if((colar[0] == 'w' || colar[0] == cor_base) && (colar[n - 1] == 'w' || colar[n - 1] == cor_base))
            {
                j++;
                return ler_esq(colar, n - 1, cor_base, n, j);
            }
            else
            {
                return j;
            }
        }
        else
        {
            if((colar[ponto_quebra] == 'w' || colar[ponto_quebra] == cor_base) && (colar[ponto_quebra - 1] == 'w' || colar[ponto_quebra - 1] == cor_base))
            {
                j++;
                return ler_esq(colar, ponto_quebra - 1, cor_base, n, j);
            }
            else
            {
                return j;
            }
        }
    }
}

char esq(char colar[], int ponto_quebra, int n, int i)
{
    if(i == n)
    {
        return colar[ponto_quebra];
    }
    else
    {
        if(colar[ponto_quebra] != 'w')
        {
            return colar[ponto_quebra];
        }
        else
        {
            if(ponto_quebra == 0)
            {
                return esq(colar, n - 1, n, i + 1);
            }
            else
            {
                return esq(colar, ponto_quebra - 1, n, i + 1);
            }
        }
    }
}

char dir(char colar[], int ponto_quebra, int n, int i)
{
    if(i == n)
    {
        return colar[ponto_quebra];
    }
    else
    {
        if(colar[ponto_quebra] != 'w')
        {
            return colar[ponto_quebra];
        }
        else
        {
            if(ponto_quebra == n - 1)
            {
                return dir(colar, 0, n, i + 1);
            }
            else
            {
                return dir(colar, ponto_quebra + 1, n, i + 1);
            }
        }
    }
}

void calculo(int n, char colar[], int qtd[], int ponto_quebra)
{
    if(ponto_quebra == n)
    {
        return;
    }
    else
    {
        char cor_esq, cor_dir;
        int esquerda, direita, total;

        if(ponto_quebra + 1 != n)
        {
            cor_esq = esq(colar, ponto_quebra, n, 0);
            cor_dir = dir(colar, ponto_quebra + 1, n, 0);
        }
        else
        {
            cor_esq = esq(colar, ponto_quebra, n, 0);
            cor_dir = dir(colar, 0, n, 0);
        }

        esquerda = ler_esq(colar, ponto_quebra, cor_esq, n, 1);
        direita = ler_dir(colar, ponto_quebra + 1, cor_dir, n, 1);

        if(direita + esquerda >= n)
        {
            qtd[ponto_quebra] = n;
        }
        else
        {
            qtd[ponto_quebra] = direita + esquerda;
        }

        calculo(n, colar, qtd, ponto_quebra + 1);
    }
}

void ler_colar(char colar[], int i, int n)
{
    if(i == n)
    {
        return;
    }
    else
    {
        scanf(" %c", &colar[i]);
        ler_colar(colar, i + 1, n);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    char colar[n];
    int qtd[n];

    ler_colar(colar, 0, n);

    calculo(n, colar, qtd, 0);

    ler_maior(qtd, n, 0, 0);

	return 0;
}