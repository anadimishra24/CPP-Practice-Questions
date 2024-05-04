#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
};



void printLinkedList(struct Node* head){
    printf("Linked list: ");
    struct Node* temp = head;

    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
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

void deleteMiddleNode(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        
        return;
    }

    struct Node* slowPtr = *head;
    struct Node* fastPtr = *head;
    struct Node* prev = NULL;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        fastPtr = fastPtr->next->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;
    }

    if (prev != NULL) {
      
        prev->next = slowPtr->next;
    } else {
        
        *head = slowPtr->next;
    }

    free(slowPtr); 
}

int main(){

    struct Node* head = NULL;
    
    int num, val;
    printf("Enter the number of elements to insert: ");
    scanf("%d",&num);

    printf("Enter the data you want to insert: ");
    for(int i = 0; i < num; i++){
        scanf("%d",&val);
        insertAtEnd(&head, val);
    }

    printLinkedList(head);

    printf("Deleting mid of linked list:");

    deleteMiddleNode(&head);

    printLinkedList(head);

}