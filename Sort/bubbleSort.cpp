#include <bits/stdc++.h>
using namespace std;



void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}
void bubbleSort(vector<int> arr, int size){

    // for rount 1 to size - 1
    for (int i = 1; i < size; i++){
        // process all the element for each round
        for (int j = 0; j < size - i; j++){         // j < size - i bcoz at each round last element is sorted so decrement the loop
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
        
 
    }
    

cout << "Array after bubble sort: " ;
printArr(arr, size);

}


int main(){

    vector<int> arr = { 6, 2, 8, 4, 10 };  
    int size  = arr.size();

    cout << "Array before bubble sort: " ;
    printArr(arr, size);

cout << endl;

    // calling function for bubble sort
    bubbleSort(arr, size);

    return 0;

}


