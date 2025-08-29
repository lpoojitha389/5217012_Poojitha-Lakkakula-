#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
int stack1[MAX];
int stack2[MAX];
int top1 = -1;
int top2 = -1;
void push1(int x) {
    stack1[++top1] = x;
}
int pop1() {
    if (top1 == -1) return -1;
    return stack1[top1--];
}
void push2(int x) {
    stack2[++top2] = x;
}
int pop2() {
    if (top2 == -1) return -1;
    return stack2[top2--];
}
int isEmptyStack2() {
    return top2 == -1;
}
int peek2() {
    if (top2 == -1) return -1;
    return stack2[top2];
}
void transfer() {
    while (top1 != -1) {
        int x = pop1();
        push2(x);
    }
}

int main() {
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            push1(x);
        } else if (type == 2) {
            if (isEmptyStack2()) {
                transfer();
            }
            pop2();
        } else if (type == 3) {
            if (isEmptyStack2()) {
                transfer();
            }
            printf("%d\n", peek2());
        }
    }

    return 0;
}
