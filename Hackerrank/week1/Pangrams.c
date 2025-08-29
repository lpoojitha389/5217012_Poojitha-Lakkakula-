#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* pangrams(char* s) {
    static char result[20];
    int freq[26] = {0};
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            int index = tolower(s[i]) - 'a';
            freq[index] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) {
            strcpy(result, "not pangram");
            return result;
        }
    }

    strcpy(result, "pangram");
    return result;
}

int main() {
    char s[1001];
    fgets(s, sizeof(s), stdin);

    // Remove trailing newline if present
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    printf("%s\n", pangrams(s));
    return 0;
}
