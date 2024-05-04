#include <bits/stdc++.h>
using namespace std;


/* Sliding window
    1. Compute sum of first window of size k

    2. Compute sums of remaining windows by removing first element of previous
       window and adding last element of current window.
*/

double maxAvg(vector<int>nums, int k){

    int start = 0, size = nums.size();
    double sum = 0.0;
    double avg = INT_MIN;

    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    avg = sum / k;

    for (int i = k; i < size; i++) {
        sum += nums[i] - nums[i - k];
        avg = max(avg, sum / k);  
    }

    return avg;
}

int maxVowels(string s, int k) {
        
        int max_vowel = 0, count = 0;

        // calculate the occurence of vowel in first window
        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count++;
            }
        }
        max_vowel = count;
        // calculate the vowel for other windows by sliding it by 1
        for(int i = k; i < s.size(); i++){
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u'){
                count--;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }
            max_vowel = max(max_vowel,count);
        }
       
            
        
        return max_vowel;




    max_vowel = count; // First maximum is the count of the first window
}

vector<int> maxElement(vector<int> num, int k){

    int max = 0;
    int sum = 0;
    vector<int>res;

    // get the maximum form the first window
    for(int i = 0; i < k; i++){
        if(num[i] > max){
            max = num[i];
        }
    }
    // max_sum = sum;
    res.push_back(max);

/*
Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation:Maximum of 1, 2, 3 is 3
            Maximum of 2, 3, 1 is 3
            Maximum of 3, 1, 4 is 4
            Maximum of 1, 4, 5 is 5
            Maximum of 4, 5, 2 is 5 
            Maximum of 5, 2, 3 is 5
            Maximum of 2, 3, 6 is 6

*/
    // get the maximum for remaing sub array by sliding the window +1
    for(int i = k; i < num.size(); i++){
        sum = 0;
        sum += num[i-k] + num[i];
    }

}

int main(){

    /* max avg
    vector<int>num = {1,12,-5,-6,50,3};
    int k = 4;
    double ans = maxAvg(num, k);

    cout << "Max average = " << ans << endl;
    */

   /* max Vowel
   string s = "abciiidef" ;
   int k = 3;

   int ans = maxVowels(s,k);

   cout << "Ans = " << ans << endl;
   */

    vector<int> num = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;

    vector<int> ans = maxElement(num,k);

    cout << "Max sum from the sub array: ";
    for (auto count: ans){
        cout << count << " ";
    }

    return 0;
}