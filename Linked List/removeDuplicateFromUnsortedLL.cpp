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

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL";
}

// removes duplicate from unsorted Linked List
void removeDuplicateFromUnsortedLL(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* current = head;

    while (current != NULL) {
        Node* prev = current;
        Node* second = current -> next;
        while(second != NULL){
            if(current -> data == second -> data){
                Node* deleteNode = second;
                prev -> next = second -> next;
                free(deleteNode);
                second = prev -> next;
            }
            else{
                prev = second;
                second = second -> next;
            }
        }
    
        current = current->next;
    }
}

/*
// chatGPT code
void removeDuplicateFromUnsortedLL(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* current = head;

    while (current != NULL) {
        Node* runner = current;

        while (runner->next != NULL) {
            if (current->data == runner->next->data) {
                Node* duplicate = runner->next;
                runner->next = duplicate->next;
                free(duplicate);
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}
*/

int main(){

    //created a new node
    Node* node1 = NULL;

    
    //head pointed to node1
    Node* head = node1; 

    insertAtEnd(head, 4);
    insertAtEnd(head, 3);
    insertAtEnd(head, 1);
    insertAtEnd(head, 4);
    insertAtEnd(head, 3);
    insertAtEnd(head, 1);
    insertAtEnd(head, 6);
    insertAtEnd(head, 5);

cout << endl;

    cout << "Linked List are: ";
    printList(head);
    
cout << endl;
cout << endl;

    removeDuplicateFromUnsortedLL(head);
    cout << "Linked List after removing duplicates: ";
    printList(head);

cout << endl;
cout << endl;



    return 0;
}