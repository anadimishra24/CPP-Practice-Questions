#include<bits/stdc++.h>
using namespace std;



int main() {


    //create a queue
    cout << "\n----------------- QUEUE ----------------------" << endl;
    queue<int> q;

    q.push(11);
    cout << "front of q is: " << q.front() << endl;
    q.push(15);
    cout << "front of q is: " << q.front() << endl;

    q.push(13);
    cout << "front of q is: " << q.front() << endl;

    cout << "Size of queue is : " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "Size of queue after pop operation is : " << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }
    
    // creating dequeue
    cout << "\n----------------- DEQUEUE ----------------------" << endl;
    
    // cout << (-1)%1<< endl;
    
    
    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout << "Front of deque is: " << d.front() << endl;
    cout << "Back of the dequeue is: " << d.back() << endl;

    d.pop_front();
    
    cout << "Front of dequeue after pop operation is: " << d.front() << endl;
    cout << "Back of the dequeue after pop operation is: " << d.back() << endl;
    d.pop_back();

    if(d.empty()) {
        cout << "Dequeue is empty" << endl;
    }
    else{
        cout << "Dequeue is not empty " << endl;
    }
   
  
    return 0;
}