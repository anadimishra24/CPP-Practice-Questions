#include <bits/stdc++.h>
using namespace std;


// printing the array
void printArr(int arr[], int size){
    for(int i = 0; i < size ; i++){
        cout << arr[i] << " , ";
    }
}


void merge(int *arr, int start, int end){
    
    int mid = (start + end) / 2;

    // length of two array
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // creating two array
    int *first = new int[len1];
    int *second = new int[len2];

    // copyting value
    int mainArrIndx = start;
    for (int i = 0; i < len1; i++){
        first[i] = arr[mainArrIndx++];
    }

    mainArrIndx = mid + 1;
    for (int i = 0; i < len2; i++){
        second[i] = arr[mainArrIndx++];
    } 

    // merge two sorted array first and second
    int indx1 = 0, indx2 = 0;
    mainArrIndx = start;

    while(indx1 < len1 && indx2 < len2){

        if(first[indx1] < second[indx2]){
            arr[mainArrIndx++] = first[indx1++];
        }
        else{
           arr[mainArrIndx++] = second[indx2++];
        }
    }

   // remaining part of first array
    while(indx1 < len1){
        arr[mainArrIndx++] = first[indx1++];
    }

    // remaining part of second array
    while(indx2 < len2){
        arr[mainArrIndx++] = second[indx2++];
    }

    // memory free
    delete []first;
    delete []second;
}


void mergeSort(int *arr, int start, int end){

    // base case
    if(start > end){
        return;
    }

    int mid = (start + end )/ 2;

    // left part sort
    mergeSort(arr, start, mid-1);

    // right part sort
    mergeSort(arr, mid+1, end);

    // merging array
    merge(arr, start, end);
}

int main(){

    int arr[] = { 6, 2, 8, 4, 10  };  

    int size  = sizeof(arr)/sizeof(int);

    cout << "Before merge sort: ";
    printArr(arr, size);
    
    mergeSort(arr, 0, size-1);

cout << endl;
    
    cout << "After merge sort: ";
    printArr(arr, size);

}