#include <bits/stdc++.h>
using namespace std;

// check who knows whom
bool knows(int a, int b, vector<vector<int>> M){

    if(M[a][b] == 1){
        return true;
    }
    else{
        return false;
    }
}

int clebrityProblem(vector<vector<int>> M, int size){

    // step 1: create a stack and push people (0, 1, 2) in it
    stack <int> st;

    for (int i = 0; i < size; i++){
        st.push(i);
    }

    // step 2 : Pop two element (people) until stack have one element remains
    while (st.size() > 1){ 
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();


        // step 3: Check who knows whom and push the celebrity into the stack 
        if(knows(a, b, M)){
            st.push(b);                     // if 'a' knows 'b' means 'b' is celebrity push into the stack
        }
        else{
            st.push(a);                     // if 'b' knows 'a' means 'a' is celebrity push into the stack
        }
    }
    
    int ans = st.top();

    // step 4: 'ans' may or may not be celebrity so verify it
    
    // row verification
    bool rowCheck = true;
    int zeroCount = 0;
    for (int i = 0; i < size; i++){
        if(M[ans][i] == 0){
            zeroCount++;
        }
    }

    if(zeroCount == size){
        rowCheck = true;
    }
    else{
        rowCheck = false;
    }

    // coloumn verification
    bool colCheck = true;
    int oneCount = 0;
    for (int i = 0; i < size; i++){
        if(M[i][ans] == 1){
            oneCount++;
        }
    }

    if(oneCount == size - 1){
        colCheck = true;
    }
    else{
        colCheck = false;
    }

    // return the answer
    if(rowCheck == true && colCheck == true){
        return ans;
    }
    else{
        return -1;
    }
    
}

int main(){

    vector<vector<int>> M = { {0, 1, 0}, {0, 0, 0}, {0, 1, 0} };

    int size = M.size();

    int ans = clebrityProblem(M, size);

    cout << "In a party " << ans << " is a celebrity." << endl;
    return 0;
}