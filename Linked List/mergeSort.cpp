#include <bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node* next = NULL;

        // empty constructor
        Node(){

        }

        // constructor with parametre
        Node(int data){
                this->data=data;
                this->next=NULL;
        }
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

// print the linked list
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL";
}

// get the middle of linked list
Node* getMiddleOfLLbyTwoPointer(Node* &head){

    Node* fast = head -> next;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;  // Advance fast by two steps
        slow = slow->next;       // Advance slow by one step
    }
    return slow;
}

// merge the two linked list
Node* mergeSortedList(Node* left, Node* right){

    // if left is empty return right
    if(left == NULL){
        return right;
    }

    // if right is empty return left
    if(right == NULL){
        return left;
    }

    Node* ans = new Node(0); // Dummy head node to simplify handling edge cases
    Node* current = ans; // Pointer to the current node in the merged list

    while (left != NULL  && right != NULL) {
        if (left->data < right->data) {
            current->next = left;
            current = left;
            left = left->next;
        } else {
            current->next = right;
            current = right;
            right = right->next;
        }
    }

    // Append any remaining nodes from left or right (if any)
    while (left != NULL) {
        current->next = left;
        current = left;
        left = left->next;
    }
    while (right != NULL){
        current->next = right;
        current = right;
        right = right->next;
    }

    ans = ans->next; 

    return ans;
}

// merge sort of two linked list
Node* mergeSort(Node* head){

    // base case
    if(head == NULL || head -> next == NULL){
        return head;
    }

    // get the mid of the linked list
    Node* mid = getMiddleOfLLbyTwoPointer(head);

    // breaking linkedl it into two halvs left and right
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    // recursive call to sort both halvs
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both the two halvs og linked list
    Node* mergeList = mergeSortedList(left, right);

    return mergeList;

}



int main(){

    //created a new node
    Node* node1 = NULL;

    
    //head pointed to node1
    Node* head = node1; 

    insertAtEnd(head, 2);
    insertAtEnd(head, 5);
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

cout << endl;

    cout << "Linked List are: ";
    printList(head);
    
cout << endl;
cout << endl;
   
    Node* resultantList = mergeSort(head);
    

    cout << "Sorted Linked List are: ";
    printList(resultantList);

    return 0;
}