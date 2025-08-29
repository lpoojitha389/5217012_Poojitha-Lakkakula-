#include <stdio.h>
#include <stdlib.h>

long long arrayManipulation(int n, int m, int queries[m][3]) {
    long long *diff = (long long *)calloc(n + 2, sizeof(long long));
    long long maxVal = 0, current = 0;

    for (int i = 0; i < m; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];
        diff[a] += k;
        if (b + 1 <= n) {
            diff[b + 1] -= k;
        }
    }

    for (int i = 1; i <= n; i++) {
        current += diff[i];
        if (current > maxVal) {
            maxVal = current;
        }
    }

    free(diff);
    return maxVal;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int queries[m][3];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }

    printf("%lld\n", arrayManipulation(n, m, queries));
    return 0;
}
