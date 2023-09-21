#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://www.codingninjas.com/studio/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1
    Vedio: https://www.youtube.com/watch?v=oVa8DfUDKTw&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=10
*/




// new solution with no TLE problem
void sort012(int arr[], int size){


    map<int, int> count;

    for (int i = 0; i < size; i++){
        count[arr[i]]++;
    }

    vector<int> sortedArray;   // creating vector to store duplicate value
    for (auto key: count){
        if(key.first == 0){
            while (key.second != 0){
                sortedArray.push_back(key.first);
                key.second--;
            } 
        }
        else if(key.first == 1){
            while (key.second != 0){
                sortedArray.push_back(key.first);
                key.second--;
            } 
        }
        else{
            while (key.second != 0){
                sortedArray.push_back(key.first);
                key.second--;
            } 
        }
    }

    cout << "Sorted array in 0 1 2 form : ";
    for (auto i: sortedArray){
        cout << i << " ";
    }
    
    
}

int main(){

    int arr[] =  {0, 1, 2, 2, 1, 0};    // output: 0 0 1 1 2 2
    
    int size  = sizeof(arr)/sizeof(int);

    cout << "Array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " " ;      
    }
    
cout << endl;

    sort012(arr, size); 

    return 0;
}