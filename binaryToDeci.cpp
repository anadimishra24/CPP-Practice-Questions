#include <bits/stdc++.h>
using namespace std;



int calculateDecimal(int bin){

    int deci = 0;
    int i = 0;
    while(bin > 0){
        int rem = bin % 10;
        deci = deci + (rem * pow(2, i));
        i++;
        bin = bin / 10;
    }
    return deci;
}


int main(){

    
    int bin;
    cout << "Enter your binary number: ";
    cin >> bin;

    

    int decimal = calculateDecimal(bin);
    cout << "The decimal of given binary is: " << decimal << endl;


    return 0;
}



