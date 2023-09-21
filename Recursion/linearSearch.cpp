#include <bits/stdc++.h>
using namespace std;


bool isPresent(int arr[], int size, int key){

    // base case
    if(size == 0){
        return false;
    }
    
    if(arr[0] == key){
        return true;
    }

    // bool ans = isPresent(arr + 1, size - 1, key);
    // return ans;

    return isPresent(arr + 1, size - 1, key);
}


int main(){

    int arr[] = {9, 4, 1, 8, 4, 5};
    int size = 6;
    int key = 8;

    if(isPresent(arr, size, key)){
        printf("\nKey is present in the array.\n");
    }
    else{
        printf("\nKey is not present in the array.\n");
    }


    return 0;
}