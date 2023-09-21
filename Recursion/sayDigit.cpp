#include <bits/stdc++.h>
using namespace std;


void sayDigit(int num, string arr[]){
    
    // base case
    if(num == 0){
        return;
    }

    // processing
    int digit = num % 10;
    num = num / 10;

    
    // recursive call
    sayDigit(num, arr);
    cout << arr[digit] << " ";

}

int main(){

    string arr[] = { "zero", "one", "two", "three", "four",
                        "five", "six", "seven", "eight", "nine"};
    
    int num;
    cout << "Enter your number: ";
    cin >> num;

    sayDigit(num, arr);

    return 0;
}