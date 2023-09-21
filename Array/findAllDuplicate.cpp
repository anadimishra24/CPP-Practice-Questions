#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://leetcode.com/problems/find-all-duplicates-in-an-array/
    Vedio: https://www.youtube.com/watch?v=oVa8DfUDKTw&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=10
*/



// function for finding the duplicate element
vector<int> findAllDuplicateElement(int arr[], int size){

    // Step 1: Create an unordered_map to store the count of occurrences for each integer.
    unordered_map<int, int> occurrences;
    for (int i = 0; i < size; i++){
        occurrences[arr[i]]++;
    }

    vector<int> duplicateValue;   // creating vector to store duplicate value
    for (auto count: occurrences){
        if(count.second == 2){
            duplicateValue.push_back(count.first)  ;
        }
    }
    return duplicateValue; 
}


int main(){

    int arr[] = {4,3,2,7,8,2,3,1};    // Output: [2,3]

    int size  = sizeof(arr)/sizeof(int);

    vector<int> ans = findAllDuplicateElement(arr, size);

    cout << "All duplicate value in array are: ";
    for(int num: ans){
        cout << num << " ";
    }
  

    return 0;

}
