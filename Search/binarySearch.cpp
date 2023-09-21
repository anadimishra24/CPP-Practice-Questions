#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int start, int end, int key){

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(key == arr[mid]){
            return mid;
        }
        else if(key < arr[mid]){
            end = mid - 1; 
        }
        else{
            start = mid + 1;
        }
    }
return -1;
}


int main(){

    int arr[] = { 2, 3, 4, 10, 40 };  

    int size  = sizeof(arr)/sizeof(int);

    int key = 40;

    int start = 0, end = size -1;

    int ans = binarySearch(arr, start, end, key);

    cout << "The key is available at: " << ans << endl;
  

    return 0;

}


