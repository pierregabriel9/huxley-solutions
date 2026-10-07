#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 255 

void inverter(char string[], int tamanho)
{
    if(tamanho == 0)
    {
        printf("%c\n", string[tamanho]);
        return;
    }

    printf("%c", string[tamanho]);

    inverter(string, tamanho - 1);
}

int main() 
{
    char string[MAX];

    fgets(string, MAX, stdin);

    int tamanho = strlen(string);

    inverter(string, tamanho - 1);
    
    return 0;
}