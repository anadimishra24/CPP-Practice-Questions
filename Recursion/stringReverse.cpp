#include <bits/stdc++.h>
using namespace std;



void reverseString(string& name, int start, int end){

    // base case
    if(start > end){
        return;
    }


    swap(name[start], name[end]);
    start++;
    end--; 

    reverseString(name, start, end);
   
}

int main(){

    string name = "anadi";

    cout << "String is " << name << endl;

    int len = name.length();

    int start = 0, end = len - 1;

   reverseString(name, start, end);

   cout << "\nString after reverse is " << name << endl;

    return 0;
}