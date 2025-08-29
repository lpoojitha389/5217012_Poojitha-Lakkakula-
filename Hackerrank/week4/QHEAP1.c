#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 1000000

typedef long long ll;

ll heap[MAX_HEAP_SIZE];
int size = 0;

void swap(ll* a, ll* b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify_down(int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(smallest);
    }
}

void insert(ll val) {
    heap[size] = val;
    heapify_up(size);
    size++;
}

int find_index(ll val) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == val) return i;
    }
    return -1;
}

void delete(ll val) {
    int index = find_index(val);
    if (index == -1) return;

    heap[index] = heap[size - 1];
    size--;
    heapify_down(index);
    heapify_up(index);  
}

void print_min() {
    if (size > 0) {
        printf("%lld\n", heap[0]);
    }
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        ll val;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%lld", &val);
            insert(val);
        } else if (type == 2) {
            scanf("%lld", &val);
            delete(val);
        } else if (type == 3) {
            print_min();
        }
    }

    return 0;
}
