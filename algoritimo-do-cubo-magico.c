#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void imprimirInvertido(int qtd_movimentos, char movimentos[][3])
{
    for(int i = qtd_movimentos - 1; i >= 0; i--)
    {
        if(movimentos[i][1] == '2')
        {
            printf("%c2", movimentos[i][0]);
        }
        else if(movimentos[i][1] == '\0')
        {
            printf("%c'", movimentos[i][0]);
        }
        else 
        {
            printf("%c", movimentos[i][0]);
        }

        if(i != 0)
        {
            printf(" ");
        }
    }

    printf("\n");
}


int main()
{
    char movimento_atual[3];
    char movimento[25][3];

    int qtd_movimentos = 0;

    while(scanf("%2s", movimento_atual) == 1)
    {
        strcpy(movimento[qtd_movimentos], movimento_atual);

        qtd_movimentos++;
    }

    imprimirInvertido(qtd_movimentos, movimento);

	return 0;
}