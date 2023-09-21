#include <bits/stdc++.h>
using namespace std;


void printArr(vector<vector<int>> mat){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}


void waveMatrix(vector<vector<int>> mat, int colSize, int rowSize ){


    for (int col = 0; col < colSize; col++){ 
    
        // when column is odd 
        if(col & 1){
            for (int row = rowSize - 1; row >= 0 ; row--){
                cout << mat[row][col] << " ";
            }
        }
        else{
            // when column is even
            for (int row = 0; row < rowSize; row++){
                cout << mat[row][col] << " ";
            }           
        }
        
    }
}

int main(){

    vector<vector<int>> mat =  { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    printArr(mat);

cout << endl;

    int colSize = 3;
    int rowSize = 3;

    waveMatrix(mat, colSize, rowSize);
    

    return 0;
}


