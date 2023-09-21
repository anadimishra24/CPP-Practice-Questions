#include <bits/stdc++.h>
using namespace std;



/*
    Ques: https://leetcode.com/problems/unique-number-of-occurrences/
*/


bool uniqueOccurrences( vector<int>& arr) {
    // Step 1: Create an unordered_map to store the count of occurrences for each integer.
     unordered_map<int, int> occurrences;
    for (int num : arr) {
        occurrences[num]++;
    }

    // Step 2 and 3: Extract the values (counts) from the unordered_map.
     unordered_set<int> counts;
    for (const auto& kv : occurrences) {
        counts.insert(kv.second);
    }

    // Step 4: Check if all the values in the counts set are unique.
    return counts.size() == occurrences.size();
}

int main() {
    // Example usage:
     vector<int> arr1 = {1, 2, 2, 3, 3};
     cout <<  boolalpha << uniqueOccurrences(arr1) <<  endl; // Output: false

     vector<int> arr2 = {1, 2, 2, 3, 3, 3, 3};
     cout <<  boolalpha << uniqueOccurrences(arr2) <<  endl; // Output: true

    return 0;
}
