#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int acharCodigo(int tamanho_codigo, char codigo[], char binario_convertido[])
{
    int final = 3;
    int c = 0;
    int decimal = 0;
    int soma = 0;
    
    while(final < tamanho_codigo)
    {
        decimal = 0;

        if(codigo[final] == '1')
        {
            decimal += 1;
        }
        if(codigo[final - 1] == '1')
        {
            decimal += 2;
        }
        if(codigo[final - 2] == '1')
        {
            decimal += 4;
        }
        if(codigo[final - 3] == '1')
        {
            decimal += 8;
        }

        soma += decimal;

        if(decimal <= 9)
        {
            binario_convertido[c] = decimal + '0';
            c++;
        }
        else
        {
            printf("Numero invalido!\n");
        }

        final += 4;
    }

    binario_convertido[c] = '\0';

    return soma;
}

void ordenarPalavras(int n, char palavra[][100])
{
    char temp[100];
    for(int j = 0; j < n - 1; j++)
    {
        for(int p = 0; p < n - j - 1; p++)
        {   
            if(strcmp(palavra[p], palavra[p + 1]) > 0)
            {
                strcpy(temp, palavra[p]);

                strcpy(palavra[p], palavra[p + 1]);
                strcpy(palavra[p + 1], temp);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char palavras[n][100];

    for(int i = 0; i < n; i++)
    {
        scanf("%s", palavras[i]);
    }

    char codigo[110];

    scanf("%s", codigo);

    int tamanho_codigo = strlen(codigo);

    char binario_convertido[100];

    if(tamanho_codigo == 0)
    {
        printf("Sem bits no momento...\n");
    }
    else if(n == 0)
    {
        int num_codigo = acharCodigo(tamanho_codigo, codigo, binario_convertido);
        printf("O codigo de entrada eh: %d\n", num_codigo);
    }
    else
    {
        ordenarPalavras(n, palavras);

        int num_codigo = acharCodigo(tamanho_codigo, codigo, binario_convertido);

        printf("O codigo de entrada eh: %d\n", num_codigo);

        for(int i = 0; i < n; i++)
        {
            printf("%s%s\n", palavras[i], binario_convertido);
        }
    }

	return 0;
}