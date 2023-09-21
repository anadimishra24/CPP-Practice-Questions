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


void maxRow(vector<vector<int>> mat){

    int rowSize = mat.size();
    int colSize = mat[0].size();

    
    for (int row = 0; row < rowSize; row++){
        int ans = 0;
        for (int col = 0; col < colSize; col++){
            if(ans < mat[row][col]){
                ans = mat[row][col];
            }
        }
        cout << "Max element of " << row <<"th row is: " << ans << endl;
    }

    
}

int main(){

    vector<vector<int>> mat =  { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };

    printArr(mat);

cout << endl;


    maxRow(mat);
    

    return 0;
}