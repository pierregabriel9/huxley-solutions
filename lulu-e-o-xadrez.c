#include <stdio.h>

int soma(char tipo)
{
    if(tipo == 'p')
    {
        return 1;
    }
    else if(tipo == 'b')
    {
        return 3;
    }
    else if(tipo == 'c')
    {
        return 3;
    }
    else if(tipo == 't')
    {
        return 8;
    }
    else if(tipo == 'd')
    {
        return 9;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int brancas = 0;
    int pretas = 0;

    char cor;
    char tipo;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            scanf(" %c %c", &tipo, &cor);

            if(cor == 'L')
            {
                continue;
            }
            else if(cor == 'p')
            {
                pretas += soma(tipo);
            }
            else
            {
                brancas += soma(tipo);
            }
        }
    }

    if(brancas > pretas)
    {
        printf("Brancas\n");
    }
    else if (pretas > brancas)
    {
        printf("Negras\n");
    }
    else
    {
        printf("Empate\n");
    }
    
	return 0;
}