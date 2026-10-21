#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 10002

void soma(char num1[], char num2[], int tam1, int tam2, int acressimo)
{
    if(tam1 < 0 && tam2 < 0)
    {
        if(acressimo > 0)
        printf("%d", acressimo);
        
        return;
    }

    if(tam1 >= 0 && tam2 >= 0)
    {
        if((num1[tam1] - 48) + (num2[tam2] - 48) + acressimo > 9)
        {
            soma(num1, num2, tam1 - 1, tam2 - 1, ((num1[tam1] - 48) + (num2[tam2] - 48) + acressimo) / 10);

            printf("%d", (((num1[tam1] - 48) + (num2[tam2] - 48)) + acressimo) % 10);
        }
        else
        {
            soma(num1, num2, tam1 - 1, tam2 - 1, 0);

            printf("%d", ((num1[tam1] - 48) + (num2[tam2] - 48)) + acressimo);
        }
    }

    else if(tam2 < 0)
    {
        if((num1[tam1] - 48) + acressimo > 9)
        {
            soma(num1, num2, tam1 - 1, tam2 - 1, ((num1[tam1] - 48) + acressimo) / 10);

            printf("%d", ((num1[tam1] - 48) + acressimo) % 10);
        }
        else
        {
            soma(num1, num2, tam1 - 1, tam2 - 1, 0);

            printf("%d", (num1[tam1] - 48) + acressimo);
        }
    }

    else
    {
        if((num2[tam2] - 48) + acressimo > 9)
        {
            soma(num1, num2, tam1 - 1, tam2 - 1, ((num2[tam2] - 48) + acressimo) / 10);

            printf("%d", ((num2[tam2] - 48) + acressimo) % 10);
        }
        else
        {
            soma(num1, num2, tam1 - 1, tam2 - 1, 0);

            printf("%d", (num2[tam2] - 48) + acressimo);
        }
    }
}

int main()
{
    char num1[MAX] = {0};
    scanf("%s", num1);

    char num2[MAX] = {0};
    scanf("%s", num2);

    soma(num1, num2, strlen(num1) - 1, strlen(num2) - 1, 0);

    printf("\n");

	return 0;
}