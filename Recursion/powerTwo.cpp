#include <bits/stdc++.h>
using namespace std;


int power(int n){

    // base case
    if(n == 0){
        return 1;
    }

    /*
    int smallerProblem = power(n-1);
    int biggerProblem = 2 * smallerProblem;   // -> F(n) = n * F(n-1)
    return biggerProblem;
    */

    return 2 * power(n-1);
}

int main(){


    int n;
    cout << "Enter the value of n: ";
    cin >> n ;

    int ans = power(n);
    cout << "2 to the power " << n << " is: " << ans << endl;

    return 0;
}