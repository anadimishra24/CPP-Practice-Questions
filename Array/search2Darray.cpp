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


bool waveMatrix(vector<vector<int>> mat, int key){

    int rowSize = mat.size();
    int colSize = mat[0].size();

    int start = 0;
    int end = (rowSize * colSize) - 1;

    int mid = start + (end - start)/2;

    while(start <= end){

        int element = mat[mid / colSize][mid % colSize];

        if(element == key){
            return true;
        }

        if(element < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    return false;
}

int main(){

    vector<vector<int>> mat =  { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };

    printArr(mat);

cout << endl;

    int key = 16;


    if(waveMatrix(mat, key)){
        cout << "Element found in 2D matrix.\n";
    }
    else{
        cout << "Element not found in 2D matrix.\n";
    }
    

    return 0;
}


