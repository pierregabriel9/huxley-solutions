#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int coprimo(int num1, int num2)
{
    if(num1 == 1 && num2 == 1)
    {
        return 1;
    }
    else if(num2 == 0)
    {
        if(num1 == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return coprimo(num2, num1 % num2);
    }
}

int primo(int n, int i)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    if(i > sqrt(n))
    {
        return 1;
    }
    else
    {
        if(n % i == 0)
        {
            return 0;
        }
        else
        {
            return primo(n, i + 1);
        }
    }
}

int batalha(int hab1, int atk1, int vd1, int hab2, int atk2, int vd2, int round, int rodada, int vez)
{
    if (vd1 <= 0)
    {
        return 2;
    }
    else if (vd2 <= 0)
    {
        return 1;
    }
    else
    {
        if(vez % 2 == 1)
        {
            if(hab1 == 1)
            {
                if(primo(round, 2))
                {
                    vd2 -= (atk1 * 2);
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round, rodada, vez + 1);
                }
                else
                {
                    vd2 -= atk1;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round, rodada, vez + 1);
                }
            }

            else if(hab1 == 2)
            {
                if(coprimo(vd1, vd2))
                {
                    atk1 += 25;
                    vd2 -= atk1;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round, rodada, vez + 1);
                }
                else
                {
                    vd2 -= atk1;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round, rodada, vez + 1);
                }
            }

            else if(hab1 == 3)
            {
                if(primo(vd1, 2) || primo(atk1, 2))
                {
                    atk1 += 10;
                    vd2 -= atk1;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round, rodada, vez + 1);
                }
                else
                {
                    vd2 -= atk1;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round, rodada, vez + 1);
                }
            }
        }


        else
        {
            if(hab2 == 1)
            {
                if(primo(round, 2))
                {
                    vd1 -= (atk2 * 2);
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round + 1, rodada, vez + 1);
                }
                else
                {
                    vd1 -= atk2;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round + 1, rodada, vez + 1);
                }
            }

            else if(hab2 == 2)
            {
                if(coprimo(vd1, vd2))
                {
                    atk2 += 25;
                    vd1 -= atk2;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round + 1, rodada, vez + 1);
                }
                else
                {
                    vd1 -= atk2;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round + 1, rodada, vez + 1);
                }
            }
            else if(hab2 == 3)
            {
                if(primo(vd2, 2) || primo(atk2, 2))
                {
                    atk2 += 10;
                    vd1 -= atk2;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round + 1, rodada, vez + 1);
                }
                else
                {
                    vd1 -= atk2;
                    batalha(hab1, atk1, vd1, hab2, atk2, vd2, round + 1, rodada, vez + 1);
                }
            }
        }    
    }
}

void rounde(int n, int pont_will, int pont_gab)
{
    if (n == 0)
    {
        printf("Will ganhou %d rodadas\n", pont_will);
        printf("Gabriel ganhou %d rodadas\n", pont_gab);
    }
    else
    {
        int inicia, will, gabriel;
        int hab_will, ataque_will, vida_will;
        int hab_gab, ataque_gab, vida_gab;

        scanf("%d", &inicia);
        scanf("%d%d%d", &hab_will, &ataque_will, &vida_will);
        scanf("%d%d%d", &hab_gab, &ataque_gab, &vida_gab);

        if (inicia == 1) // will
        {
            if (batalha(hab_will, ataque_will, vida_will, hab_gab, ataque_gab, vida_gab, 1, n, 1) == 1)
            {
                pont_will++;
            }
            else
            {
                pont_gab++;
            }
        }
        else // gabriel
        {
            if (batalha(hab_gab, ataque_gab, vida_gab, hab_will, ataque_will, vida_will, 1, n, 1) == 1)
            {
                pont_gab++;
            }
            else
            {
                pont_will++;
            }
        }

        rounde(n - 1, pont_will, pont_gab);
    }
}

int main() 
{
    int n;
    scanf("%d", &n);

    rounde(n, 0, 0);

	return 0;
}