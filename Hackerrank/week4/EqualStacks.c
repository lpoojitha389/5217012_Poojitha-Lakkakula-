#include <stdio.h>
#include <stdlib.h>

int stack_sum(int* stack, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += stack[i];
    return sum;
}

int equalStacks(int* h1, int n1, int* h2, int n2, int* h3, int n3) {
    int i = 0, j = 0, k = 0;
    int sum1 = stack_sum(h1, n1);
    int sum2 = stack_sum(h2, n2);
    int sum3 = stack_sum(h3, n3);

    while (i < n1 && j < n2 && k < n3) {
        
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;


        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= h1[i++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= h2[j++];
        else
            sum3 -= h3[k++];
    }

    return 0; 
}

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int* h1 = (int*)malloc(n1 * sizeof(int));
    int* h2 = (int*)malloc(n2 * sizeof(int));
    int* h3 = (int*)malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++) scanf("%d", &h1[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &h2[i]);
    for (int i = 0; i < n3; i++) scanf("%d", &h3[i]);

    int result = equalStacks(h1, n1, h2, n2, h3, n3);
    printf("%d\n", result);

    free(h1);
    free(h2);
    free(h3);
    return 0;
}
