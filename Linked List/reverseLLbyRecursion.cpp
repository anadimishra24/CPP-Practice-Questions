#include <bits/stdc++.h>
using namespace std;


class Node{

    public:
        int data;
        Node* next = NULL;
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
void reverseLinkedListByRecursion(Node* &head, Node* temp, Node* prev) {

    if(temp == NULL){
        head = prev;
        return;
    }

    Node* nextNode = temp->next; // Store the next node
    reverseLinkedListByRecursion(head, nextNode, temp);
    temp->next = prev;     // Reverse the link
    
}

// dusra recursion function for reversing the linked list
Node* LLreverseByRecursion(Node* head) {

    if(head == NULL || head -> next == NULL){
        return head ;
    }

    Node* chotaHead = LLreverseByRecursion(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
        
    return chotaHead;
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

    Node* temp = head;
    Node* prev = NULL;

    cout << "Reverse the linked list using recursion: ";
    reverseLinkedListByRecursion(head, temp, prev);
    printList(head);

cout << endl;
cout << endl;

    cout << "Reverse the linked list using second recursion method : ";
    Node* newHead = LLreverseByRecursion(head);
    printList(newHead);

cout << endl;

    return 0;
}