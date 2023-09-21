#include <bits/stdc++.h>
using namespace std;


/*  How to find a^b 
    case 1: if b is even, then (a^b/2) * (a^b/2)
    case 2: if b is odd, then a * ((a^b/2) * (a^b/2))    */

int getApowerB(int a, int b){

    // base case
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    int ans = getApowerB(a, b/2);

    // b is odd 
    if(b & 1){
        return a * ans * ans;
    }
    else{
        return ans * ans;
    }

}


int main(){

    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of b: ";
    cin >> b;

    int ans = getApowerB(a,b);

    cout << endl;

    cout << a <<" to the power of " << b << " is: " << ans << endl;


    return 0;
}