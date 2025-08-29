#include <stdio.h>
#include <stdlib.h>

void findZigZagSequence(int a[], int n){
    int temp;
    // Sort array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int mid = (n - 1)/2;

    // Swap middle and last
    temp = a[mid];
    a[mid] = a[n - 1];
    a[n - 1] = temp;

    int st = mid + 1;
    int ed = n - 2;
    while(st <= ed){
        temp = a[st];
        a[st] = a[ed];
        a[ed] = temp;
        st = st + 1;
        ed = ed - 1;
    }

    for(int i = 0; i < n; i++){
        if(i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        findZigZagSequence(a, n);
    }
    return 0;
}
