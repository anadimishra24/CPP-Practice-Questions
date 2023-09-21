#include <bits/stdc++.h>
using namespace std;



int getSum(int *arr, int size){

    int sum = 0;

    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){


    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    /*creating dynamic array of size 'n' that store in heap memory.
        'int *arr' it takes 8 byte bcoz its pointer and 
        'new int[n]' it takes n*4 byte bcoz it is array of int.
        So, total memory consumed by it is 8 + n*4 byte */
    int *arr = new int[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int ans = getSum(arr, n);

    cout << "Sum of array element is " << ans << endl;

    //free dynamically allocated memory
    delete []arr;
    
    return 0;
}