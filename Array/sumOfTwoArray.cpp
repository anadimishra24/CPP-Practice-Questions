#include <bits/stdc++.h>
using namespace std;




void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " ";
    }
}


vector<int> sumOfTwoArray(vector<int> arr, int aSize, vector<int> brr, int bSize){

    // if we don't want to reverse the array then we simply run the loop from reverse like:while (i > aSize && j > bSize) i-- and j--
    reverse(arr.begin(), arr.end());
    reverse(brr.begin(), brr.end());

    
    vector<int> ans;

    int i = 0, j = 0;
    int carry = 0;

    while (i < aSize && j < bSize){
        
        int sum = 0, digit = 0;

        sum = carry + arr[i] + brr[j];
        digit = sum % 10;
        carry = sum / 10;

        ans.push_back(digit);
        i++;
        j++;
    }
    
    while(i  < aSize){
        int sum = 0, digit = 0;

        sum = carry + arr[i];
        digit = sum % 10;
        carry = sum / 10;

        ans.push_back(digit);
        i++;
    }
 
    while(j  < bSize){
        int sum = 0, digit = 0;

        sum = carry + brr[j];
        digit = sum % 10;
        carry = sum / 10;

        ans.push_back(digit);
        j++;
    }  
    
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){

    vector<int> arr = { 1, 2, 3, 4 };  
    vector<int> brr = { 6 }; 
    
    int aSize  = arr.size();
    int bSize  = brr.size();

cout << endl;

    cout << "Array 1: ";
    printArr(arr, aSize);

cout << endl;
cout << endl;

    cout << "Array 2: ";
    printArr(brr, bSize);

cout << endl;
cout << endl;

    vector<int> sum = sumOfTwoArray(arr, aSize, brr, bSize);

    cout << "Sum of two array Array1 and Array2 are: ";
    printArr(sum, sum.size());

    return 0;

}


