#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node in the linked list
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to find the first duplicate number in the linked list
int findFirstDuplicate(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return -1;

    // Create a hash set to store the seen numbers
    bool* seen = (bool*)calloc(1000001, sizeof(bool));

    struct ListNode* current = head;

    while (current != NULL) {
        if (seen[current->val])
            return current->val;

        seen[current->val] = true;
        current = current->next;
    }
    free(seen);
    return -1;
}

// Function to free the memory used by the linked list
void freeLinkedList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int N;
    printf("Enter the size of the LinkedList: ");
    scanf("%d", &N);

    int numList[N];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &numList[i]);
    }

    // Create the linked list from the array
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < N; i++) {
        struct ListNode* newNode = createNode(numList[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int result = findFirstDuplicate(head);
    printf("First duplicate number: %d\n", result);

    
    freeLinkedList(head);

    return 0;
}
