#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char determinarResultado(char matriz[][3]) {
    int venceu_x = 0;
    int venceu_o = 0;

    int qtd_x = 0;
    int qtd_o = 0;

    int total_x = 0;
    int total_o = 0;

    // Verifica na horizontal

    for(int i = 0; i < 3; i++) {
        qtd_x = 0;
        qtd_o = 0;

        for(int j = 0; j < 3; j++) {
            if(matriz[i][j] == 'X') {
                total_x++;
                qtd_x++;
            }
            else if(matriz[i][j] == 'O') {
                total_o++;
                qtd_o++;
            }
        }

        if(qtd_x == 3) {
            venceu_x++;
        }
        else if(qtd_o == 3) {
            venceu_o++;
        }
    }

    // Verifica se a diferenca é maior que 1

    if(abs(total_x - total_o) > 1) {
        return 'I';
    }

    // Verifica na vertical

    for(int i = 0; i < 3; i++) {
        qtd_x = 0;
        qtd_o = 0;

        for(int j = 0; j < 3; j++) {
            if(matriz[j][i] == 'X') {
                qtd_x++;
            }
            else if(matriz[j][i] == 'O') {
                qtd_o++;
            }
        }

        if(qtd_x == 3) {
            venceu_x++;
        }
        else if(qtd_o == 3) {
            venceu_o++;
        }
    }

    // Verifica diagonal principal

    qtd_x = 0;
    qtd_o = 0;

    for(int i = 0; i < 3; i++) {
        if(matriz[i][i] == 'X') {
            qtd_x++;
        }
        else if(matriz[i][i] == 'O') {
            qtd_o++;
        }
    }

    if(qtd_x == 3) {
        venceu_x++;
    }
    else if(qtd_o == 3) {
        venceu_o++;
    }

    // Verifica diagonal secundaria

    qtd_x = 0;
    qtd_o = 0;

    for(int i = 2, j = 0; j < 3; j++, i--) {
        if(matriz[i][j] == 'X') {
            qtd_x++;
        }
        else if(matriz[i][j] == 'O') {
            qtd_o++;
        }
    }

    if(qtd_x == 3) {
        venceu_x++;
    }
    else if(qtd_o == 3) {
        venceu_o++;
    }

    if(venceu_x == 1 && venceu_o == 0 && total_x > total_o) {
        return 'X';
    }
    else if(venceu_o == 1 && venceu_x == 0 && total_o >= total_x) {
        return 'O';
    }
    else if(venceu_x == 0 && venceu_o == 0) {
        return 'E';
    }
    else {
        return 'I';
    }
}

void lerMatriz(char matriz[][3]) {
    int qtd_x = 0;
    int qtd_o = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf(" %c", &matriz[i][j]);

            if(matriz[i][j] == 'X') {
                qtd_x++;
            }
            else if(matriz[i][j] == 'O') {
                qtd_o++;
            }
        }
    }
}

int main() 
{
    int n; scanf("%d", &n);
    char resultado;

    char matriz[3][3];

    for(int i = 0; i < n; i++) {
        lerMatriz(matriz);

        resultado = determinarResultado(matriz);

        if(resultado == 'X') {
            printf("X_VENCEU\n");
        }
        else if(resultado == 'O') {
            printf("O_VENCEU\n");
        }
        else if(resultado == 'I') {
            printf("ILEGAL\n");
        }
        else {
            printf("EM_ANDAMENTO\n");
        } 
    }

	return 0;
}