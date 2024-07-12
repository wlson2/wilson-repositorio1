#include <stdio.h>

void generateFibonacci(int n, int fib[]) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

void separateOddEven(int n, int fib[], int odd[], int even[], int *numOdd, int *numEven) {
    *numOdd = 0;
    *numEven = 0;
    for (int i = 0; i < n; i++) {
        if (fib[i] % 2 == 0) {
            even[*numEven] = fib[i];
            (*numEven)++;
        } else {
            odd[*numOdd] = fib[i];
            (*numOdd)++;
        }
    }
}

int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void writeToFile(char *filename, int fib[], int n, int odd[], int numOdd, int even[], int numEven) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Write Fibonacci sequence
    fprintf(fp, "Fibonacci sequence: ");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d", fib[i]);
        if (i != n - 1) fprintf(fp, "-");
    }
    fprintf(fp, "\n");

    // Write odd numbers
    fprintf(fp, "Odd numbers: ");
    for (int i = 0; i < numOdd; i++) {
        fprintf(fp, "%d", odd[i]);
        if (i != numOdd - 1) fprintf(fp, "-");
    }
    fprintf(fp, "\n");

    // Write even numbers
    fprintf(fp, "Even numbers: ");
    for (int i = 0; i < numEven; i++) {
        fprintf(fp, "%d", even[i]);
        if (i != numEven - 1) fprintf(fp, "-");
    }
    fprintf(fp, "\n");

    // Sum of odd and even numbers
    int sumOdd = sumArray(odd, numOdd);
    int sumEven = sumArray(even, numEven);
    fprintf(fp, "Sum of odds: %d\n", sumOdd);
    fprintf(fp, "Sum of evens: %d\n", sumEven);

    fclose(fp);
}

int main() {
    int n = 50;
    int fib[50];
    int odd[50], even[50];
    int numOdd, numEven;

    // Generate Fibonacci sequence
    generateFibonacci(n, fib);

    // Separate odd and even numbers
    separateOddEven(n, fib, odd, even, &numOdd, &numEven);

    // Print results to console
    printf("Fibonacci sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d", fib[i]);
        if (i != n - 1) printf("-");
    }
    printf("\n");

    printf("Odd numbers: ");
    for (int i = 0; i < numOdd; i++) {
        printf("%d", odd[i]);
        if (i != numOdd - 1) printf("-");
    }
    printf("\n");

    printf("Even numbers: ");
    for (int i = 0; i < numEven; i++) {
        printf("%d", even[i]);
        if (i != numEven - 1) printf("-");
    }
    printf("\n");

    // Write results to file
    writeToFile("fibonacci_results.txt", fib, n, odd, numOdd, even, numEven);

    printf("Results written to fibonacci_results.txt\n");

    return 0;
}
