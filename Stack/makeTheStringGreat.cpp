#include <bits/stdc++.h>
using namespace std;


char toLower(char ch){
    // already in lower case
    if(ch >= 97 && ch <= 122){
        return ch;
    }
    else{
        return ch - 'A' + 'a';
    }

}
string makeTheStringGreat(string str){

    string ans = "";


    for (int i = 0; i < str.length(); i++)
    {
        if(toLower(str[i]) != toLower(str[i+1])){
            ans.push_back(str[i]);
        }
    }
    
return ans;
}


int main(){

    string str = "abBAcC";   // "leEeetcode";  // Output: "leetcode"

    string ans = makeTheStringGreat(str);

    cout << "The great string is: " << ans << endl;

    return 0;
}