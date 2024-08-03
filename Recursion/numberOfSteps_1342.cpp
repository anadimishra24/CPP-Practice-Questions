#include <bits/stdc++.h>
#include <iostream>
using namespace std;


/* 1342. Number of Steps to Reduce a Number to Zero
   https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero */



int helper(int num, int steps){
        if(num == 0){
            return steps;
        }
        if(num % 2 == 0){
            return helper(num/2, steps+1);
        }
        else{
            return helper(num-1, steps+1);
        }
    }

int numberOfSteps(int num) {
    return helper(num, 0);        
}

int main() {

    
   int num = 14;

   int count = numberOfSteps(num);

   cout << "Number of steps to reduce " << num  <<  " to zero is: " <<  count << endl;
    
    return 0;
}