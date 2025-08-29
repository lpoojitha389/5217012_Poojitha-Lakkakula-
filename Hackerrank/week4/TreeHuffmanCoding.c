#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 512
#define MAX_CHAR 256

typedef struct node {
    char data;
    int freq;
    struct node* left;
    struct node* right;
} node;

typedef struct {
    node* nodes[MAX_TREE_NODES];
    int size;
} MinHeap;

node* createNode(char data, int freq) {
    node* n = malloc(sizeof(node));
    n->data = data;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void swap(node** a, node** b) {
    node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < heap->size && heap->nodes[left]->freq < heap->nodes[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->nodes[right]->freq < heap->nodes[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->nodes[smallest], &heap->nodes[idx]);
        minHeapify(heap, smallest);
    }
}

node* extractMin(MinHeap* heap) {
    node* minNode = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return minNode;
}

void insertMinHeap(MinHeap* heap, node* n) {
    heap->size++;
    int i = heap->size - 1;
    heap->nodes[i] = n;

    while (i && heap->nodes[(i-1)/2]->freq > heap->nodes[i]->freq) {
        swap(&heap->nodes[i], &heap->nodes[(i-1)/2]);
        i = (i-1)/2;
    }
}

MinHeap* createAndBuildMinHeap(int freq[MAX_CHAR]) {
    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->size = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            insertMinHeap(heap, createNode((char)i, freq[i]));
        }
    }
    return heap;
}

node* buildHuffmanTree(int freq[MAX_CHAR]) {
    MinHeap* heap = createAndBuildMinHeap(freq);

    while (heap->size > 1) {
        node* left = extractMin(heap);
        node* right = extractMin(heap);

        node* top = createNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(heap, top);
    }

    node* root = extractMin(heap);
    free(heap);
    return root;
}

void buildCodes(node* root, char* code, int top, char codes[MAX_CHAR][MAX_CHAR]) {
    if (!root) return;

    if (!root->left && !root->right) {
        code[top] = '\0';
        strcpy(codes[(unsigned char)root->data], code);
        return;
    }

    code[top] = '0';
    buildCodes(root->left, code, top + 1, codes);

    code[top] = '1';
    buildCodes(root->right, code, top + 1, codes);
}

void encodeString(char* input, char codes[MAX_CHAR][MAX_CHAR], char* encoded) {
    encoded[0] = '\0';
    for (int i = 0; input[i]; i++) {
        strcat(encoded, codes[(unsigned char)input[i]]);
    }
}

void decode_huff(node *root, char *s) {
    node *curr = root;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (!curr->left && !curr->right) {
            printf("%c", curr->data);
            curr = root;
        }
    }
    printf("\n");
}

void freeTree(node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char input[1024];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;  // Remove newline

    int freq[MAX_CHAR] = {0};
    for (int i = 0; input[i]; i++) {
        freq[(unsigned char)input[i]]++;
    }

    node* root = buildHuffmanTree(freq);

    char codes[MAX_CHAR][MAX_CHAR] = {{0}};
    char code[MAX_CHAR];
    buildCodes(root, code, 0, codes);

    char encoded[8192];
    encodeString(input, codes, encoded);

    // Decode and print result
    decode_huff(root, encoded);

    freeTree(root);
    return 0;
}
