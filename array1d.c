#include <stdio.h>

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};

    int sizeA = sizeof(a) / sizeof(a[0]);
    int sizeB = sizeof(b) / sizeof(b[0]);

    int c[sizeA + sizeB];   // New array for concatenation

    // Copy array a into c
    for (int i = 0; i < sizeA; i++) {
        c[i] = a[i];
    }

    // Copy array b into c (starting from sizeA)
    for (int i = 0; i < sizeB; i++) {
        c[sizeA + i] = b[i];
    }

    // Print concatenated array
    printf("Concatenated array: ");
    for (int i = 0; i < sizeA + sizeB; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
