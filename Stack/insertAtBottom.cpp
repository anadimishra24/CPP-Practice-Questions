#include <bits/stdc++.h>
using namespace std;


void insertAtBottom(stack<int> &st, int key){

    // base case
    if(st.empty()){
        st.push(key);
        return;
    }
    
    // keep the top element aside in 'num' when we returning back we push it into stack
    int num = st.top();
    st.pop();

    // recursive call to functon
    insertAtBottom(st, key);

    // now push the 'num' that keep aside
    st.push(num);
}

int main(){

    stack <int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int x = 9;

    insertAtBottom(st, x);

/* check value is inserted or not
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout << "After poping all the element top of the stack that we insert at the bottom of the stack: " << st.top() << endl;
    
*/
    
    return 0;
} 