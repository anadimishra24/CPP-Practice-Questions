#include <bits/stdc++.h>
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

    vector<vector<int>> totalSubSets = subsets(nums);

    // Print the subsets
    cout << "Subsets:" << endl;
    for (const auto& subset : totalSubSets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}