#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://www.codingninjas.com/studio/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1
    Vedio: https://www.youtube.com/watch?v=oVa8DfUDKTw&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=10
*/






// new solution with no TLE problem
vector<vector<int>> pairSum(vector<int> &arr, int key){
    int i = 0, j = 0;

    vector<vector<int>> sum;

    for (int i = 0; i < arr.size(); i++){
        vector<int> v1;
        for (int j = i+1; j < arr.size(); j++){
           if(arr[i] + arr[j] == key){
                v1.push_back(arr[i]);
                v1.push_back(arr[j]);
           }
        }
        sum.push_back(v1);
    }
    
    sort(sum.begin(), sum.end());
    return sum; 
}

int main(){

    vector<int> arr =  {1, 2, 3, 4, 5};    // output: 1,4 and 2,3     || sum = 5
    // vector<int> arr = {2, -3, 3, 3, -2};   // output: -3 3 || -3 3 || -2 2
    int s = 5;          // int s = 0;


    vector<vector<int>> ans = pairSum(arr, s);   

    cout << "Pair sum:";
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " " ;
        }
        cout << endl ; 
    }
    


    return 0;
}