#include <bits/stdc++.h>
using namespace std;



int main(){

    
    int i = 5;

    // creating reference variable
    int &j = i;

    cout << " The value of i is " << i << endl;
    cout << " The value of j is " << j << endl;

cout << endl;

    i++;

    cout << " After increment of i the value of i is " << i << endl;
    cout << " After increment of i the value of j is " << j << endl;

cout << endl;

    j++;

    cout << " After increment of j the value of i is " << i << endl;
    cout << " After increment of j the value of j is " << j << endl;  

    return 0;
}



