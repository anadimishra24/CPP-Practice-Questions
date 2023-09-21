#include <bits/stdc++.h>
using namespace std;



bool binarySearch(int *arr, int start, int end, int key){

    // base case
    if(start > end){
        return false;
    }

    // processing
    int mid = start + (end - start) / 2;
    if(arr[mid] == key){
        return true;
    }
    
    if(arr[mid] > key){
        end = mid - 1;
        binarySearch(arr, start, end, key);
    }
    else{
        start = mid  + 1;
        binarySearch(arr, start, end, key);
    }

}


int main(){

    int arr[] = {2, 3, 5, 7, 9, 10};
    int size = sizeof(arr)/sizeof(int);
    int key = 9;
    int start = 0, end = size - 1;
    
    if(binarySearch(arr, start, end, key)){
        printf("\nKey is present in the array.\n");
    }
    else{
        printf("\nKey is not present in the array.\n");
    }

    return 0;
}