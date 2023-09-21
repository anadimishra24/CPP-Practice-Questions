#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://www.codingninjas.com/studio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1
    Vedio: https://www.youtube.com/watch?v=oVa8DfUDKTw&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=10
*/



// function for finding the duplicate element
int findDuplicateElement(int arr[], int size){

    int ans = 0;

    // XOR ing all array element
    for (int i = 0; i < size; i++){
        ans = ans ^ arr[i];
    }

    // XOR [1, N-1]
    for (int i = 0; i < size; i++){
        ans = ans ^ i;
    }

    return ans;
}


int main(){

    int arr[] {6, 3, 1, 5, 4, 3, 2};             // output: 3

    int size  = sizeof(arr)/sizeof(int);

    cout << "Duplicate element in an array is: " << findDuplicateElement(arr, size);
  

    return 0;

}
