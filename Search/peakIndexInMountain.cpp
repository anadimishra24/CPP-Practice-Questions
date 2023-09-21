#include <bits/stdc++.h>
using namespace std;


/*
    Ques:  https://leetcode.com/problems/peak-index-in-a-mountain-array/
    Vedio: https://www.youtube.com/watch?v=zD2Jg3alZV8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=13
*/




int peakIndexInMountain(vector<int> arr){

    int start = 0;
    int end = arr.size() - 1;

    // no need to run till start <= end bcoz it compare more time that already done previously
    while (start < end){
        int mid = start + ( end - start) / 2;

        if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }
        else{
            // here we not pass end = mid -1 bcoz it may lead our code to redundency if our mid itself is peak element and we do mid - 1 then we loose that peak element
            end = mid;
        }
    }

    return start;
}





int main(){

    vector<int> arr = {0, 10, 5, 2};     // output: return the index of peak of mountain (maximum number in arr) 1

    int ans = peakIndexInMountain(arr);

    cout << "peak of mountain is: " << ans << endl;
  

    return 0;

}

