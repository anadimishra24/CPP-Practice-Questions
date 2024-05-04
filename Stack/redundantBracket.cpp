#include <bits/stdc++.h>
using namespace std;



// check the redundant Brackets is present or not
bool redundantBrackets(string expression){

    stack <char> st;

    for (int i = 0; i < expression.length(); i++){
        char ch = expression[i];

        // if ch = '(' or ch = operator push into the stack 
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        // if ch = ')' or ch = lowerCharcater(no need to consider in code)
        else{

           if(ch == ')'){

            bool isReduntant = true;

            while(st.top() != '('){
                char top = st.top();
                if( top == '+' || top == '-' || top == '*' || top == '/' ){
                    isReduntant = false;
                }
                st.pop();
            }

            if(isReduntant == true){
                return true;
            }
            st.pop();
           } 
        }
    }
    return false;
}


int main(){

    string expression = "(a+b)";   // (a+c*b)+(c))

    if(redundantBrackets(expression)){
        cout << "Yes." << endl;
    }
    else{
        cout << "No." << endl;
    }

    return 0;
}

