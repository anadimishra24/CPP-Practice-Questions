#include <bits/stdc++.h>
using namespace std;


void deleteMiddleElementFromStack(stack<int> &st, int size, int count){

    // base case
    if(count == size / 2){
        st.pop();
        return;
    }
    
    // keep the top element aside in 'num' when we returning back we push it into stack
    int num = st.top();
    st.pop();

    // recursive call to functo
    deleteMiddleElementFromStack(st, size, count + 1);

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

    int size = st.size();

    int count  = 0;

    deleteMiddleElementFromStack(st, size, count);

/*
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
*/

    return 0;
} 