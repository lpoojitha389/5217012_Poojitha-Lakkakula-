#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while(q--) {
        int d;
        scanf("%d", &d);

        int min_max = 1000001; 
        for(int i = 0; i <= n - d; i++) {
            int current_max = arr[i];
            for(int j = i + 1; j < i + d; j++) {
                if(arr[j] > current_max)
                    current_max = arr[j];
            }
            if(current_max < min_max)
                min_max = current_max;
        }
        printf("%d\n", min_max);
    }

    free(arr);
    return 0;
}
