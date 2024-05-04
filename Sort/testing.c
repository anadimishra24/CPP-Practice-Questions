#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
    Ques: https://leetcode.com/problems/merge-sorted-array/
    Video: https://www.youtube.com/watch?v=MPvr-LmaZmA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=21
*/

/* Merge Sorted Array
void printArr(int arr[], int size){
    for(int i = 0; i < size ; i++){
        printf("%d , ", arr[i]);
    }
}

void mergeSortedArr(int arr[], int aSize, int brr[], int bSize){

    int i = 0, j = 0;

    while(i < aSize && j < bSize){

        if((arr[i] <= brr[j]) && arr[i] != 0){
            i++;
        }
        else{
            //shift array element to 1 place
            arr[i+1] = arr[i];
            
            arr[i] = brr[j];
            j++;
            i++;
        }
    }

}


int main(){

    int arr[] = { 1, 2, 3, 0, 0, 0 };  
    int brr[] = { 2, 5, 6};               // Output: 1 , 2 , 2 , 3 , 5 , 6 

    int aSize  = sizeof(arr)/sizeof(int);
    int bSize  = sizeof(brr)/sizeof(int);


    // calling function for merge two sorted array
    mergeSortedArr(arr, aSize, brr, bSize);

    

    printf("Merged array: ") ;
    printArr(arr, aSize);

    return 0;

}
*/


/* Remove duplicates character from string
void removeDuplicate(char *token){

    int len = strlen(token);

    int end = 1;
    for (int i = 1; i < len; i++){
        int j;
        for (j = 0; j < end; j++){
            if(token[i] == token[j]){
                break;
            }
        }
        if(j == end){
            token[end] = token[i];
            end++;
        }
    }
    token[end] = '\0';
}


int main(){

    char s[] = "lel dodge";

    printf("The default string is: %s", s);
    
    char *token = strtok(s, " ");
    while(token != NULL){
        removeDuplicate(token);
        printf("\nThe resultant string is: %s \n", token);
        token = strtok(NULL, " ");
    }
    
    return 0;
}
*/


/* Prime numbers 1 to 100
int main(){

    for (int i = 2; i < 100; i++){
        int flag = 0;
        for (int j = 2; j < i; j++){
            if(i % j == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("%d ", i);
        }
        
    }
    return 0;
}
*/


/* Pallinf=drome of string without case sensitive
char toLower(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int main(){

    char *name = "Noon";

    int len = strlen(name);

    int i = 0, flag = 1;
    int j = len - 1;
    while(i < len){
        if(toLower(name[i]) != toLower(name[j])){
            flag = 0;
            break;
        }
        else{
            i++;
            j--;
        }
    }
    if(flag == 0){
        printf("\nNot pallindrome.\n");
    }
    else{
        printf("\nPallindrome.\n");
    }
    
    

    return 0;
}
*/

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

// Function to delete the middle node of a linked list
void deleteMiddleNode(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // If the list is empty or has only one element, there is no middle to delete.
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

    // At this point, slowPtr points to the middle node, and prev points to the node before it.

    if (prev != NULL) {
        // If there is a node before the middle, update its "next" pointer to skip the middle node.
        prev->next = slowPtr->next;
    } else {
        // If there is no node before the middle, update the head to skip the middle node.
        *head = slowPtr->next;
    }

    free(slowPtr); // Free the memory of the middle node.
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

    printf("Deleting mid of linked list:");

    deleteMiddleNode(&head);

    printLinkedList(head);

}
