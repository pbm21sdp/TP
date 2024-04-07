#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double* elementePare(int n, ...) {
    double* vector = (double*)malloc(n * sizeof(double));
    if (vector == NULL) {
        printf("Eroare la alocarea memoriei!");
        return NULL;
    }
    va_list va;
    va_start(va, n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        double num = va_arg(va, double);
        if ((int)num % 2) == 0) {
            vector[count] = num;
            count++;
        }
    }
    va_end(va);
    vector = (double*)realloc(vector, count * sizeof(double));
    return vector;
}

int main() {
    int n = 6;
    double* result = elementePare(n, 1.5, 2.8, 3.2, 4.7, 5.0, 6.3);
    printf("Elementele pare: ");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", result[i]);
    }
    free(result);
    return 0;
}
