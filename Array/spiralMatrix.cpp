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


void spiralMatrix(vector<vector<int>> mat ){

    int rowSize = mat.size();
    int colSize = mat[0].size();

    int count = 0;
    int total = rowSize * colSize;

    int colMin = 0;
    int colMax = colSize - 1;

    int rowMin = 0;
    int rowMax = rowSize - 1;

    while(count < total){

        for (int col = colMin; col <= colMax; col++){ 
            cout << mat[rowMin][col] << " ";
            count++;
        }
        rowMin++;

        for (int row = rowMin; row <= rowMax; row++){
            cout << mat[row][colMax] << " ";
            count++;
        }           
        colMax--;

        for (int col = colMax; col >= colMin; col--){ 
            cout << mat[rowMax][col] << " ";
            count++;
        }  
        rowMax--;

        for (int row = rowMax; row >= rowMin; row--){
            cout << mat[row][colMin] << " ";
            count++;
        }  
        colMin++;  
    }
}

int main(){

    vector<vector<int>> mat =  { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    printArr(mat);

cout << endl;



    spiralMatrix(mat);
    

    return 0;
}


