#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 10  // 'a' to 'j'


struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
};

struct TrieNode *createNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}


int insert(struct TrieNode *root, char *word) {
    struct TrieNode *curr = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        
        if (curr->isEndOfWord)
            return 0;

        if (!curr->children[index])
            curr->children[index] = createNode();

        curr = curr->children[index];
    }


    if (curr->isEndOfWord)
        return 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (curr->children[i])
            return 0;
    }

    curr->isEndOfWord = 1;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    char word[61];
    struct TrieNode *root = createNode();

    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        if (!insert(root, word)) {
            printf("BAD SET\n");
            printf("%s\n", word);
            return 0;
        }
    }

    printf("GOOD SET\n");
    return 0;
}
