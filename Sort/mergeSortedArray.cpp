/* Normally merged two sorted array

#include <bits/stdc++.h>
using namespace std;


void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}

vector<int> mergeSortedArr(vector<int> arr, int aSize, vector<int> brr, int bSize){

    vector<int> ans;

    int i = 0, j = 0;

    while(i < aSize && j < bSize){

        if(arr[i] < brr[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(brr[j]);
            j++;
        }
    }

   // remaining part of arr
    while(i < aSize){
        ans.push_back(arr[i]);
        i++;
    }

    // remaining part of brr
    while(j < bSize){
        cout << "enter in j"<< endl;
        ans.push_back(brr[j]);
        j++;
    }

    return ans;


}


int main(){

    vector<int> arr = { 1, 3, 5, 7, 9, 11 };  
    vector<int> brr = { 2, 4, 6, 8, 10, 12}; 

    int aSize  = arr.size();
    int bSize  = brr.size();


    // calling function for merge two sorted array
    vector<int> ans = mergeSortedArr(arr, aSize, brr, bSize);

    cout << endl;

    cout << "Merged array: " ;
    printArr(ans, ans.size());

    return 0;

}


*/



#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://leetcode.com/problems/merge-sorted-array/
    Video: https://www.youtube.com/watch?v=MPvr-LmaZmA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=21
*/

void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}

vector<int> mergeSortedArr(vector<int> arr, int aSize, vector<int> brr, int bSize){

    int i = 0, j = 0;

    while(i < aSize && j < bSize){

        if((arr[i] <= brr[j]) && arr[i] != 0){
            i++;
        }
        else{
            arr[i+1] = arr[i];
            arr[i] = brr[j];
            j++;
            i++;
        }
    }



    return arr;


}


int main(){

    vector<int> arr = { 1, 2, 3, 0, 0, 0 };  
    vector<int> brr = { 2, 5, 6};               // Output: 1 , 2 , 2 , 3 , 5 , 6 

    int aSize  = arr.size();
    int bSize  = brr.size();


    // calling function for merge two sorted array
    vector<int> ans = mergeSortedArr(arr, aSize, brr, bSize);

    cout << endl;

    cout << "Merged array: " ;
    printArr(ans, ans.size());

    return 0;

}


