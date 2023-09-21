#include <bits/stdc++.h>
using namespace std;


void printArr(vector<vector<int>> mat){
    
    int rowSize = mat.size();
    int colSize = mat[0].size();

    for (int i = 0; i < rowSize; i++){
        for (int j = 0; j < colSize; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}


bool waveMatrix(vector<vector<int>> mat, int key){

    int rowSize = mat.size();
    int colSize = mat[0].size();        

    int rowIndx = 0;
    int colIndx = colSize - 1;


    while(rowIndx < rowSize && colIndx >= 0){

        int element = mat[rowIndx][colIndx];

        if(element == key){
            return true;
        }

        if(element < key){
            rowIndx++;
        }
        else{
            colIndx--;
        }

    }
    return false;
}

int main(){

    vector<vector<int>> mat =  { {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, 
                                {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

    printArr(mat);

cout << endl;

    int key = 5;


    if(waveMatrix(mat, key)){
        cout << "Element: " << key <<" found in 2D matrix.\n";
    }
    else{
        cout << "Element: " << key <<" not found in 2D matrix.\n";
    }
    

    return 0;
}


