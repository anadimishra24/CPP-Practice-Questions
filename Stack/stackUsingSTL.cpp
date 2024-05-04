#include <bits/stdc++.h>
using namespace std;



int main(){

    stack <int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Top element of stack is: " << st.top() << endl;

cout << endl;

    st.pop();

    cout << "Top element of stack after pop is: " << st.top() << endl;

cout << endl;

    cout << "Size of stack is: " << st.size() << endl;
    
    // check stack is empty or not
    if(st.empty()){
        cout << "Stack is empty." << endl;
    }
    else{
        cout << "Stack is not empty." << endl;
    }


    return 0;
} 