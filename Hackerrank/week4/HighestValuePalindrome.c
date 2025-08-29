#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void highestValuePalindrome(char s[], int n, int k) {
    int left = 0, right = n - 1;
    int changes_needed = 0;
    int *changed = (int *)calloc(n, sizeof(int)); 
    
   
    while (left < right) {
        if (s[left] != s[right]) {
            changes_needed++;
        }
        left++;
        right--;
    }

    if (changes_needed > k) {
        printf("-1\n");
        free(changed);
        return;
    }

    left = 0;
    right = n - 1;
    int remaining_changes = k;
\
    while (left <= right) {
        if (left == right) {
            
            if (remaining_changes > 0 && s[left] != '9') {
                s[left] = '9';
            }
            break;
        }

        if (s[left] != s[right]) {
           
            char max_char = s[left] > s[right] ? s[left] : s[right];
            if (max_char != '9' && remaining_changes - 1 >= changes_needed) {
                s[left] = '9';
                s[right] = '9';
                remaining_changes -= 2;
            } else {
                s[left] = max_char;
                s[right] = max_char;
                remaining_changes--;
            }
            changes_needed--;
            changed[left] = changed[right] = 1;
        } else {
            
            if (remaining_changes - 2 >= changes_needed && s[left] != '9') {
                s[left] = '9';
                s[right] = '9';
                remaining_changes -= 2;
            }
        }

        left++;
        right--;
    }

    printf("%s\n", s);
    free(changed);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char s[n + 1];
    scanf("%s", s);

    highestValuePalindrome(s, n, k);

    return 0;
}
