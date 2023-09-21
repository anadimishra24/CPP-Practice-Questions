#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }

};

void insertNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " -> ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        // cout << "\n loop is at: " << temp -> data << endl;
        return true;
    }

    return false;

}

// check any loop is exist in entire loop or not T.C = O(n)
bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp != NULL) {

        //cycle is present
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}

// Floyd's Cycle detection algorithm
Node* floydLoopDetection(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;

        // if this cond is true then cycle is present in linkedl list
        if(slow == fast){
            // cout << "Cycle is present at node: " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;
}

// starting node of loop using floyd's cycle detection algo
Node* startingNodeOfLoop(Node* head){ 
    if(head == NULL){
        return NULL;
    }

    // floydLoopDetection(head) it gives where fast reside 
    Node* intersection = floydLoopDetection(head);

    Node* slow = head;

    // run loop till slow and intersection
    while(slow != intersection){

        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

// removing the loop from linked list
void revertLoopFromLL(Node* head){

    if(head == NULL){
        return;
    }

    Node* startOfLoop = startingNodeOfLoop(head);

    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
}

int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);


    deleteNode(tail, 5);
    print(tail);


    // checking loop is present in LL by using map
    if(isCircularList(tail)) {
        cout << "Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }

    // checking loop is present in LL by using floyd's detection algo    
    Node* cycle = floydLoopDetection(tail);
    cout << "Linked List is Circular in nature by using floyd's detection algo at node : " << cycle -> data << endl;


    Node* loop = startingNodeOfLoop(tail);
    cout << "Loop is present at node: " << loop -> data << endl;

    cout << "Removing the loop from linked list...." ;
    revertLoopFromLL(tail);


    return 0;
}