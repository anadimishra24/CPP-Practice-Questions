#include <bits/stdc++.h>
using namespace std;



/*
    Ques: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    Video: https://www.youtube.com/watch?v=tWnHbSHwNmA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=42
*/


vector <string> letterCombinationOfPhoneKeypad(string digit, string map[], vector<string> &ans, string output, int indx){


    // base case    
    if(indx >= digit.length()){
        ans.push_back(output);
        return ans;
    }
    
    // if digit length is 0 then return empty ans
    if(digit.length() == 0){
        return ans;
    }

    // we do -'0' for type conversion from char to int
    int number = digit[indx] - '0';
    string value = map[number];

    for (int i = 0; i < value.length(); i++){
        output.push_back(value[i]);
        letterCombinationOfPhoneKeypad(digit, map, ans, output, indx+1);
        output.pop_back();
    }
    
    return ans;
}


int main(){

    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string digit = "23";

    vector <string> ans;
    string output;
    
    int indx = 0;

    vector <string> result = letterCombinationOfPhoneKeypad(digit, map, ans, output, indx);

cout << endl;

    cout << "Letter combination of phone keypad is: ";
    for(auto str: result){
        cout << str << " ";
    }
    return 0;
}