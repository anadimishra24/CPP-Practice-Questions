#include <bits/stdc++.h>
using namespace std;


/*
    Vedio: https://www.youtube.com/watch?v=6z2HK4o8qcU&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=14
*/


/* Pivot: is that element in rotated sorted array after that all elements are in order or in sequence 
        i.e 1 is the pivot element in arr and it's index is 3*/


int pivotIndex(vector<int> arr){

    int start = 0;
    int end = arr.size() - 1;
    

    while (start < end){
        int mid = start + ( end - start) / 2;
        
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }

        
    }

    return start;
}





int main(){

    vector<int> arr = {5, 6, 7, 1, 2, 3, 4};     // arr is rotated sorted array 

    int ans = pivotIndex(arr);

    cout << "Pivot element index is: " << ans << endl;
  

    return 0;

}

