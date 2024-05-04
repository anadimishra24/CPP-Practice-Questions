#include <bits/stdc++.h>
using namespace std;



// check the cost to make string valid
int minimumCostToMakeStringValid(string str){
  	
    //odd condition (there is no any invalid string becoz # opening '{' == # closing '}' and their sum is always odd )
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
        //stack contains invalid expression
        int countOfCloseBrac = 0, countOfOpenBrac = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                countOfOpenBrac++;
            }
            else
            {
                countOfCloseBrac++;
            }
            s.pop();
        }
        
		int ans = (countOfCloseBrac+1)/2 + (countOfOpenBrac+1)/2;
        return ans;
}


int main(){

    /*  Input
        1. {}}{}} = 1
        2. {{{{ = 2
        3. {{{}} = -1
    
    */
    string expression = "{}}{}}"; 

    int cost = minimumCostToMakeStringValid(expression);
    
    cout << "Minimum cost to make a string valid is: " <<  cost <<endl;


    return 0;
}
