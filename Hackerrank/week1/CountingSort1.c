#include <stdio.h>
#include <stdlib.h>

int* countingSort(int arr_count, int* arr, int* result_count) {
    int* freq = (int*)calloc(100, sizeof(int));  // frequency array initialized to 0
    for (int i = 0; i < arr_count; i++) {
        freq[arr[i]]++;
    }
    *result_count = 100;
    return freq;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result_count;
    int* result = countingSort(n, arr, &result_count);

    // Print exactly as HackerRank expects: values separated by spaces
    for (int i = 0; i < result_count; i++) {
        printf("%d", result[i]);
        if (i < result_count - 1) {
            printf(" ");
        }
    }
    printf("\n");  // end with newline

    free(arr);
    free(result);
    return 0;
}
