#include <bits/stdc++.h>
using namespace std;




bool checkPallindrome(string name, int start, int end){
    
    // base case
    if(start > end){
        return true;
    }

    if(name[start] != name[end]){
        return false;
    }
    else{
        return checkPallindrome(name, start + 1, end - 1);
    }
}



int main(){

    string name = "ana";

    cout << "String is " << name << endl;

    int len = name.length();

    int start = 0, end = len - 1;

   if(checkPallindrome(name, start, end)){
        cout << "String is pallindrome.\n";
   }
   else{
        cout << "String is not pallindrome.\n";
   }


    return 0;
}