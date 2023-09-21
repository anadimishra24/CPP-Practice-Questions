#include <bits/stdc++.h>
using namespace std;



int main(){


    int row;
    cout << "Enter the row size of array: ";
    cin >> row;

    int col;
    cout << "Enter the col size of array: ";
    cin >> col;

    /*creating dynamic 2D array of size 'row' and 'col'bbbbb that store in heap memory*/
    int **arr = new int*[row];

    for (int i = 0; i < row; i++){
        arr[i] = new int[col];
    }
    
    // taking input in 2D array
    cout << "Enter your array elements..." << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
           cin >> arr[i][j]; 
        }
    }
    
cout << endl;

    // printing the 2D array
    cout << "Printing the array..." << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
           cout <<  arr[i][j] << " ";  
        }
        cout << endl;
    }

    //free dynamically allocated memory (first of all we release memory of rows otherwise it shows memory leakage )
    for (int i = 0; i < row; i++){
        delete [] arr[i];
    }
   
    // release the memmory of array poiter that holds all the rows
    delete []arr;


    return 0;
}