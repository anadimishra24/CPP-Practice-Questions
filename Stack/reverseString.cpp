#include <bits/stdc++.h>
using namespace std;


int main(){

    string name = "anadi";
    string nayaNaam = " ";

    stack<char> st;

    for(int i = 0; i < name.size(); i++){
        st.push(name[i]);
    }



    for(int i = 0; i < name.size(); i++){
        nayaNaam.push_back(st.top());
        st.pop();
    }

    cout << "Reverse string is: " << nayaNaam << endl;
    
    return 0;
}