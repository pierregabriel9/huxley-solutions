#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int qtd_alunos, cpc_supervisor, qtd_onibus, cpc_onibus;
    int qtd_supervisor, total_vagas, total_pessoas;
    scanf("%d%d%d%d", &qtd_alunos, &cpc_supervisor, &qtd_onibus, &cpc_onibus);


    if (qtd_alunos % cpc_supervisor != 0)
    {
        qtd_supervisor = (qtd_alunos / cpc_supervisor) + 1;
    }
    else
    {
        qtd_supervisor = qtd_alunos / cpc_supervisor;
    }
    total_vagas = qtd_onibus * cpc_onibus;
    total_pessoas = qtd_alunos + qtd_supervisor;

    if (qtd_alunos == 0)
    {
        printf("Davi foi assistir o filme sozinho =(\n");
    }
    else if (total_vagas - total_pessoas == 0)
    {
        printf("Iremos ao cinema!\nTodas as vagas foram preenchidas.\n");
    }
    else if (total_vagas - total_pessoas >= 0)
    {
        printf("Iremos ao cinema!\nVagas Vazias = %d\n", total_vagas - total_pessoas);
    }
    else
    {
        printf("Não é possível.\nFalta %d vagas.\n", total_pessoas - total_vagas);
    }
	return 0;
}