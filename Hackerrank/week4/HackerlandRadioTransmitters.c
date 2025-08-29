#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int hackerlandRadioTransmitters(int x[], int n, int k) {
    qsort(x, n, sizeof(int), cmp);
    
    int i = 0, count = 0;
    while (i < n) {
        count++;

        int loc = x[i] + k;
        while (i < n && x[i] <= loc) {
            i++;
        }

    
        int tower = x[i - 1];
        loc = tower + k;

        while (i < n && x[i] <= loc) {
            i++;
        }
    }

    return count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    int result = hackerlandRadioTransmitters(x, n, k);
    printf("%d\n", result);

    return 0;
}
