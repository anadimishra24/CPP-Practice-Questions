#include <bits/stdc++.h>
using namespace std;


class Node{

    public:
        int data;
        Node* next = NULL;


    //constructor
    // Node(int data) {
    //     this -> data = data;
    //     this -> next = NULL;
    // }
};


// insert at the end of linked list
void insertAtEnd(Node* &head, int d){

    // creating new node
    Node* node = new Node();

    node -> data = d;
    node -> next = NULL;

    // if list is empty
    if(head == NULL){
        head = node;
    }
    else{
        Node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = node;
    }
}

// reverse the linked list
Node* KreverseLinkedList(Node* head, int k) {

    //base case 
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    Node* prev = NULL; 
    Node* nextNode = NULL;
    
    int count = 0;

    while ( temp != NULL && count < k) {
        nextNode = temp->next; // Store the next node or next part of LL
        temp->next = prev;     // Reverse the link

        // Move prev and temp pointers one step ahead
        prev = temp;
        temp = nextNode;
        count++ ;
    }

    if(nextNode != NULL){
        head -> next = KreverseLinkedList(nextNode, k); 
    }

    // Update the head to point to the new first node (prev)
    return prev;
}


void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL";
}

int main(){

    //created a new node
    Node* node1 = NULL;

    
    //head pointed to node1
    Node* head = node1; 

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    

cout << endl;

    cout << "Linked List are: ";
    printList(head);
    
cout << endl;
cout << endl;

    int k = 2;
    cout << "Reverse the linked list:";
    Node* newHead = KreverseLinkedList(head, k);
    printList(newHead);
    return 0;
}