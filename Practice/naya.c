#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createTableOfContent(int n, char** annotations) {
    for (int i = 0; i < n; i++) {
        if (annotations[i][0] == '@') {
            if (annotations[i][1] == '@') {
                // This is a sub-heading
                printf("1. %s\n", &annotations[i][2]);
            } else if (annotations[i][1] == '@@') {
                // This is a heading
                printf("2. %s\n", &annotations[i][2]);
            } else {
                // This is content of the last heading
                printf("1.%s\n", &annotations[i][3]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of sentences: ");
    scanf("%d", &n);

    // Clear the input buffer
    while ((getchar()) != '\n');

    char** annotations = (char**)malloc(n * sizeof(char*));

    printf("Enter the sentences:\n");
    for (int i = 0; i < n; i++) {
        printf("Sentence %d: ", i + 1);
        char buffer[100];
        scanf(" %[^\n]", buffer);

        // Allocate memory for the sentence and copy it to the annotations array
        annotations[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(annotations[i], buffer);
    }

    printf("\nTable of Content:\n");
    createTableOfContent(n, annotations);

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(annotations[i]);
    }
    free(annotations);

    return 0;
}
