#include <stdio.h>

void miniMaxSum(long long arr[5]) {
    long long total = 0;
    long long min = arr[0], max = arr[0];

    for (int i = 0; i < 5; i++) {
        total += arr[i];

        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    printf("%lld %lld\n", total - max, total - min);
}

int main() {
    long long arr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%lld", &arr[i]);
    }

    miniMaxSum(arr);
    return 0;
}
