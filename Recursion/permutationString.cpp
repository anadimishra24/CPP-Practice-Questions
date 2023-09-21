#include <bits/stdc++.h>
using namespace std;



/*
    Extra Ques: https://www.codingninjas.com/studio/problems/permutations-of-a-string_985254

    Ques: https://leetcode.com/problems/permutations/
    Video: https://www.youtube.com/watch?v=va3NEycUxsg&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=43
*/


vector <vector<int>> permutationString(vector<int>  nums, vector<vector<int>> &ans, int indx){


    // base case    
    if(indx >= nums.size()){
        ans.push_back(nums);
        return ans;
    }
    

    for (int i = indx; i < nums.size(); i++){
        
        swap(nums[indx], nums[i]);
        permutationString(nums, ans, indx+1);
        // backtrack
        swap(nums[indx], nums[i]);
    }
    
    return ans;
}


int main(){

    vector<int> nums = {1, 2, 3};

    vector <vector<int>> ans;
    
    int indx = 0;

    vector <vector<int>> result = permutationString(nums, ans, indx);

cout << endl;

    cout << "Permuation of given integer array is: ";
    for (int i = 0; i < result.size(); i++){
        cout << "[";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "] ";
    }

cout << endl << endl;

    return 0;
}