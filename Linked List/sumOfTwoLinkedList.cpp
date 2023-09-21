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


// reverse the half of liked list
Node* reverseOfLinkedList(Node* mid){
    Node* temp = mid;
    Node* prev = NULL;
    Node* nextNode = NULL;

    while(temp != NULL){
        nextNode = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = nextNode;
    }
    return prev;
}

/* This code is also working but using four while loop

Node* sumOfTwoLinkedList(Node* head1, Node* head2){

    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* newList = NULL;

    int val1 = 0, val2 = 0, carry = 0;

    while(temp1 != NULL && temp2 != NULL){

        int sum = 0, digit = 0;
        
        val1 = temp1 -> data;
        val2 = temp2 -> data;

        sum = carry + val1 + val2;
        digit = sum % 10;
        carry = sum / 10;

        insertAtEnd(newList, digit);

        temp1 = temp1 -> next;
        temp2 = temp2 -> next;

    }

    while(temp1 != NULL){

        int sum = 0, digit = 0;
        val1 = temp1 -> data;
       
        sum = carry + val1;
        digit = sum % 10;
        carry = sum / 10;

        insertAtEnd(newList, digit);

        temp1 = temp1 -> next;
    }

    while(temp2 != NULL){

        int sum = 0, digit = 0;

        val2 = temp2 -> data;

        sum = carry + val2;
        digit = sum % 10;
        carry = sum / 10;

        insertAtEnd(newList, digit);

        temp2 = temp2 -> next;

    }
    
    while(carry != 0){
        int sum = 0, digit = 0;
        
        sum = carry;
        digit = sum % 10;

        insertAtEnd(newList, digit);
        carry = sum / 10;
    }
}
*/


// sum of two linked list with generic or optimized code
Node* sumOfTwoLinkedList(Node* head1, Node* head2){

    Node* newList = NULL;

    int carry = 0;

    // generic code with one while loop
    while(head1 != NULL || head2 != NULL || carry != 0){

        int val1 = 0;
        if(head1 != NULL){
            val1 = head1 -> data;
        }
        
        int val2 = 0;
        if(head2 != NULL){
            val2 = head2 -> data;
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;
        carry = sum / 10;

        insertAtEnd(newList, digit);

        if(head1 != NULL){
            head1 = head1 -> next;
        }
        
        if(head2 != NULL){
            head2 = head2 -> next;
        }
    }
    return newList;
}



int main(){

    //created a new node
    Node* List1 = NULL;

    Node* List2 = NULL;
    
    //head1 pointed to list1
    Node* head1 = List1; 

    //head2 pointed to list2
    Node* head2 = List2; 

    // List1 element insertion
    insertAtEnd(head1, 4);
    insertAtEnd(head1, 5);

    // List2 element insertion
    insertAtEnd(head2, 3);
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 5);


cout << endl;

    cout << "First Linked List are: ";
    printList(head1);
    
cout << endl;

    cout << "Second Linked List are: ";
    printList(head2);

cout << endl;

    Node* revL1 = reverseOfLinkedList(head1);
    Node* revL2 = reverseOfLinkedList(head2);

cout << endl;


    // cout << "First Linked List after reverse are: ";
    // printList(revL1);

    // cout << "Second Linked List after reverse are: ";
    // printList(revL2);

cout << endl;

    Node* sumOFList = sumOfTwoLinkedList(revL1, revL2);

    // re-reverse the list to its normal form otherwise it prints the answer list in reverse order
    
    Node* nayaHead = reverseOfLinkedList(sumOFList);

    cout << "The sum of two linked list are: ";
    printList(nayaHead);

    return 0;
}