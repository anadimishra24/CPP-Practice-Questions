#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://leetcode.com/problems/complement-of-base-10-integer/
    Vedio: https://www.youtube.com/watch?v=0fwrMYPcGQ0&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=7
*/


// function for complement of base 10
int complementOfBase10Int(int n){

    int m = n;
    int mask = 0;

    // edge case
    if(n == 0){
        return 1;
    }

    while (m != 0)
    {
        mask = (mask << 1) | 1;
        cout << "mask = " << mask << endl;
        m = m >> 1;
        cout << "m = " << m << endl;
    }
    int ans = (~n) & mask;

    return ans;
    
}
int main(){

    int n;
    cout << "Enter your number: ";
    cin >> n;

    cout << "Complement of base 10 integer: " << complementOfBase10Int(n);
    return 0;

}
