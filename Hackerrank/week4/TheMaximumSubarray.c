#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void maxSubarray(int arr[], int n) {
    int maxSubarraySum = arr[0];
    int currentSum = arr[0];
    int maxSubsequenceSum = (arr[0] > 0) ? arr[0] : 0;

    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSubarraySum = max(maxSubarraySum, currentSum);

        if (arr[i] > 0) {
            maxSubsequenceSum += arr[i];
        }
    }

    if (maxSubsequenceSum == 0) {
        maxSubsequenceSum = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxSubsequenceSum) {
                maxSubsequenceSum = arr[i];
            }
        }
    }

    printf("%d %d\n", maxSubarraySum, maxSubsequenceSum);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        maxSubarray(arr, n);
    }

    return 0;
}
