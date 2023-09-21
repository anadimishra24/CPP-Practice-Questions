#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://leetcode.com/problems/reverse-integer/
    Vedio: https://www.youtube.com/watch?v=0fwrMYPcGQ0&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=7
*/


// function for reverse the integer
int reverseInteger(int n){

    int ans = 0;
    while( n != 0){
        int digit = n % 10;

        // check ans is within limit of int or not
        if( (ans > INT_MAX / 10) || (ans < INT_MIN / 10)){
            cout << "\nans is not within limit of int.So, its return 0.\n" << endl;
            return 0;
        }
        ans = (ans * 10) + digit;
        n = n / 10;
    }
    return ans;
}


int main(){

    int x ;
    cout << "Enter your number: ";
    cin >> x;

    cout << "Reverse integer is: " << reverseInteger(x) << endl;

    return 0;
}