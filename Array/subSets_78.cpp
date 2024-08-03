#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void allTheSets(vector<int>& nums, int index, vector<int> output, vector<vector<int>>& result){
    if(index >= nums.size()){
    result.push_back(output);
    return;
    }

    // recursive call for the remaining sets

    // exclude the element
    allTheSets(nums, index+1, output, result);

    // incluse the element
    int element = nums[index];
    output.push_back(element);
    allTheSets(nums, index+1, output, result);

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> output;
    vector<vector<int>> result;
    int index = 0;

    allTheSets(nums, index, output, result);

    return result;        
}


int main(){

    vector<int> nums = {1,2,3};

    vector<vector<int>> subset = subsets(nums);

    // Print all subsets
    for (const auto& s : subset) {
        cout << "{ ";
        for (const auto& el : s) {
            cout << el << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}