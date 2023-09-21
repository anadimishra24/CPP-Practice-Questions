#include <bits/stdc++.h>
using namespace std;




void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}


void rotateArray(vector<int> arr, int size, int k){

    // creating temporary vector of same size of orginal array
    vector<int> temp(size);

    for (int i = 0; i < size; i++){
        temp[(i+k) % size] = arr[i];
    }
    
    arr = temp;    

cout << "Array after rotate : " ;
printArr(arr, size);

}


int main(){

    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };  
    int size  = arr.size();
    int k = 3;

    cout << "Array before rotation : " ;
    printArr(arr, size);

cout << endl;
cout << endl;

    rotateArray(arr, size, k);    /* Output: Step 1: 7, 1, 2, 3, 4, 5, 6 
                                             Step 2: 6, 7, 1, 2, 3, 4, 5
                                             Step 3: 5, 6, 7, 1, 2, 3, 4   */



    return 0;

}


