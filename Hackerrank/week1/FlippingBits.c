#include <stdio.h>
int main() {
    int q;
    unsigned int n;
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        scanf("%u", &n);
        unsigned int flipped=n^0xFFFFFFFF;
        printf("%u\n", flipped);
    }
    return 0;
}
