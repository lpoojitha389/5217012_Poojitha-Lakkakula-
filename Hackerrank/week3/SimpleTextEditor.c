#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000
typedef struct {
    char** states;
    int top;
    int capacity;
} Stack;
void initStack(Stack* s, int capacity) {
    s->states = malloc(capacity * sizeof(char*));
    s->top = -1;
    s->capacity = capacity;
}
void push(Stack* s, const char* str) {
    if (s->top == s->capacity - 1) {
        s->capacity *= 2;
        s->states = realloc(s->states, s->capacity * sizeof(char*));
    }
    s->top++;
    s->states[s->top] = strdup(str); 
}

char* pop(Stack* s) {
    if (s->top == -1) return NULL;
    char* res = s->states[s->top];
    s->top--;
    return res;
}

void freeStack(Stack* s) {
    while (s->top >= 0) {
        free(s->states[s->top]);
        s->top--;
    }
    free(s->states);
}

int main() {
    int Q;
    scanf("%d", &Q);

    char* text = malloc(1);
    text[0] = '\0';
    int text_len = 0;

    Stack undoStack;
    initStack(&undoStack, 100);

    for (int i = 0; i < Q; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            char buf[100001];
            scanf("%s", buf);
            push(&undoStack, text);

            int add_len = strlen(buf);
            text = realloc(text, text_len + add_len + 1);
            strcpy(text + text_len, buf);
            text_len += add_len;

        } else if (op == 2) {
            int k;
            scanf("%d", &k);
            push(&undoStack, text);

            text_len -= k;
            text[text_len] = '\0';

        } else if (op == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", text[k-1]);

        } else if (op == 4) {
            char* prev = pop(&undoStack);
            if (prev != NULL) {
                free(text);
                text = prev;
                text_len = strlen(text);
            }
        }
    }
    free(text);
    freeStack(&undoStack);

    return 0;
}
