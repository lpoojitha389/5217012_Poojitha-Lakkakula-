#include <stdio.h>
#include <stdlib.h>

// Comparator for ascending order
int compareAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Comparator for descending order
int compareDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

void checkPermutation(int n, int k, int A[], int B[]) {
    // Sort A ascending, B descending
    qsort(A, n, sizeof(int), compareAsc);
    qsort(B, n, sizeof(int), compareDesc);

    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] < k) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int A[n], B[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &B[i]);
        }

        checkPermutation(n, k, A, B);
    }

    return 0;
}
