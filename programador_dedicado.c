#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_produtivo(int dia)
{
    if (dia == 1)
    {
        printf("DIA QUE MAIS PRODUZIU: DOMINGO\n");
    }
    else if (dia == 2)
    {
        printf("DIA QUE MAIS PRODUZIU: SEGUNDA\n");
    }
    else if (dia == 3)
    {
        printf("DIA QUE MAIS PRODUZIU: TERCA\n");
    }
    else if (dia == 4)
    {
        printf("DIA QUE MAIS PRODUZIU: QUARTA\n");
    }
    else if (dia == 5)
    {
        printf("DIA QUE MAIS PRODUZIU: QUINTA\n");
    }
    else if (dia == 6)
    {
        printf("DIA QUE MAIS PRODUZIU: SEXTA\n");
    }
    else
    {
        printf("DIA QUE MAIS PRODUZIU: SABADO\n");
    }
}

void loop(int n, int p, int l, int dia_atual, int linhas, int auxlm, int auxdm, int dia_maior)
{
    if (n == 0)
    {
        printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\n", p);
        printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\n", l);
        print_produtivo(dia_maior);
    }
    else
    {
        dia_atual++;

        int programas;
        if (dia_atual == 2)
        {
            auxlm = linhas;
            auxdm = 1;
        }

        scanf("%d%d", &programas, &linhas);
        
        if (programas >= 5)
        {
            p++;
        }

        if (linhas >= 100)
        {
            l++;
        }
        if (auxlm > linhas && dia_atual > 1)
        {
            linhas = auxlm;
            dia_maior = auxdm;
            loop(n - 1, p, l, dia_atual, linhas, auxlm, auxdm, dia_maior);
        }
        else if (linhas >= auxlm && dia_atual > 1)
        {
            auxlm = linhas;
            dia_maior = dia_atual;
            auxdm = dia_atual;
            loop(n - 1, p, l, dia_atual, linhas, auxlm, auxdm, dia_maior);
        }
        else
        {
            loop(n - 1, p, l, dia_atual, linhas, auxlm, auxdm, dia_maior);
        }
    }
}

int main() 
{
    loop(7, 0, 0, 0, 0, 0, 0, 0);

	return 0;
}