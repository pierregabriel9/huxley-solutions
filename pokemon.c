#include <stdio.h>
#include <math.h>

void batalha(int v1, int v2, int d1, int d2)
{
    int r_clodes, r_bezaliel;

    if (v2 <= 0)
    {
        printf("Clodes\n");
    }
    else if (v1 <= 0)
    {
        printf("Bezaliel\n");
    }
    else
    {
        r_clodes = v2 / d1;
        if (v2 % d1 != 0)
        {
            r_clodes += 1;
        }
        r_bezaliel = v1 / d2;
        if (v1 % d2 != 0)
        {
            r_bezaliel += 1;
        }
        
        if (r_clodes <= r_bezaliel)
        {
            v2 -= d1;
            v1 -= d2;
            batalha(v1, v2, d1, d2);
        }
        else
        {
            d1 += 50;
            v1 -= d2;
            batalha(v1, v2, d1, d2);
        }
    }
}

void loop(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        int v1, v2, d1, d2;
        scanf("%d%d%d%d", &v1, &v2, &d1, &d2);

        batalha(v1, v2, d1, d2);

        loop(n - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    loop(n);

    return 0;
}