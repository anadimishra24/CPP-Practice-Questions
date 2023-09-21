#include <bits/stdc++.h>
using namespace std;


/*
    Ques: https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1
    Vedio: https://www.youtube.com/watch?v=oVa8DfUDKTw&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=10
*/



// This solution is workin fine but not pass the time limit
/*vector<int> intersectionOfArray(vector<int> &arr1, vector<int> &arr2){

    // creating vector to store value
    vector<int> value;
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
           if(arr1[i] == arr2[j]){
                value.push_back(arr2[j]);
                arr2[j] = -1;
                break;
           }
        }
        
    }
    return value;
}
*/


// new solution with no TLE problem
vector<int> intersectionOfArray(vector<int> &arr1, vector<int> &arr2){
    int i = 0, j = 0;

    vector<int> value;
    while (i < arr1.size() && j < arr2.size()){
        if(arr1[i] == arr2[j]){
            value.push_back(arr2[j]);
            i++;
            j++;
        } 
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    return value; 
}

int main(){

    vector<int> arr1 =  {1, 2, 2, 2, 3, 4};    // output :2 2 3
    vector<int> arr2 = {2, 2, 3, 3};


    vector<int> ans = intersectionOfArray(arr1, arr2);   

    cout << "Intersection of arr1 and arr2 is: ";
    for(int num: ans){
        cout << num << " ";
    }


    return 0;
}