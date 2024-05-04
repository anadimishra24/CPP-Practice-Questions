#include <bits/stdc++.h>
using namespace std;


string firstNonRepeatingCharInStream(string str){

    // to store the count of every character
    unordered_map<char, int> count;

    string ans = "";
    queue<char> que;

    for (int i = 0; i < str.size(); i++){ 
        char ch = str[i];

        // incease count for char ch
        count[ch]++;

        // push into the queue
        que.push(ch);

        while(!que.empty()){
            if(count[que.front()] > 1){
                // repeating character
                que.pop();
            }
            else{
                // non-repeating character
                ans.push_back(que.front());
                break;
            }
        }
        if(que.empty()){
            // no non-repeating character is remaining
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){


    string str = "aabc";

    string ans = firstNonRepeatingCharInStream(str);

    
    cout << "Output is: "<< ans << " ";
      

    return 0;
}