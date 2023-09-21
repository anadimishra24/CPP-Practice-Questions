#include <bits/stdc++.h>
using namespace std;




void printArr(vector<int> arr, int size){
    for(int i = 0; i < size ; i++){
        cout << arr [i] << " , ";
    }
}


void reverseArrAtPoint(vector<int> arr, int size, int m){

    int start = m + 1;
    int end = size - 1;
    while (start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
       
    }
    

cout << "Array after reverse : " ;
printArr(arr, size);

}


int main(){

    vector<int> arr = { 1, 2, 3, 4, 5, 6 };  
    int size  = arr.size();
    int m = 3;

    cout << "Array before reverse : " ;
    printArr(arr, size);

cout << endl;
cout << endl;

    reverseArrAtPoint(arr, size, m);




    return 0;

}


