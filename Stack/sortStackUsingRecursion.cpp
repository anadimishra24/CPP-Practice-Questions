#include <bits/stdc++.h>
using namespace std;


// insert in descending order
void insertInRightOrder(stack<int> &st, int num){

    // base case
    if(st.empty() || (!st.empty() && st.top() < num)){
        st.push(num);
        return;
    }  

    int ele = st.top();
    st.pop();

    // recursive call
    insertInRightOrder(st, num);

    st.push(ele);

}


// sort the stack
void sortStack(stack<int> &st){

    // base case
    if(st.empty()){
        return;
    }
    
    // keep the top element aside in 'num' when we returning back we push it into stack
    int num = st.top();
    st.pop();

    // recursive call to functon
    sortStack(st);

    insertInRightOrder(st, num);
}
  

int main(){

    stack <int> st;
    
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);

    // cout << "Top of the sorted stack: " << st.top() << endl;    

    sortStack(st);

/* check stack is sorted or not

    cout << "Top of the sorted stack: " << st.top() << endl;    
*/
    
    return 0;
} 