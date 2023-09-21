#include <bits/stdc++.h>
using namespace std;




void selectionSort(vector<int> arr, int size){

    
    for (int i = 0; i < size; i++){
        int minIndx = i;
        for (int j = i+1; j < size; j++){

            if(arr[j] < arr[minIndx]){
                minIndx = j;
            }
        }  
        swap(arr[minIndx], arr[i]); 
    }

    cout << endl;
    cout << "After selection sort: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " , " ;
    }
}


int main(){

    vector<int>  arr = { 6, 2, 8, 4, 10  };  

    int size  = arr.size();

    cout << "Before selection sort: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " , " ;
    }
    

    selectionSort(arr, size);

cout << endl;


  

    return 0;

}


