#include <bits/stdc++.h>
using namespace std;
 


 bool isSorted(int arr[], int size){

    // base case
    if(size == 0 || size == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool ans = isSorted(arr + 1, size - 1);
        return ans;
    }
    
 }

int main(){

    int arr[] = {2, 3, 5, 6, 7};
    int size = 5;


    if(isSorted(arr, size)){
        cout <<"YES, array is sorted.\n" << endl;
    }
    else{
        cout <<"NO, array is not sorted.\n" << endl;
    }


    return 0;
}