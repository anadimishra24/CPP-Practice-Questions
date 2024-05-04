#include <bits/stdc++.h>
using namespace std;

char isLower(char ch){
    char ans;
    if(islower(ch)){
        return ch;
    }
    else{
        ans = ch - 'A' + 'a';
        return ans;
    }
}

int main(){

    char an = isLower('B');
    cout << " Answer = " << an << endl;
    return 0;

}