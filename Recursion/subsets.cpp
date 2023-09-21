#include <bits/stdc++.h>
using namespace std;


void  solve(vector<int> arr, vector<int> output, int indx, vector<vector <int>> &ans){

    // base case
    if(indx == arr.size()){
        ans.push_back(output);
        return;
    }

    // exclude
        // cout << "Ex Indx == "<< indx << " " << endl;
    solve(arr, output, indx+1, ans);

    // include
    int element = arr[indx];
        // cout << "In Indx == "<< indx << " " << endl;
    output.push_back(element);
    solve(arr, output, indx+1, ans);

}

vector<vector <int>> subsets(vector<int> &arr){
    vector<vector <int>> ans;
    vector<int> output;
    int indx = 0;

    solve(arr, output, indx, ans);
    return ans;
}

int main(){

    vector <int> arr = {1, 2, 3};

    vector<vector <int>> ans = subsets(arr);

    for (int i = 0; i < ans.size(); i++){
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++){
            cout  << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
    

    return 0;
}