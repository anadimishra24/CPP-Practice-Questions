#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://leetcode.com/problems/power-of-two/
    Vedio: https://www.youtube.com/watch?v=0fwrMYPcGQ0&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=7
*/


// function for checking the number of two
bool powerOfTwo(int n){

    for (int i = 0; i < 30; i++)
    {
       int ans = pow(2, i);
       if(ans == n){
        return true;
       }
    } 
    return false;
}

int main(){

    int n;
    cout << "Enter your number: ";
    cin >> n;

    if(powerOfTwo(n)){
        cout << "The number is power of two." << endl;
    }
    else{
        cout << "The number is not power of two." << endl;
    }
    return 0;

}
