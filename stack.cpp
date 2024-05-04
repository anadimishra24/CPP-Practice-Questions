#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {

    stack<char> st;

    for(int i = 0; i < s.size(); i++){

        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            cout << "in if" << endl;
            st.push(s[i]);
        }
        else {
            if((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']')){
                cout << "in else if" << endl;
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

    string s = "}";

    if(isValid(s)){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }


    return 0;
}