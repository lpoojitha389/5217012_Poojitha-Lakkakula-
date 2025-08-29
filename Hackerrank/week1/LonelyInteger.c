#include <stdio.h>
int main(){
    int n, num, result=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        result ^= num;
    }
    printf("%d\n", result);
    return 0;
}
