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


int getMiddleOfLL(Node* &head, int len){

    int mid = (len / 2) + 1 ;

    Node* temp = head;

    while(mid > 1){
        temp = temp -> next;
        mid--;
    }

    return temp -> data;
}
int getMiddleOfLLbyTwoPointer(Node* &head){

    // base case if LL is empty
    if(head == NULL){
        return -1;
    }

    // base case if LL has only one node
    if(head -> next == NULL){
         return head -> data;
    }

    // base case if LL have two nodes
    if(head -> next -> next == NULL){
        return head -> next -> data;
    }


    Node* fast = head -> next;
    Node* slow = head;

    while (fast != NULL){
        fast = fast -> next ;
        if(fast != NULL){
            fast = fast -> next ;
        }
        slow = slow -> next;
    }
    return slow -> data;
}

int getLenght(Node* node)
{
    int count = 0;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
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
    insertAtEnd(head, 5);

cout << endl;

    cout << "Linked List are: ";
    printList(head);
    
cout << endl;
cout << endl;

    int len = getLenght(head);
    // cout <<"lenght = " << len << endl;

    // first approach T.C = O(n)
    int element = getMiddleOfLL(head, len);
    cout << "Middle element of linked list is: " << element << endl;

    // second approach
    int key = getMiddleOfLLbyTwoPointer(head);
    cout << "Middle element of linked list is: " << key << endl;

    
    return 0;
}