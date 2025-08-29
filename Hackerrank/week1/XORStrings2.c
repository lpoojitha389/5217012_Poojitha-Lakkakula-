#include <stdio.h>
#include <string.h>

int main() {
    char s[10001], t[10001];
    scanf("%s", s);
    scanf("%s", t);
    
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        // XOR of '1' and '0' gives '1', same bits give '0'
        if (s[i] == t[i])
            printf("0");
        else
            printf("1");
    }
    printf("\n");
    return 0;
}
