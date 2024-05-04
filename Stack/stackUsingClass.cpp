#include <bits/stdc++.h>
using namespace std;

class Stack{
    
    public:
    // properties
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele){
        // is stack overflow
        if(top == size - 1){
            cout << "Stack is overflow." << endl;
        }
        else{
            top++;
            arr[top] = ele;
        }
    }

    void pop(){
        // is stack underflow
        if(top <= -1){
            cout << "Stack is underflow." << endl;
        }
        else{
            top --;
        }
    }

    int peek(){
        // is stack empty
        if(top <= -1){
            cout << "Nothing to show stack is empty." << endl;
        }
        else{
            return arr[top];
        }
        
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    // 4 is the size of the stack
    Stack st(4);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Top element of stack is: " << st.peek() << endl;

cout << endl;

    st.pop();

    cout << "Top element of stack after pop is: " << st.peek() << endl;

cout << endl;
    
    // check stack is empty or not
    if(st.isEmpty()){
        cout << "Stack is empty." << endl;
    }
    else{
        cout << "Stack is not empty." << endl;
    }

    return 0;
}