#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 121

int main()
{
    char nome[MAX];

    fgets(nome, 120, stdin);

    printf("Seja muito bem-vindo %s\n", nome);

	return 0;
}