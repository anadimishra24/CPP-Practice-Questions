#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


bool isPalindrome(struct Node* head) {
    // getting the size of LL
    int size = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    // creating an array
    int arr[size];
    temp = head;
    for (int i = 0; i < size; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }

    // checking LL from both end for similar element
    int start = 0;
    int end = size - 1;
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}



int main() {
    struct Node* head = createNode(3);
    head->next = createNode(1);
    head->next->next = createNode(0);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(3);

    if (isPalindrome(head)) {
        printf("Yes.\n");
    } else {
        printf("No.\n");
    }


    return 0;
}
