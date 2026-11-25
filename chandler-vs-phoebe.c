    #include <stdio.h>

    int main() {
        int n;
        scanf("%d", &n);

        int matriz[n][n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &matriz[j][i]);

                if(matriz[j][i] < 0) { 
                    matriz[j][i] *= 2;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j + 1 != n) {
                    printf("%d ", matriz[i][j]);
                }
                else {
                    printf("%d\n", matriz[i][j]);
                }  
            }
        }
    }