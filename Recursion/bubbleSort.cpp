#include <bits/stdc++.h>
using namespace std;



void printArr(int arr[], int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}


void bubbleSort(int *arr, int size){

    // base case --> already sorted
    if(size == 0 || size == 1){
        return;
    }

    // process all the element for each round
    for (int j = 0; j < size - 1; j++){         // j < size - i bcoz at each round last element is sorted so decrement the loop
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }
    
    // recursicve call
    bubbleSort(arr, size-1);

}


int main(){

    int arr[] = { 6, 2, 8, 4, 10 };  
    int size  = sizeof(arr)/sizeof(int);

    cout << "Array before bubble sort: " ;
    printArr(arr, size);

cout << endl;

    // calling function for bubble sort
    bubbleSort(arr, size);

    cout << "Array after bubble sort: " ;
    printArr(arr, size);

    return 0;

}


