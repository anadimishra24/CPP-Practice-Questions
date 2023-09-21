#include <bits/stdc++.h>
using namespace std;



/* Ques: https://www.spoj.com/problems/EKO/ */

int woodCuttingSize(vector<int> arr, int key){

    sort(arr.begin(), arr.end());

    int size = arr.size();

    int start = 0, end = arr[size-1];

    while(start <= end){
        int mid = start + (end - start) / 2;

        int sum = 0;

        int i = 0;
        while (i < size){
            if(mid < arr[i]){
                sum = sum + (arr[i] - mid);
                i++;
            }  
            else{
                i++;
            }
        }
        
        
        if(sum == key){
            return mid;
        }
        else if(sum > key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
return -1;
}


int main(){

   // vector<int> arr = { 20, 15, 10, 17 };   // M = 7; Output: 15

    vector<int> arr = { 4, 42, 40, 26, 46 };  // M = 20; output: 36

    int size  = arr.size();

    int M = 20;

    int ans = woodCuttingSize(arr, M);

    cout << "The height of blade for cutting the exact " << M << " meter of woods: " << ans << endl;
  

    return 0;

}


