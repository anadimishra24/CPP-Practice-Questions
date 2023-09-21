#include <bits/stdc++.h>
using namespace std;


bool isPossibleSol(vector<int> arr, int size, int m, int mid){

    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < size; i++){
        if( pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if( studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;    
}

int bookAllocation(vector<int> arr, int size, int m){

    int start = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }

    int end = sum;
    int ans = -1;

    while(start < end){
        int mid = start + (end - start) / 2;

        if(isPossibleSol(arr, size, m, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
return ans;
}


int main(){

    vector<int>  arr = { 10, 20, 30, 40 };  

    int size  = arr.size();

    int m = 2;

    int ans = bookAllocation(arr, size, m);

    cout << "The minimum of maximum pages alloted: " << ans << endl;
  

    return 0;

}


