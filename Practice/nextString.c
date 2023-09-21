#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for linked list
struct Node {
    char data;
    struct Node* next;
};

// Function to insert a new node at the head of the linked list
void insertAtHead(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if a character already exists in the linked list
int alreadyExist(struct Node* head, char ch) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == ch) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    // Create a new node
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 'a';
    node1->next = NULL;

    struct Node* head = node1;

    // Insert elements at the head of the linked list
    insertAtHead(&head, 'b');
    insertAtHead(&head, 'c');
    insertAtHead(&head, 'd');

    printf("Linked List: ");
    print(head);

    char ch;
    printf("Enter your character: ");
    scanf(" %c", &ch);
    printf("Linked List: ");

    if (!alreadyExist(head, ch)) {
        insertAtHead(&head, ch);
        print(head);
    } else {
        printf("Character already used in Linked List.\n");
    }

    return 0;
}
