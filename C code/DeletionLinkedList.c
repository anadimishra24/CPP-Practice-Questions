#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*Linked List*/
struct Node{
    int data;
    struct Node *next;
};


void printLinkedList(struct Node* head){
    printf("Linked list: ");
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL");
}

void insertAtBeginning(struct Node** head, int val){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = val;
    node -> next = *head;
    *head = node;
}

void insertAtEnd(struct Node** head, int val){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = val;
    node -> next = NULL;

    // if list is empty
    if(*head == NULL){
        *head = node;
        return;
    }

    struct Node* curr = *head;

    // traverse the whole list till its NULL
    while(curr -> next != NULL){
        curr = curr -> next;
    }
    curr -> next = node;
   
}


void deleteFromStart(struct Node** head){

    struct Node* temp = *head;
    
    *head = (*head)->next;

    free(temp);
}

void deleteFromEnd(struct Node** head){

    struct Node* curr = *head;

    // traverse the whole list till its NULL
    while(curr -> next -> next != NULL){
        curr = curr -> next;
    }
    
    curr -> next = NULL;
    // free(curr -> next -> next);
}

void deleteFromValue(struct Node** head, int key) {
    struct Node* curr = *head;
    struct Node* prev = NULL;

    // Traverse the list to find the node with the specified key
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the key was not found, return (or you can print an error message)
    if (curr == NULL) {
        printf("Value %d not found in the linked list.\n", key);
        return;
    }

    // Update the pointers to remove the node with the specified key
    if (prev == NULL) {
        // If the key is found in the first node (head), update the head
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }

    // Free the memory occupied by the deleted node
    free(curr);
}


int main(){

    struct Node* head = NULL;
    
    // printf("Size = %d\n", sizeof(struct Node));
    
    int num, val;
    printf("Enter the number of elements you want to insert: ");
    scanf("%d",&num);

    printf("Enter the data you want to insert: ");
    for(int i = 0; i < num; i++){
        scanf("%d",&val);
       // insertAtBeginning(&head, val);
        insertAtEnd(&head, val);
    }

    printLinkedList(head);

    deleteFromStart(&head);
    printLinkedList(head);

    deleteFromEnd(&head);
    printLinkedList(head);

    deleteFromValue(&head,4);
    printLinkedList(head);

}
