#include <stdio.h>

int verificacao(int leituras[], int qtd_leituras, int capacidade, int total, int i, int passou)
{
	if(i == qtd_leituras * 2)
	{
		return passou;
	}
	else
	{
		if(i % 2 == 0)
		{
			total -= leituras[i];
		}
		else
		{
			total += leituras[i];

			if(total > capacidade)
			{
				passou = 1;
			}
		}

		return verificacao(leituras, qtd_leituras, capacidade, total, i + 1, passou);
	}
}

void loop(int leituras[], int qtd_leituras, int capacidade, int i)
{
	if(i >= qtd_leituras * 2)
	{
		int passou = verificacao(leituras, qtd_leituras, capacidade, 0, 0, 0);

		if(passou == 0)
		{
			printf("N\n");
		}
		else
		{
			printf("S\n");
		}
	}
	else
	{
		int saiu, entrou;
		scanf("%d%d", &saiu, &entrou);

		leituras[i] = saiu;
		leituras[i + 1] = entrou;

		loop(leituras, qtd_leituras, capacidade, i + 2);
	}
}

int main() 
{
	int qtd_leituras, capacidade;
	scanf("%d%d", &qtd_leituras, &capacidade);

	int leituras[qtd_leituras * 2];

	loop(leituras, qtd_leituras, capacidade, 0);

	return 0;
}