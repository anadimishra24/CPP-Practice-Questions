#include <bits/stdc++.h>
using namespace std;



/* Using queue
queue<int> interleaveTheFirstHalfWithSecondHalf(queue<int> que){

    // size of the queue
    int mid = que.size()/2;

    cout << "size == " << mid << endl;

    // creating new queue
    queue<int> half;

    queue<int> ans;

    int count = 0;

    while(count < mid){
        int ele = que.front();
        que.pop();
        half.push(ele);
        count++;
    }

    while(!que.empty()){
        int queEle = que.front();
        int halfEle = half.front();

        ans.push(halfEle);
        ans.push(queEle);
        

        que.pop();
        half.pop();
    }

    // cout << "Front == " << half.back() << endl;
    return ans;
}
*/

/* Using stack */
queue<int> interleaveTheFirstHalfWithSecondHalf(queue<int> que){

    int mid = que.size()/2;

    queue<int> newQue;

    // step 1: push first half into the stack
    stack<int> st;

    int count = 0;
    while(count < mid){
        int ele = que.front();
        que.pop();
        st.push(ele);
        count++;
    }

    // step 2: pop from stack and push into the queue(elements in stack are in reverse)
    while(!st.empty()){
        int ele = st.top();
        que.push(ele);
        st.pop();
    }

    // step 3: pop from queue and push back itno the queue(so that queue in right order)
    count = 0;
    while(count < mid){
        int ele = que.front();
        que.pop();
        que.push(ele);
        count++;
    }

    // step 4: push first half into the stack(elements in stack are in correct order)
    count = 0;
    while(count < mid){
        int ele = que.front();
        que.pop();
        st.push(ele);
        count++;
    }    

    // step 5: run the loop and push and pop from stack and queue
    while(!que.empty()){
        int queEle = que.front();
        int stackEle = st.top();

        newQue.push(stackEle);
        newQue.push(queEle);
        
        que.pop();
        st.pop();
    }

    return newQue;
}

int main(){

    /*
        Input :  1 2 3 4
        Output : 1 3 2 4

        Input : 11 12 13 14 15 16 17 18 19 20
        Output : 11 16 12 17 13 18 14 19 15 20      
    */

    queue<int> que;

    que.push(11);
    que.push(12);
    que.push(13);
    que.push(14);
    que.push(15);
    que.push(16);
    que.push(17);
    que.push(18);
    que.push(19);
    que.push(20);


    queue<int> ans = interleaveTheFirstHalfWithSecondHalf(que);
    
    cout << "\nQueue after interleave first half with second half: ";
    while(!ans.empty()){
        int ele = ans.front();
        ans.pop();
        cout << ele << " ";
    }
    return 0;
}