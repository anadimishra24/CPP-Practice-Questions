#include <bits/stdc++.h>
using namespace std;


/*
    Example Question
*/


//function for swaping alternate elemet of array
void swapAlternate(int arr[], int size){
    for (int i = 0; i < size; i=i+2){
        // checking increment for odd array
        if(i+1 < size){
            swap(arr[i], arr[i+1]);
        }
        
    }
    
}

// function for print the array
void print(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << ", ";
    }
    
}


int main(){

    // odd array
    int arr[7] = {12, 13, 8, 9, 3, 4, 7};

    // even array
    //int arr[6] = {12, 13, 8, 9, 3, 4};

    cout << "Array before swap : " ;
    print(arr, 7);

cout << endl;

    swapAlternate(arr, 7);

cout << endl;

    cout << "Array after swap : " ;
    print(arr, 7);
    
    return 0;

}
