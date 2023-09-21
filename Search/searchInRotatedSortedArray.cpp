#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2
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


int binarySearch(vector<int> arr, int start, int end, int key){

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


int searchInRotatedSortedArray(vector<int> arr, int key){

    int start = 0;
    int end = arr.size() - 1;
    

    int pivotIndx = pivotIndex(arr);

    // cout << "Pivot element is: " << pivotIndx << endl;

    if(key == arr[pivotIndx]){
        return pivotIndx;
    }
    else if(key >= arr[pivotIndx] && key <= arr[end]){
        return binarySearch(arr, pivotIndx, end, key);
    }
    else{
        return binarySearch(arr, 0, pivotIndx-1, key);
    }
}





int main(){

    vector<int> arr = {12, 15, 18, 2, 4};     // key = 2; output = 3
                  
    //vector<int> arr = {2, 3, 5, 8};       // key = 11; output = -1
    
    int k = 2; 

    int ans = searchInRotatedSortedArray(arr, k);

    cout << "Element found at index: " << ans << endl;
  

    return 0;

}

