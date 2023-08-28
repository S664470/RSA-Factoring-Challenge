#include <stdio.h>

void factorizeNumber(int number) {
    int i, factor1, factor2;
    for (i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            factor1 = i;
            factor2 = number / i;
            printf("%d=%d*%d\n", number, factor1, factor2);
            return;  // Stop factorizing after finding the first factorization
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int number;
    while (fscanf(file, "%d\n", &number) != EOF) {
        factorizeNumber(number);
    }

    fclose(file);
    return 0;
}
