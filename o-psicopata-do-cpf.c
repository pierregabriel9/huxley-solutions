#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
  
struct pessoa 
{
    char nome[50];
    char cpf[12];
    char senha[30];
};

void criarSenha(char nome[], char cpf[], char senha_user[])
{
    int tamanho_nome = strlen(nome);
    int tamanho_cpf = strlen(cpf);

    for(int i = 0; i < tamanho_nome + 3; i++)
    {
        if(i == tamanho_nome)
        {
            senha_user[i] = cpf[tamanho_cpf - 2];
        }
        else if(i == tamanho_nome + 1)
        {
            senha_user[i] = cpf[tamanho_cpf - 1];
        }
        else if(i == tamanho_nome + 2)
        {
            senha_user[i] = '\0';
        }
        else
        {
            senha_user[i] = ((nome[i] - 'a' + (cpf[i] - '0')) % 26) + 'a';
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct pessoa pessoas[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%s", pessoas[i].nome);
        scanf("%s", pessoas[i].cpf);

        criarSenha(pessoas[i].nome, pessoas[i].cpf, pessoas[i].senha);
    }

    for(int j = 0; j < n - 1; j++)
    {
        for(int p = 0; p < n - 1 - j; p++)
        {
            if(strcmp(pessoas[p].nome, pessoas[p + 1].nome) > 0)
            {
                struct pessoa temp;

                temp = pessoas[p];
                pessoas[p] = pessoas[p + 1];
                pessoas[p + 1] = temp;
            }
        }
    }

    for(int k = 0; k < n; k++)
    {
        printf("%s %s\n", pessoas[k].nome, pessoas[k].senha);    
    }

	return 0;
}