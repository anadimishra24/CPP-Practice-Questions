#include <bits/stdc++.h>
using namespace std;

/* Decimal to Binary
int reverse(int num){

    int rev = 0;
    while(num != 0){
        int rem = num % 10;
        rev = (rev * 10) + rem;
        num = num / 10;
    }

    return rev;
}

int deciToBin(int n){

    int bin = 0;
    while(n != 0){
        bin = bin * 10 + (n % 2) ;
        n = n / 2;
    }
    return reverse(bin);
}



int main(){

    int n ;
    cout << "Enter your number: ";
    cin >> n;

    int ans = deciToBin(n);
    cout << "Binary of number: "<< ans << endl;

    return 0;
}
*/


/* Count the number of 1 bits*/
int main(){

    uint32_t n = 00000000000000000000000000001011;


    int numberOf1bits = 0;

    while(n != 0){

        if(n & 1){
            numberOf1bits++;
        }
        n = n >> 1;
    }

    cout << "Number of one bits in n is: " << numberOf1bits << endl;
    return 0;
}



























/*
    Ques: https://www.codingninjas.com/studio/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1
    Vedio: https://www.youtube.com/watch?v=oVa8DfUDKTw&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=10
*/





/*
// new solution with no TLE problem
vector<int> pairSum(vector<int> &arr, int key){
    int i = 0, j = 0;

    vector<int> sum;

    for (int i = 0; i < arr.size(); i++){
        for (int j = i+1; j < arr.size(); j++){
            for(int k = j+1; k < arr.size(); k++){
                if(arr[i] + arr[j] + arr[k] == key){
                    sum.push_back(arr[i]);
                    sum.push_back(arr[j]);
                    sum.push_back(arr[k]);
                }
            }
        }
        
    }
    
    return sum; 
}

int main(){

    vector<int> arr =  {10, 5, 5, 5, 2};    // output: 1,4 and 2,3     || sum = 5
    // vector<int> arr = {2, -3, 3, 3, -2};   // output: -3 3 || -3 3 || -2 2
    int s = 12;          // int s = 0;


    vector<int> ans = pairSum(arr, s);   

    cout << "Pair sum:";
    for (int i = 0; i < ans.size(); i++){
        
            cout << ans[i] << " " ;
        }
        cout << endl ; 
    


    return 0;
}
*/


/*
Triplet Sum

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> findTriplets(std::vector<int>& arr, int targetSum) {
    std::vector<std::vector<int>> triplets;
    int n = arr.size();

    // Sort the array in ascending order
    std::sort(arr.begin(), arr.end());

    // Fix the first element and find the remaining two elements
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];
            if (currentSum == targetSum) {
                // Found a triplet, add it to the result
                triplets.push_back({arr[i], arr[left], arr[right]});

                // Skip duplicates for the second element
                while (left < right && arr[left] == arr[left + 1])
                    left++;
                // Skip duplicates for the third element
                while (left < right && arr[right] == arr[right - 1])
                    right--;

                // Move both pointers inward
                left++;
                right--;
            } else if (currentSum < targetSum) {
                // Sum is less than the target, move the left pointer to increase the sum
                left++;
            } else {
                // Sum is greater than the target, move the right pointer to decrease the sum
                right--;
            }
        }
    }

    return triplets;
}

int main() {
    int n, targetSum;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the target sum: ";
    std::cin >> targetSum;

    std::vector<std::vector<int>> triplets = findTriplets(arr, targetSum);

    std::cout << "Triplets with sum " << targetSum << " are:\n";
    for (const auto& triplet : triplets) {
        std::cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << std::endl;
    }

    return 0;
}

*/