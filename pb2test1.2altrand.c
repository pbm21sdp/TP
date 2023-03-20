#include <stdio.h>

int main() {
    int n, i, j, k, ok;
    printf("Introduceti dimensiunea matricei patratice: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Introduceti elementele matricei: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &k);
    int v[k];
    printf("Introduceti elementele vectorului: \n");
    for(i = 0; i < k; i++) {
        scanf("%d", &v[i]);
    }
    for(j = 0; j < n; j++) {
        for(i = 0; i <= n-k; i++) {
            ok = 1;
            for(int l = 0; l < k; l++) {
                if(a[i+l][j] != v[l]) {
                    ok = 0;
                    break;
                }
            }
            if(ok == 1) {
                printf("Vectorul apare in matrice pe coloana %d.\n", j+1);
                return 0;
            }
        }
    }
    printf("Vectorul nu apare in matrice pe verticala.\n");
    return 0;
}
