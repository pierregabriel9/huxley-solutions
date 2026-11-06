#include <stdio.h>

int main()
{
    int operacao = -1;
    double valor;
    double creditos = 0;
    double debitos = 0;

    int operacoes[100][2];

    while(1)
    {
        scanf("%d", &operacao);

        if(operacao == 1)
        {
            scanf("%lf", &valor);
            creditos += valor;
        }
        else if(operacao == 0)
        {
            scanf("%lf", &valor);
            debitos += valor;
        }
        else
        {
            break;
        }
    }

    printf("Creditos: R$ %.2lf\n", creditos);
    printf("Debitos: R$ %.2lf\n", debitos);
    printf("Saldo: R$ %.2lf\n", creditos - debitos);

    return 0;
}