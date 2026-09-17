#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int luta(int yuri, int kaio)
{
    if (yuri == 1 && (kaio == 0 || kaio == 4))
    {
        return 2;
    }
    else if (yuri == 2 && (kaio == 0 || kaio == 1))
    {
        return 2;
    }
    else if (yuri == 3 && (kaio == 1 || kaio == 2))
    {
        return 2;
    }
    else if (yuri == 4 && (kaio == 2 || kaio == 3))
    {
        return 2;
    }
    else if (yuri == 0 && (kaio == 4 || kaio == 3))
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void loop(int n, int pont_yuri, int pont_kaio)
{
    if (n == 0)
    {
        if (pont_yuri < pont_kaio)
        {
            printf("Yuri foi o perdedor.\n");
        }
        else
        {
            printf("Kaio foi o perdedor.\n");
        }
    }
    else
    {
        int yuri, kaio;
        scanf("%d%d", &yuri, &kaio);

        int vencedor = luta(yuri, kaio);

        if (vencedor == 1)
        {
            pont_yuri++;
        }
        else
        {
            pont_kaio++;
        }

        loop(n - 1, pont_yuri, pont_kaio);
    }
}


int main() 
{
    int n;
    scanf("%d", &n);

    loop(n, 0, 0);

	return 0;
}