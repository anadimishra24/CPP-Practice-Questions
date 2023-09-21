#include <bits/stdc++.h>
using namespace std;


int main(){

    char *arr = "anadi";

    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++){
        count++;
    }
    
    cout << arr<< endl;     //anadi♠
    cout << count << endl;

    return 0;
}