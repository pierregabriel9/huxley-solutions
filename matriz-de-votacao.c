#include <stdio.h>

int main()
{
    int princesas, eleitores;
    int voto = 0;

    scanf("%d%d", &princesas, &eleitores);

    int votacao[eleitores][princesas];

    for(int i = 0; i < eleitores; i++)
    {
        for(int j = 0; j < princesas; j++)
        {
            scanf("%d", &votacao[i][j]);
        }
    }

    for(int i = 0; i < princesas; i++)
    {
        for(int j = 0; j < eleitores; j++)
        {
            if(votacao[j][i] == 1)
            {
                voto++;
            }
        }

        printf("Princesa %d: %d voto(s)\n", i + 1, voto);
        voto = 0;
    }

    return 0;
}