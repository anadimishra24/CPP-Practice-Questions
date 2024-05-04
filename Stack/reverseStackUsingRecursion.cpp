#include <bits/stdc++.h>
using namespace std;


// insert at bottom
void insertAtBottom(stack<int> &st, int key){

    // base case
    if(st.empty()){
        st.push(key);
        return;
    }
    
    // keep the top element aside in 'num' when we returning back we push it into stack
    int num = st.top();
    st.pop();

    // recursive call to functo
    insertAtBottom(st, key);

    // now push the 'num' that keep aside
    st.push(num);
}

// reverse the stack
void reverseStack(stack<int> &st){

    // base case
    if(st.empty()){
        return;
    }
    
    // keep the top element aside in 'num' when we returning back we push it into stack
    int num = st.top();
    st.pop();

    // recursive call to functon
    reverseStack(st);

    // everytime function call it push the element 'num' at bottom
    insertAtBottom(st, num);
}

int main(){

    stack <int> st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

/* check stack is reverse or not

    cout << "Top of the reverse stack: " << st.top() << endl;    
*/
    
    return 0;
} 