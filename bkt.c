#include <stdio.h>

// Funcție pentru a număra cifrele de 1 dintr-un număr
int onesCount(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 10 == 1) {
            count++;
        }
        num /= 10;
    }
    return count;
}

// Funcție pentru a afișa un vector de cifre
void printDigits(int digits[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", digits[i]);
    }
    printf("\n");
}

// Funcție pentru a genera și afișa numerele
void generateNumbers(int digits[], int n, int k, int pos, int onesCount) {
    if (pos == n) {
        if (onesCount == k) {
            printDigits(digits, n);
        }
        return;
    }

    // Încercăm să punem 1 pe poziția curentă
    digits[pos] = 1;
    generateNumbers(digits, n, k, pos + 1, onesCount + 1);

    // Încercăm să punem 0 pe poziția curentă
    digits[pos] = 0;
    generateNumbers(digits, n, k, pos + 1, onesCount);
}

int main() {
    int n, k;
    printf("Introduceti numarul n: ");
    scanf("%d", &n);
    printf("Introduceti numarul k: ");
    scanf("%d", &k);

    int digits[10]; // Putem utiliza un vector de lungime maximă 10 pentru cifrele 0 și 1

    generateNumbers(digits, n, k, 0, 0);

    return 0;
}
