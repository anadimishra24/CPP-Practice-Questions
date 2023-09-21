#include <bits/stdc++.h>
using namespace std;


/*
    Insertion sort is different from other sorting algorithm 
    because in this algo we use shifting of arrays instead of swapping them
*/

void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}

void insertionSort(vector<int> &arr, int size){

    for (int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i-1;
        for (; j >= 0; j--){         
            if(arr[j] > temp){
                // shift
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp; 
    }
}


int main(){

    vector<int> arr = { 10, 7, 4, 8, 2, 11 };  
    int size  = arr.size();

    cout << "Array before insertion sort: " ;
    printArr(arr, size);

cout << endl;

    // calling function for insertion sort
    insertionSort(arr, size);

    return 0;

}


