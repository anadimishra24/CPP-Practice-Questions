#include <bits/stdc++.h>
using namespace std;




void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}


bool checkRotatedSortedArray(vector<int> arr, int size){

   int count = 0;

    for (int i = 1; i < size; i++){
        if(arr[i-1] > arr[i]){
            count++;
        }
    }
    
    if(arr[size-1] > arr[0]){
        count++;
    }

    if(count <= 1){
        return true;
    }
    else{
        return false;
    }
   // return count <= 1;        // instaed of writing 'if' we simply reuturn this
   
}


int main(){

    vector<int> arr = { 3, 4, 5, 1, 2 };  
    int size  = arr.size();


    cout << "Array: " ;
    printArr(arr, size);

cout << endl;
cout << endl;

    if(checkRotatedSortedArray(arr, size)){
        cout << "TRUE.\n"<< endl;
    } 
    else{
        cout << "FALSE.\n"<< endl;
    }   



    return 0;

}


