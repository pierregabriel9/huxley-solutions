#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printDistribuicao(int pessoas_vagao[], int i, int n)
{
    if(i == n)
    {
        return;
    }

    if(i == n - 1)
    {
        printf("%d\n", pessoas_vagao[i]); 
    }
    else
    {
        printf("%d ", pessoas_vagao[i]); 
    }

    printDistribuicao(pessoas_vagao, i + 1, n);
}

void distribuicao(int pessoas_vagao[], int passageiros, int n, int vagoes)
{
    if(n < 0 || passageiros == 0)
    {
        if(passageiros == 0)
        {
            printf("Todos foram acomodados\n");
            printDistribuicao(pessoas_vagao, 0, vagoes);
        }
        else
        {
            printf("%d ficaram de fora.\n", passageiros);
            printDistribuicao(pessoas_vagao, 0, vagoes);
        }
        return;
    }

    if(pessoas_vagao[n] < 4 && passageiros > 0)
    {
        pessoas_vagao[n]++;
        passageiros--;

        distribuicao(pessoas_vagao, passageiros, n, vagoes);
    }
    else
    {
        distribuicao(pessoas_vagao, passageiros, n - 1, vagoes);
    }
}

void lerPessoasVagao(int pessoas_vagao[], int n, int i)
{
    if(i == n)
    {
        return;
    }
        
    scanf("%d", &pessoas_vagao[i]);

    lerPessoasVagao(pessoas_vagao, n, i + 1);
}

int main()
{
    int n_vagoes;
    scanf("%d", &n_vagoes);

    int pessoas_vagao[n_vagoes];

    lerPessoasVagao(pessoas_vagao, n_vagoes, 0);

    int novos_passageiros;

    scanf("%d", &novos_passageiros);

    distribuicao(pessoas_vagao, novos_passageiros, n_vagoes - 1, n_vagoes);

	return 0;
}