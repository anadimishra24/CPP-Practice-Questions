#include <bits/stdc++.h>
using namespace std;


            /*Do it yourself*/

void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}


void selectionSort(vector<int> &arr, int size, int indx){

    // base case
    if(indx == size - 1){
        return;
    }
    

    // processing
    int minIndx = indx;

    for (int j = indx + 1; j < size; j++){
        if(arr[j] < arr[minIndx]){
            minIndx = j;
        }
    } 

    if(minIndx != indx){
        swap(arr[minIndx], arr[indx]); 
    } 
    
    // recursive call
    selectionSort(arr, size, indx +1);
}


int main(){

    vector<int>  arr = { 6, 2, 8, 4, 10  };  

    int size  = arr.size();

    cout << "Before selection sort: ";
    printArr(arr, size);
    
    selectionSort(arr, size, 0);

cout << endl;
    
    cout << "After selection sort: ";
    printArr(arr, size);

  

    return 0;

}


