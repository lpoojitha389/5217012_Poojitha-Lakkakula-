#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int primary = 0, secondary = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (i == j)
                primary += val;
            if (i + j == n - 1)
                secondary += val;
        }
    }
    
    int diff = abs(primary - secondary);
    printf("%d\n", diff);
    
    return 0;
}
