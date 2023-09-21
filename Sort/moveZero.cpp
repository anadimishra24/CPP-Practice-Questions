#include <bits/stdc++.h>
using namespace std;




void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}


void moveZero(vector<int> arr, int size){

    int j = 0;
    for (int i = 1; i < size; i++){
       if(arr[i] != 0){
        swap(arr[i], arr[j]);
        j++;
       }
    }
    

cout << "Array after moving zero: " ;
printArr(arr, size);

}


int main(){

    vector<int> arr = { 0, 1, 0, 3, 12 };  
    int size  = arr.size();



cout << endl;

    
    moveZero(arr, size);

    return 0;

}


