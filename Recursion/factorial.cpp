#include <bits/stdc++.h>
using namespace std;



int factorial(int num){

    // base case
    if(num == 0){
        return 1;
    }

    // recurrence relation

    /*
    int smallerProblem = factorial(num-1);
    int biggerProblem = num * smallerProblem;   // -> F(n) = n * F(n-1)
    return biggerProblem;
    */

    return num * factorial(num-1);
}


int main(){

    int num;
    cout << "Enter your number: ";
    cin >> num;

    int ans = factorial(num);

    cout << "Factorial of "<< num <<" is: " << ans << endl;



    return 0;
}