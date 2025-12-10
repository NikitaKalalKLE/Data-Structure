#include <stdio.h>

int main() {
    int n;
    printf("Enter size of square matrix (n): ");
    scanf("%d", &n);

    float a[10][10], inv[10][10];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
            inv[i][j] = (i == j) ? 1 : 0;  // identity matrix
        }
    }

    // Applying Gauss-Jordan Elimination
    for (int i = 0; i < n; i++) {
        float pivot = a[i][i];

        if (pivot == 0) {
            printf("Matrix is singular... No inverse exists!\n");
            return 0;
        }

        // Make pivot element = 1
        for (int j = 0; j < n; j++) {
            a[i][j] /= pivot;
            inv[i][j] /= pivot;
        }

        // Make other rows = 0 in this column
        for (int r = 0; r < n; r++) {
            if (r != i) {
                float factor = a[r][i];
                for (int c = 0; c < n; c++) {
                    a[r][c] -= factor * a[i][c];
                    inv[r][c] -= factor * inv[i][c];
                }
            }
        }
    }

    printf("\nInverse of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%0.3f  ", inv[i][j]);
        printf("\n");
    }

    return 0;
}
