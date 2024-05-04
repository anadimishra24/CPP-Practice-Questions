#include <bits/stdc++.h> 
using namespace std;


// reverse first k element from queue
queue<int> reverseQueueKElemet(queue<int> que, int size, int k){

    // stack intialization
    stack<int> st;

    // delete first k queue front element and push that into the stack
    for (int i = 0; i < k; i++){
        int ele = que.front();
        que.pop();
        st.push(ele);
    }
    
    // now push the stack element ito the queue
    while(!st.empty()){
        int ele = st.top();
        st.pop();
        que.push(ele);
    }

    // now our que is: 4 5 3 2 1 but we want in order: 3 2 1 4 5
    // now pop the n-k element from queue front and push back

    for (int i = 0; i < size-k; i++){
        int ele = que.front();
        que.pop();
        que.push(ele);
    }
    return que;
}

int main(){

   
    queue<int> que;


    que.push(1); 
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);

    int size = que.size();

    int k = 3;

    cout << "\nFront of queue before reverse: " << que.front() << endl;
    
    queue<int> ans = reverseQueueKElemet(que, size, k);

    cout << "\nFront of queue after reverse: " << ans.front() << endl;
    cout << "\nRear of queue after reverse: " << ans.back() << endl;


    return 0;
}