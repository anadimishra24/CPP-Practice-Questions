#include <bits/stdc++.h>
using namespace std;



int countDifferentWaysToReachStair(int nStairs){

    // base case
    if(nStairs < 0){
        return 0;
    }

    if(nStairs == 0){
        return 1;
    }

    int ans = countDifferentWaysToReachStair(nStairs - 1) + countDifferentWaysToReachStair(nStairs - 2);
    return  ans;
}


int main(){

    int nStairs = 4;

    int ans = countDifferentWaysToReachStair(nStairs);

    cout << "\nThere are " << ans << " different ways to climb the stairs.\n" << endl;
    return 0;
}