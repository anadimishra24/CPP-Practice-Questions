#include <stdio.h>
#include <string.h>


int isReverse(char word1[], char word2[]) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 != len2)
        return 0;

    for (int i = 0; i < len1; i++) {
        if (word1[i] != word2[len1 - i - 1])
            return 0;
    }

    return 1;
}


int countWordsLeft(char words[][100], int n) {
    int  rem_wrd[n];
    memset( rem_wrd, 0, sizeof( rem_wrd));

    int i = 0;

    while (i < n) {
        if (! rem_wrd[i]) {
            for (int j = i + 1; j < n; j++) {
                if (! rem_wrd[j] && isReverse(words[i], words[j])) {
                     rem_wrd[i] = 1;
                     rem_wrd[j] = 1;
                    break;
                }
            }
        }
        i++;
    }

    int count = 0;
    for (i = 0; i < n; i++) {
        if (! rem_wrd[i])
            count++;
    }

    return count;
}

int main() {
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);

    char words[n][100];
    printf("Enter the words:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    int result = countWordsLeft(words, n);
    printf("Number of words left in the array: %d\n", result);
  
    return 0;
}
