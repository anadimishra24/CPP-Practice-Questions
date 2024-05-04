#include <bits/stdc++.h>
using namespace std;



/*
    Ques: https://leetcode.com/problems/median-of-two-sorted-arrays/
*/


// function for merge two array
vector<int> mergeTwoArray(vector<int>& nums1, vector<int>& nums2){
    int arrSize = nums1.size();
    int brrSize = nums2.size();

    int i =0, j = 0;

    vector<int> ans;

    while(arrSize != 0 && brrSize != 0){
        if(nums1[i] < nums2[j]){
            ans.push_back(nums1[i]);
            i++;
            arrSize--;
        }
        else{
            ans.push_back(nums2[j]);
            j++;
            brrSize--;
        }
    }
    while(arrSize != 0){
        ans.push_back(nums1[i]);
        i++;
        arrSize--;
    }
    while(brrSize != 0){  
        ans.push_back(nums2[j]);
        j++;
        brrSize--;
    }

    /* Instead of using 3 while loop we ca also do this in efficient manner

    while (i < arrSize || j < brrSize) {
        if (i < arrSize && (j >= brrSize || nums1[i] < nums2[j])) {
            ans.push_back(nums1[i]);
            i++;
        } else {
            ans.push_back(nums2[j]);
            j++;
        }
    } 
    */

    return ans;
}

/* My code also woks fine but its T.C is 0(m+n)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){

    vector<int> arr = mergeTwoArray(nums1, nums2);

    int size = arr.size();
    int index = -1;

    if(size % 2 != 0){
        index = size / 2;
        return static_cast<double>(arr[index]);
    }
    else{
        index = (size / 2) - 1;
       // cout << arr[index] <<  arr[index + 1] ;
        // int add = arr[index] + arr[index + 1];
        // cout << add << endl;
        return static_cast<double>(arr[index] + arr[index + 1]) / 2;
    }
}
*/

// copied from solution its T.C is O(log (m+n))
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
    cout << m << " " << n << endl;
        // Ensure nums1 is the smaller array to simplify the algorithm
        if (m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }

    cout << m << " " << n << endl;
        int left = 0, right = m;
        int mid = (m + n + 1) / 2; // Calculate the midpoint of the combined array

        while (left <= right) {
            int partition1 = left + (right - left) / 2;
            cout << "Part1 = " << partition1 << endl;

            int partition2 = mid - partition1;
            cout << "Part2 = " << partition2 << endl;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            cout << "\nmaxLeft1 = " << maxLeft1 << endl;

            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            cout << "minRight1 = " << minRight1 << endl;

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            cout << "\nmaxLeft2 = " << maxLeft2 << endl;

            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            cout << "minRight2 = " << minRight2 << endl;

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Found the correct partitions
                if ((m + n) % 2 == 0) {
                    // If the combined array has an even length, take the average
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    // If the combined array has an odd length, return the maximum of the left elements
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Adjust the partition1 to the left
                right = partition1;
            } else {
                // Adjust the partition1 to the right
                left = partition1 + 1;
            }
        }

        return 0.0; // Return 0.0 if no solution is found (shouldn't normally happen)
    }
int main(){

    vector<int> arr1 = {1, 3};
    vector<int> arr2 = {2};

    double median = findMedianSortedArrays(arr1, arr2);

    // vector<int> ans =  mergeTwoArray(arr1, arr2);

    // for(int num: ans){
    //     cout << num << " ";
    // }

    cout << endl;
    cout << "Median of two array is: " << median << endl;



    return 0;
}