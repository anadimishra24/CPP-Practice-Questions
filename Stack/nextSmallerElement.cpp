#include <bits/stdc++.h>
using namespace std;



vector<int> nextSmallerElement(vector<int> &arr, int size){

    stack<int> st;
    st.push(-1);

    vector<int> ans(size);

    for (int i = size - 1; i >= 0; i--){

        int ele = arr[i];

        while(st.top() >= ele){
            st.pop();
        }

        ans[i] = st.top();
        st.push(ele);
    }
    
    return ans;    
}

/* Writing again this function for practice*/
vector<int> nextSmallerElement2(vector<int> &arr, int size){

    stack<int> s;
    s.push(-1);

    vector<int> ans(size);

    for (int i = size - 1; i >= 0; i--){
        int curr = arr[i];
        
        // if bada element mila to stack se chota nikalo pop krke
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
return ans;
}

int main(){


    vector<int> arr = {2, 1, 4, 3};
   

    int size = arr.size();

    vector<int> ans =  nextSmallerElement2(arr, size);

    cout << "\n\nThe next smaller number is: ";
    for (int i = 0; i < size; i++){
        cout << ans[i] << " " ;
    }
    

    return 0;
} 