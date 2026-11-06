#include <stdio.h>

int verificaValidade(int ataque[][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &ataque[i][j]);
        }
    }

    if(ataque[0][0] == 0 && ataque[2][0] == 0)
    {
        return 0;
    }
    else if(ataque[0][0] == 1)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if((i != j && ataque[i][j] == 1) || (i == j && ataque[i][j] == 0))
                {
                    return 0;
                }
            }
        }
    }
    else if(ataque[2][0] == 1)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if((i + j == 2 && ataque[i][j] == 0) || (i + j != 2 && ataque[i][j] == 1))
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main()
{
    int vida_luke;
    int vida_vader;

    scanf("%d%d", &vida_luke, &vida_vader);

    int ataque_luke[3][3];
    int ataque_vader[3][3];

    int validade_luke;
    int validade_vader;

    int c = 0;

    while(c >= 0)
    {
        if(vida_luke <= 0 && vida_vader <= 0)
        {
            printf("Houve empate.\n");
            break;
        }
        else if(vida_luke <= 0)
        {
            printf("Darth Vader venceu.\n");
            break;
        }
        else if(vida_vader <= 0)
        {
            printf("Luke Skywalker venceu.\n");
            break;
        }
        else if(c == 10)
        {
            if(vida_luke == vida_vader)
            {
                printf("Houve empate.\n");
            }
            else if(vida_luke > vida_vader)
            {
                printf("Luke Skywalker venceu.\n");
            }
            else
            {
                printf("Darth Vader venceu.\n");
            }
            
            break;
        }

        validade_luke = verificaValidade(ataque_luke);
        validade_vader = verificaValidade(ataque_vader);

        if(validade_luke == 1 && validade_vader == 0)
        {
            vida_vader -= 15;
        }
        else if(validade_vader == 1 && validade_luke == 0)
        {
            vida_luke -= 15;
        }
        else if(validade_luke == 1 && validade_vader == 1)
        {
            if(ataque_luke[0][0] == ataque_vader[0][0])
            {
                vida_luke -= 15;
                vida_vader -= 15;
            }
        }

        c++;
    }

    return 0;
}