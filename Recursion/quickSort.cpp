#include <bits/stdc++.h>
using namespace std;


// printing the array
void printArr(int arr[], int size){
    for(int i = 0; i < size ; i++){
        cout << arr[i] << " , ";
    }
}


int partition(int *arr, int start, int end){

    int pivot = arr[start];

    int count = 0;
    for (int i = start+1; i <= end; i++){
        if(arr[i] <= pivot){
          count++;  
        }
    }
      
    // place pivot at right position
    int pivotIndx = start + count;
    swap(arr[pivotIndx], arr[start]);

    int i = start, j = end;
    while(i < pivotIndx && j > pivotIndx){
        while (arr[i] < pivot){
            i++;
        }

        while (arr[j] > pivot){
            j--;
        }
        
        if(i < pivotIndx && j > pivotIndx){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndx;    

}


void quickSort(int *arr, int start, int end){

    // base case
    if(start > end){
        return;
    }

    // partition
    int p = partition(arr, start, end);

    // recursive call for left part
    quickSort(arr, start, p-1);

    // recursive call for right part
    quickSort(arr, p+1, end);

}

int main(){

    int arr[] = { 6, 2, 8, 4, 10  };  

    int size  = sizeof(arr)/sizeof(int);

cout << endl; 

    cout << "Before quick sort: ";
    printArr(arr, size);

    quickSort(arr, 0, size-1);

cout << endl;
    
    cout << "After quick sort: ";
    printArr(arr, size);

cout << endl;
cout << endl;

}