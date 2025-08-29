#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

// Min-heap implementation
int heap[MAX_SIZE];
int heapSize = 0;

// Function to swap elements
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Heapify up
void heapifyUp(int idx) {
    while (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
        swap(&heap[(idx - 1) / 2], &heap[idx]);
        idx = (idx - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heapSize && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heapSize && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void insertHeap(int val) {
    heap[heapSize++] = val;
    heapifyUp(heapSize - 1);
}

// Extract min from heap
int extractMin() {
    int min = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return min;
}

// Get min without removing
int peekMin() {
    return heap[0];
}

int cookies(int k, int arr[], int n) {
    heapSize = 0;

    for (int i = 0; i < n; i++) {
        insertHeap(arr[i]);
    }

    int ops = 0;

    while (heapSize >= 2 && peekMin() < k) {
        int least = extractMin();
        int second = extractMin();
        int combined = least + 2 * second;
        insertHeap(combined);
        ops++;
    }

    if (heapSize > 0 && peekMin() >= k) {
        return ops;
    }

    return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = cookies(k, arr, n);
    printf("%d\n", result);

    return 0;
}
