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

void insertAtPos(struct Node** head, int val, int pos){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = val;
    

    if (pos == 1) {
        node->next = *head;
        *head = node;
    }


    struct Node* current = *head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < pos - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        free(node);
        return;
    }

    node->next = current->next;
    current->next = node;
    return ;
   
}

void deleteFromStart(struct Node** head){

    if(*head == NULL){
        printf("\nList is empty.\n");
        return;
    }
    struct Node* temp = *head;
    
    *head = (*head)->next;

    free(temp);
}

void deleteFromEnd(struct Node** head){

    if (*head == NULL) {  
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;

    // Traverse the list until curr points to the last node
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    // curr now points to the last node
    // Set the next pointer of the second-to-last node to NULL
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        // If prev is NULL, it means curr was the only node in the list
        // Update the head to reflect the empty list
        *head = NULL;
    }

    // Free the memory of the last node
    free(curr);
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
    int num, val, pos, opt, del;
    // printf("Size = %d\n", sizeof(struct Node));
    
    while(1){
        printf("\n\t\t===== MENU =====\n");
        printf("\t1. Press 1 for insert from beginning.\n");
        printf("\t2. Press 2 for insert from end.\n");
        printf("\t3. Press 3 for insert at any position.\n");
        printf("\t-----------------------------------------\n");
        printf("\t4. Press 4 for delete first node.\n");
        printf("\t5. Press 5 for delet from last node.\n");
        printf("\t6. Press 6 for delete node by value.\n");
        printf("\t7. Press 7 for display the linked list.\n");
        printf("\t8. Press 0 for exit.\n");

        int op;
        printf("\n\tEnter your option here: ");
        scanf("%d",&op);

        switch (op){
            case 1:
                printf("Enter the number of elements you want to insert: ");
                scanf("%d",&num);

                printf("Enter the data you want to insert: ");
                for(int i = 0; i < num; i++){
                    scanf("%d",&val);
                    insertAtBeginning(&head, val);
                }
                break;

            case 2:
                printf("Enter the number of elements you want to insert: ");
                scanf("%d",&num);

                printf("Enter the data you want to insert: ");
                for(int i = 0; i < num; i++){
                    scanf("%d",&val);
                    insertAtEnd(&head, val);
                }
                break;

            case 3:
                printf("Enter the position at which you want to insert: ");
                scanf("%d",&pos);
                printf("Enter the data you want to insert: ");
                scanf("%d",&val);
                insertAtPos(&head, val, pos);             
                break;
            
            case 4:
                deleteFromStart(&head);
                break;

            case 5:
                deleteFromEnd(&head);
                break;

            case 6:
                printf("Enter a node value that should be deleted: ");
                scanf("%d",&del);
                deleteFromValue(&head,del);
                break;

            case 7:
                printLinkedList(head);
                break;

            case 0:
                printf("\n\tClosing the mneu and exiting from code.");
                return 0; 

            default:
                break;
        }
    }

}

    // int num, val;
    // printf("Enter the number of elements you want to insert: ");
    // scanf("%d",&num);

    // printf("Enter the data you want to insert: ");
    // for(int i = 0; i < num; i++){
    //     scanf("%d",&val);
    //    // insertAtBeginning(&head, val);
    //     insertAtEnd(&head, val);
    // }

    // printLinkedList(head);

    // int pos;
    // printf("Enter the data at position: ");
    // scanf("%d",&pos);
    // scanf("%d",&val);
    //    // insertAtBeginning(&head, val);
    // insertAtPos(&head, val, pos);
    // printLinkedList(head);
/*
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}
*/