#include <stdio.h>

int main() {
    int arr[] = {4, 7, 1, 9, 3};
    int n = 5, key = 9;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d", i);
            return 0;
        }
    }

    printf("Element not found");
    return 0;
}
