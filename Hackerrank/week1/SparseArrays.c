#include <stdio.h>
#include <string.h>
#define MAX_N 1000
#define MAX_LEN 21
int main() {
    int n,q;
    char strings[MAX_N][MAX_LEN];
    char queries[MAX_N][MAX_LEN];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", strings[i]);
    }
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        scanf("%s", queries[i]);
    }
    for (int i=0; i<q; i++) {
        int count=0;
        for (int j=0; j<n; j++) {
            if (strcmp(queries[i], strings[j])==0) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
