#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void lerMatriz(int n, int matriz[][n])
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int matriz1[n][n];
    lerMatriz(n, matriz1);

    int matriz2[n][n];
    lerMatriz(n, matriz2);

    int soma;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            soma = matriz1[i][j] + matriz2[i][j];
            printf("%d ", soma);
        }
        printf("\n");
    }

	return 0;
}