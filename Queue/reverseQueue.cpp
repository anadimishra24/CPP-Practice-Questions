#include <bits/stdc++.h> 
using namespace std;


// reverse queue using  satck
queue<int> reverseQueueByUsingStack(queue<int> que){

    // creating a stack
    stack<int> st;

    // pop element from queue and push element into the stack
    while (!que.empty()){
       int ele = que.front();
       que.pop();
       st.push(ele);
       
    }

    // pop element from stack and push element into the queue
    while (!st.empty()){
       int ele = st.top();
       st.pop();
       que.push(ele);
       
    }
    
    return que;
}


// reverse queue using recursion
void reverseQueueByUsingRecursion(queue<int> que){

    // baase case
    if(que.empty()){
        return ;
    }

    int ele = que.front();
    que.pop();

    reverseQueueByUsingRecursion(que);

    que.push(ele);
}

int main(){

   
    queue<int> que;


    que.push(1); 
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);

    cout << "\nFront of queue before reverse: " << que.front() << endl;
    
    queue<int> reverseQueue = reverseQueueByUsingStack(que);

    cout << "\nFront of queue after reverse: " << reverseQueue.front() << endl;


    reverseQueueByUsingRecursion(que);

    cout << "\nFront of queue after reverse: " << que.front() << endl;


    return 0;
}