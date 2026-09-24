#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    double cot_dolar, aliquota, valor_prod, valor_frete;

    scanf("%lf%lf%lf%lf", &cot_dolar, &aliquota, &valor_prod, &valor_frete);

    double imp_de_importacao, icms, total_imp, total_global, valor_final_prod;

    printf("%.2lf\n", cot_dolar);
    printf("%.2lf\n", valor_prod * cot_dolar);
    printf("%.2lf\n", valor_frete * cot_dolar);

    double total_sem_imp = valor_prod * cot_dolar + valor_frete * cot_dolar;

    printf("%.2lf\n", total_sem_imp);

    if(valor_prod >= 2500)
    {
        imp_de_importacao = (total_sem_imp - (valor_frete * cot_dolar)) * 0.6;
        valor_final_prod = (total_sem_imp - (valor_frete * cot_dolar) + imp_de_importacao)/(1 - (aliquota/100));
    }
    else
    {
        imp_de_importacao = total_sem_imp * 0.6;
        valor_final_prod = (total_sem_imp + imp_de_importacao)/(1 - (aliquota/100));
    }

    printf("%.2lf\n", imp_de_importacao);

    icms = valor_final_prod * (aliquota/100);
    double valor_imps = imp_de_importacao + icms;

    printf("%.2lf\n", icms);
    printf("%.2lf\n", valor_imps);

    printf("%.2lf\n", total_sem_imp + valor_imps);

    if(valor_prod >= 2500)
    {
        printf("Impostos calculados sem o frete\n");
    }
    else
    {
        printf("Impostos calculados com o frete\n");
    }

	return 0;
}