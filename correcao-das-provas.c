#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_dados(double notas[], double qtd_aprovados, double nota_mais_freq, int qtd_alunos, int i)
{
    if(i == qtd_alunos)
    {
        printf("%.1lf%%\n", qtd_aprovados);
        printf("%.1lf\n", nota_mais_freq);
        return;
    }

    printf("%d %.1lf\n", i + 1, notas[i]);

    print_dados(notas, qtd_aprovados, nota_mais_freq, qtd_alunos, i + 1);
}

int maior_freq(int freq_notas[], int i, int maior)
{
    if(i == 11)
    {
        return maior;
    }

    if(freq_notas[i] > freq_notas[maior])
    {
        maior = i;
    }

    return maior_freq(freq_notas, i + 1, maior);
}

int calc_freq(int freq_notas[], double notas[], int qtd_alunos, int i)
{
    if(i == qtd_alunos)
    {
        return maior_freq(freq_notas, 0, 0);
    }

    freq_notas[(int) notas[i]]++;

    return calc_freq(freq_notas, notas, qtd_alunos, i + 1);
}

double calc_aprovados(double notas[], int qtd_alunos, int i, double aprovados)
{
    if(i == qtd_alunos)
    {
        return (aprovados/qtd_alunos) * 100;
    }
    
    if(notas[i] >= 6)
    {
        aprovados++;
    }

    return calc_aprovados(notas, qtd_alunos, i + 1, aprovados);
}

double calculo_nota(char gabarito[], char resposta[], int i, int pontuacao)
{
    if(i == 10)
    {
        return pontuacao;
    }
    
    if(gabarito[i] == resposta[i])
    {
        pontuacao++;
    }

    return calculo_nota(gabarito, resposta, i + 1, pontuacao);
}

int leitura_individual(char gabarito[], double notas[], int i, int qtd_alunos)
{
    int n_aluno;
    scanf("%d", &n_aluno);

    if(n_aluno == 9999)
    {
        return qtd_alunos;
    }

    char resposta[11];
    scanf("%s", resposta);

    notas[i] = calculo_nota(gabarito, resposta, 0, 0);

    qtd_alunos++;

    return leitura_individual(gabarito, notas, i + 1, qtd_alunos);
}

int main() 
{
    char gabarito[11];
    fgets(gabarito, 11, stdin);

    double notas[9999];

    int qtd_alunos = leitura_individual(gabarito, notas, 0, 0);

    double qtd_aprovados = calc_aprovados(notas, qtd_alunos, 0, 0);

    int freq_notas[11] = {0};

    double nota_mais_freq = calc_freq(freq_notas, notas, qtd_alunos, 0);

    print_dados(notas, qtd_aprovados, nota_mais_freq, qtd_alunos, 0);

	return 0;
}