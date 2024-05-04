#include <bits/stdc++.h> 
using namespace std;


class CircularQueue{
    public:

    int *arr;
    int size;
    int front;
    int rear;

    // Initialize your data structure.
    CircularQueue(int size){
        
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // check overflow
        if((front == 0 && rear == size - 1)|| (rear == (front-1)%(size-1))){
            cout << "Queueu is overflow." << endl;
            return false;
        }
        // push first element
        else if(front == -1){
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear == size - 1 && front != 0){    // to maintain cyclic nature
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear = rear + 1;
            arr[rear] = value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // check queue is underflow
        if(front == -1){
            cout << "Circular queue is underflow." << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){ // single element in queue
            front = rear = -1;
        }
        else if(front == size - 1){   // to maintain cyclic nature
            front = 0;
        }
        else{   // normal flow
            front++;
        }
        return ans;
    }
};

int main(){

    int PopEle;

    CircularQueue cirQue(4);

    if(cirQue.enqueue(1)){
        cout << "Insertion in circular queue is successfull." << endl;
    }
    else{
        cout << "Insertion in circular queue is unsuccessfull." << endl;
    }

    PopEle = cirQue.dequeue();
    cout << "Dequeue element from circular queue is: " << PopEle << endl;
   
    
    PopEle = cirQue.dequeue();
    cout << "Dequeue element from circular queue is: " << PopEle << endl;

    return 0;
}