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

// Approach 1; count the # occurence and update the data
void sort012LinkedList(Node* head) {
    int zero = 0, one = 0, two = 0;
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        
        if(temp -> data == 0){
            zero++;
        }
        if(temp -> data == 1){
            one++;
        }
        if(temp -> data == 2){
            two++;
        }

        temp = temp->next;
    }

    Node* newList = NULL;

    Node* start = head;

    while(start != NULL){
        if(zero != 0){
            start -> data = 0;
            zero--;
        }
        else if(one != 0){
            start -> data = 1;
            one--;
        }
        else{
            start -> data = 2;
            two--;
        }
        start = start -> next;
    }

}

// Approach 2; don't overwrite the data just create the three LL and merge them
Node* sort012LLByCreatingDifferentLL(Node* head){

    // create 0's, 1's, 2's list
    Node* zeroHead = NULL;

    Node* oneHead = NULL;

    Node* twoHead = NULL;


    Node* temp = head;
    while (temp != NULL) {
        int value = temp->data;
        Node* newNode = new Node();
        newNode->data = value;

        if (value == 0) {
            newNode->next = zeroHead;
            zeroHead = newNode;
        } else if (value == 1) {
            newNode->next = oneHead;
            oneHead = newNode;
        } else if (value == 2) {
            newNode->next = twoHead;
            twoHead = newNode;
        }

        temp = temp->next;
    }

    // Find the last node of the zero list
    Node* zeroTail = zeroHead;
    if (zeroTail != NULL) {
        while (zeroTail->next != NULL) {
            zeroTail = zeroTail->next;
        }
    }

    // Find the last node of the one list
    Node* oneTail = oneHead;
    if (oneTail != NULL) {
        while (oneTail->next != NULL) {
            oneTail = oneTail->next;
        }
    }

    // Merge the sorted lists (0 -> 1 -> 2)
    if (zeroHead != NULL) {
        head = zeroHead;
        if (oneHead != NULL) {
            zeroTail->next = oneHead;
            if (twoHead != NULL) {
                oneTail->next = twoHead;
            }
        } else if (twoHead != NULL) {
            zeroTail->next = twoHead;
        }
    } else if (oneHead != NULL) {
        head = oneHead;
        if (twoHead != NULL) {
            oneTail->next = twoHead;
        }
    } else if (twoHead != NULL) {
        head = twoHead;
    }

    return head;
}

int main(){

    //created a new node
    Node* node1 = NULL;

    
    //head pointed to node1
    Node* head = node1; 

    insertAtEnd(head, 1);
    insertAtEnd(head, 0);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    insertAtEnd(head, 0);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    

cout << endl;

    cout << "Linked List are: ";
    printList(head);
    
cout << endl;
cout << endl;

    sort012LinkedList(head);
    cout << "After sorting the Linked List: ";
    printList(head);

cout << endl;
cout << endl;

    Node* nayaHead = sort012LLByCreatingDifferentLL(head);
    cout << "After sorting the Linked List: ";
    printList(nayaHead);    


    return 0;
}