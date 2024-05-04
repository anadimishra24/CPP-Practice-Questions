#include <bits/stdc++.h>
using namespace std;


/* Sliding window
    1. Compute sum of first window of size k

    2. Compute sums of remaining windows by removing first element of previous
       window and adding last element of current window.
*/

double maxAvg(vector<int>nums, int k){

    /* Hit TLE 
    int start = 0, size = num.size(), sum = 0;
    cout << "size = " << size << endl;
    double avg = 0.00, curr_avg = 0.00;
    

    for(int i = start; i <= size - k; i++){
        double sum = 0.00;
        for(int j = 0; j < k; j++){
            sum = sum + num[i+j];
            cout << "sum = " << sum << endl;
        }
        curr_avg = (sum) / k;
        cout << "Current ang = " << curr_avg << endl;
        avg = max(avg, curr_avg);
    }
    return avg;
    */

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

int main(){

    /*
    vector<int>num = {1,12,-5,-6,50,3};
    int k = 4;
    double ans = maxAvg(num, k);

    cout << "Max average = " << ans << endl;
    */

   string s = "abciiidef" ;
   int k = 3;

   int ans = maxVowels(s,k);

   cout << "Ans = " << ans << endl;

    return 0;
}