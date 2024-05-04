#include <bits/stdc++.h> 
using namespace std;


class TwoStack {

    int *arr;
    int top1;
    int top2;
    int size;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // at leadt one space available
        if(top2 - top1 > 1){
           top1++;
            arr[top1] = num;
        }
        else{
            cout << "Stack is overflow for stack1." << endl;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // at leadt one space available
        if(top2 - top1 > 1){
           top2--;
            arr[top2] = num;
        }
        else{
            cout << "Stack is overflow for stack2." << endl;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // is stack underflow
        if(top1 <= -1){
            cout << "Stack1 is underflow." << endl;
            return -1;
        }
        else{
            int popElemet = arr[top1];
            top1 --;
            return popElemet;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // is stack underflow
        if(top2 >= size){
            cout << "Stack2 is underflow." << endl;
        }
        else{
            int popElemet = arr[top2];
            top2++;
            return popElemet;
        }
    }
};

int main(){

    TwoStack st(4);

    st.push1(1);
    st.push1(2);

    st.push2(3);
    st.push2(4);


    int popEle1 = st.pop1();
    cout << "Pop element from stack1: " << popEle1 << endl;
    
    int popEle2 = st.pop2();
    cout << "Pop element from stack1: " << popEle2 << endl;

    return 0;
}