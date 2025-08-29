#include <stdio.h>

int sockMerchant(int n, int ar[]) {
    int colorCount[101] = {0};  // Array to count colors (1 to 100)
    int pairs = 0;

    // Count the number of each color
    for (int i = 0; i < n; i++) {
        colorCount[ar[i]]++;
    }

    // Calculate number of pairs
    for (int i = 1; i <= 100; i++) {
        pairs += colorCount[i] / 2;
    }

    return pairs;
}

int main() {
    int n;
    scanf("%d", &n);

    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    int result = sockMerchant(n, ar);
    printf("%d\n", result);

    return 0;
}
