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


// get the middle of linked list
Node* getMiddleOfLinkedList(Node* head){
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
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

// Approach 1: check linked list is pallindrome or not
bool checkPallindrome(Node* head){

    if(head -> next == NULL){
        return true;
    }

    // step 1: get the middle of linked list
    Node* mid = getMiddleOfLinkedList(head);

    // step 2: reverse half from middle -> next of the linked list
    Node* temp =  mid -> next;
    mid -> next = reverseOfLinkedList(temp);
    
    // step 3: compare both halfs
    Node* head1= head;
    Node* head2 = mid -> next;

    while(head2 != NULL){
        if(head1 -> data != head2 -> data ){
            return false;
        }
        else{
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    }

    // step 4: re-reverse the half linked list to its actual order 
    temp = mid -> next;
    mid -> next = reverseOfLinkedList(temp);

    // step 5: return the answer
    return true;
}


// Approach 2: Copying LL element in array and check it is pallindrome or not
bool checkPallindromeUsingArray(Node* head){
    vector<int> pal;

    Node* temp = head;
    while(temp != NULL){
        pal.push_back(temp -> data);
        temp = temp -> next;
    }

    int start = 0, end = pal.size()-1;
   
    while(start < end){
        if(pal[start] != pal[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}


int main(){

    //created a new node
    Node* node1 = NULL;

    
    //head pointed to node1
    Node* head = node1; 

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);


cout << endl;

    cout << "Linked List are: ";
    printList(head);
    
cout << endl;
cout << endl;

    if(checkPallindrome(head)){
        cout << "Linked List is pallindrome" << endl;
    }
    else{
        cout << "Linked List is not pallindrome" << endl;
    }

cout << endl;
cout << endl;

    if(checkPallindromeUsingArray(head)){
        cout << "Linked List is pallindrome by using array." << endl;
    }
    else{
        cout << "Linked List is not pallindrome by using array." << endl;
    }


cout << endl;
cout << endl;



    return 0;
}