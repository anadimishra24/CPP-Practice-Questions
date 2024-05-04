#include <bits/stdc++.h> 
using namespace std;

class Queue {
public:

    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size) {
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {

        // check queue is overflow
        if(rear == size){
            cout << "Queue is overflow." << endl;
        }
        else{
            arr[rear] = data;
            rear = rear + 1;
        }
    }

    int dequeue() {
       
        // check queue is underflow
        if(front == rear){
            cout << "Queue is underflow." << endl;
            return -1;
        }
        else{
            int ele = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ele;
        }
    }

    int Qfront() {
        if(front == rear){
            return -1;
        }else{
            return arr[front];
        }
       
    }
};


int main(){

    int PopEle, FrontEle;
    
    Queue myQueue(5); // Create a Queue object with a size of 5

    myQueue.enqueue(1); // Call the enqueue method on the myQueue object
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);

    FrontEle = myQueue.Qfront();
    cout << "Front element of queue is: " << FrontEle << endl;

    PopEle = myQueue.dequeue();
    cout << "Dequeue element from queue is: " << PopEle << endl;
   
    
    PopEle = myQueue.dequeue();
    cout << "Dequeue element from queue is: " << PopEle << endl;

    FrontEle = myQueue.Qfront();
    cout << "Front element of queue after popo is: " << FrontEle << endl;

    if(myQueue.isEmpty()){
        cout << "Queue is empty." << endl;
    }
    else{
        cout << "Queue is not empty." << endl;
    }


    return 0;
}