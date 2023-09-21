#include <bits/stdc++.h>
using namespace std;


bool isPossibleSol(vector<int> arr, int size, int m, int mid){

    int cowCount = 1;
    int lastPos = arr[0];

    for (int i = 0; i < size; i++){
        if(arr[i] - lastPos >= mid){
            cowCount++;
            if(cowCount == m){
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;    
}

int aggresiveCows(vector<int> arr, int size, int m){

    sort(arr.begin(), arr.end());

    int start = 0;
    int maxi = arr[size-1] ;


    /* No need to do this bcoz we sorted the array using sort()
    for (int i = 0; i < size; i++){
        maxi = max(maxi,arr[i]);
    }
    */

    int end = maxi;
    int ans = -1;

    while(start < end){
        int mid = start + (end - start) / 2;

        if(isPossibleSol(arr, size, m, mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
return ans;
}


int main(){

    vector<int>  arr = { 4, 2, 1, 3, 6 };  

    int size  = arr.size();

    int m = 2;

    int ans = aggresiveCows(arr, size, m);

    cout << "The maximum of minimum distance between cows: " << ans << endl;
  

    return 0;

}


