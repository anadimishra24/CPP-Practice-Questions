#include <bits/stdc++.h>
using namespace std;


/*
    Ques:  https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2
    Vedio: https://www.youtube.com/watch?v=zD2Jg3alZV8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=13
*/


// function for getting the first occurrence of key
int firstOccurrence(vector<int> arr, int start, int end, int key){
    
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(key == arr[mid]){
            ans = mid;
            end = mid - 1;
        }
        else if(key < arr[mid]){
            end = mid - 1; 
        }
        else{
            start = mid + 1;
        }
    }

return ans;
}

// function for getting the last occurrence of key
int lastOccurrence(vector<int> arr, int start, int end, int key){

    int ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(key == arr[mid]){
            ans = mid;
            start = mid + 1;
        }
        else if(key < arr[mid]){
            end = mid - 1; 
        }
        else{
            start = mid + 1;
        }
    }

return ans;
}


// function for getting the first and last occurrence of key
pair<int, int> firstAndLastOccur(vector<int> arr, int start, int end, int key){

    pair<int, int> occurrence;


    occurrence.first = firstOccurrence(arr, start, end, key);

    occurrence.second = lastOccurrence(arr, start, end, key);


    return occurrence;
}


int main(){

    vector<int> arr = { 0, 0, 1, 1, 2, 2, 2, 2 };     // output: 4 and 7 

    int size  = arr.size();

    int key = 2;

    int start = 0, end = size -1;

    pair<int, int> ans = firstAndLastOccur(arr, start, end, key);

    cout << "The key's first occurrence is available at: " << ans.first << endl;
    cout << "The key's last occurrence is available at: " << ans.second << endl;
  

    return 0;

}


/*
    ->Introduction to Standard Template Library (STL) pair:

    pair<int, int> is a STL (Standard Template Library) 
    that used when we need value in pair form either similar data type or different data type.
    
    Syntax:
    pair <data_type1, data_type2> Pair_name (value1, value2) ;
   
    Example:
    
    pair<int, int> p;
    pair<int, char> p;
    pair<char, char> p;

    
    *Different ways to initialize pair:  
    pair  g1;         //default
    pair  g2(1, 'a');  //initialized,  different data type
    pair  g3(1, 10);   //initialized,  same data type
    pair  g4(g3);    //copy of g3
    
    *Another way to initialize a pair is by using the make_pair() function. 
    g2 = make_pair(1, 'a');
    
    *Another valid syntax to declare pair is:
    g2 = {1, 'a'};
*/