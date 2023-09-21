#include <bits/stdc++.h>
using namespace std;


/*
    Ques:  https://www.codingninjas.com/studio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2
    Vedio: https://www.youtube.com/watch?v=6z2HK4o8qcU&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=14
*/




int binarySearch(int num){

    vector<int> arr;
    for (int i = 0; i < num; i++){
        arr.push_back(i);
    }
    
    int start = 0, end = arr.size()-1;
    int ans = 0;

    while(start <= end){
        int mid = start + (end - start) / 2;

        int sqr = arr[mid] * arr[mid];
        if(num < sqr){
            end = mid - 1;
        }
        else if(num > sqr){
            ans = mid;
            start = mid + 1;
        }
        else{
            return mid;
        }
    }
return ans;
}


int squareRootOfNumber(int num){


    int sqrt = binarySearch(num);

    return sqrt;
}





int main(){

    int n = 100; 

    int ans = squareRootOfNumber(n);

    cout << "Square root of number is: " << ans << endl;
  

    return 0;

}

