#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int val;
    int idx;
} Element;


int compare(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    if (e1->val < e2->val) return -1;
    if (e1->val > e2->val) return 1;
    return 0;
}

int lilysHomework(int arr[], int n) {
    Element* elements = (Element*)malloc(n * sizeof(Element));
    int* visited = (int*)calloc(n, sizeof(int));
    int i, swaps = 0;

    for (i = 0; i < n; i++) {
        elements[i].val = arr[i];
        elements[i].idx = i;
    }

    qsort(elements, n, sizeof(Element), compare);

 
    for (i = 0; i < n; i++) {
        if (visited[i] || elements[i].idx == i) continue;

        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = 1;
            j = elements[j].idx;
            cycle_size++;
        }

        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }

    free(elements);
    free(visited);
    return swaps;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int swaps_asc = lilysHomework(arr, n);

    int* inverted = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) inverted[i] = arr[i];

   
    int max_val = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max_val) max_val = arr[i];

    
    for (int i = 0; i < n; i++)
        inverted[i] = max_val - arr[i];

    int swaps_desc = lilysHomework(inverted, n);

    printf("%d\n", swaps_asc < swaps_desc ? swaps_asc : swaps_desc);

    free(arr);
    free(inverted);
    return 0;
}
