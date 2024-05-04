#include <bits/stdc++.h>
using namespace std;



// check the paranthesis is valid or not
bool validParanthesis(string paranthesis){

    stack <char> st;

    for (int i = 0; i < paranthesis.length(); i++){
        char ch = paranthesis[i];

        // push opening paranthesis into the stack
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        // else pop the corresponding closing paranthesis from the stack
        else{

            char top = st.top();
            if( ( top == '(' && ch == ')' ) || ( top == '[' && ch == ']' ) || ( top == '{' && ch == '}' ) ){
                st.pop();
            }
            else{
                return false;
            }
        }

    }

    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    string brac = "[()]{}{[()()]()}";

    if(validParanthesis(brac)){
        cout << "Balanced." << endl;
    }
    else{
        cout << "Not balanced." << endl;
    }

    return 0;
}










/*
bool isValidParenthesis(string expression)
{
  	 stack<char> s;
     for(int i=0; i<expression.length(); i++) {
         
         char ch = expression[i];
         
         //if opening bracket, stack push
         //if close bracket, stacktop check and pop
         
         if(ch == '(' || ch == '{' || ch == '['){
             s.push(ch);
         }
         else
         {
             //for closing bracket
             if(!s.empty()) {
                  char top = s.top();
                  if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      s.pop();
                  }
                 else
                 {
                     return false;
                 }
             }
             else
             {
                 return false;
             } 
         }  
     }
    
    if(s.empty())
        return true;
    else
        return false;
}

*/