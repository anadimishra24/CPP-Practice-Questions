#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertAtEnd(struct Node** head, char d) {
    struct Node* temp = createNode(d);

    if (*head == NULL) {
        *head = temp;
    } else {
        struct Node* ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

// Function to print linked list
void print(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the first duplicate data in a sorted linked list
int findDuplicateData(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            return temp->data;
        }
        temp = temp->next;
    }
    return -1;
}

// Function to find the first repeated data in an unsorted linked list
int findRepeatedData(struct Node* head) {
    printf("calling function repeated\n");
    struct Node* temp = head;

    while (temp != NULL) {
        int dat = temp->data;
        struct Node* ptr = temp->next;
        while (ptr != NULL) {
            printf("Data : %c\n", ptr->data);
            if (dat == ptr->data) {
                return ptr->data;
            }
            ptr = ptr->next;
        }
        temp = temp->next;
    }
    return -1;
}

// Function to check if a character already exists in the linked list
bool alreadyExist(struct Node* head, char ch) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == ch) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    struct Node* head = NULL;

    // Create a new node
    struct Node* node1 = createNode('a');
    head = node1;

    // Insert elements at the end of the linked list
    insertAtEnd(&head, 'b');
    insertAtEnd(&head, 'c');
    insertAtEnd(&head, 'd');

    printf("Linked List: ");
    print(head);

    char ch;
    printf("Enter your character: ");
    scanf(" %c", &ch);
    printf("Linked List: ");

    if (!alreadyExist(head, ch)) {
        insertAtEnd(&head, ch);
        print(head);
    } else {
        printf("Character already used in Linked List.\n");
    }

    return 0;
}
