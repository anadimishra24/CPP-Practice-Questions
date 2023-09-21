#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://www.codingninjas.com/studio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1
    Vedio: https://www.youtube.com/watch?v=oVa8DfUDKTw&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=10
*/



// function for getting the unique element 
int findUniqueElement(int arr[], int size){

    // brutefull solution
/*    int temp[100] = {0};

    for (int i = 0; i < size; i++){
        temp[arr[i]]++;
    }
    
    for (int i = 0; i < 100; i++){
        if(temp[i] == 1){
            return i;
        }
    }
*/

    // optimized solution
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}


int main(){

    // int arr[] = {2, 3, 1, 6, 3, 6, 2};               // output: 1
    int arr[] {1, 3, 1, 3, 6, 6, 7, 10, 7};             // output: 10

    int size  = sizeof(arr)/sizeof(int);

    cout << "Unique element in an array is: " << findUniqueElement(arr, size);
  

    return 0;

}
