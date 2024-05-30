#include <iostream>
using namespace std;

/*
 *  *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  * 
*/
void printStars1(int n){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

/*
 * 
 *  * 
 *  *  * 
 *  *  *  * 
 *  *  *  *  * 
 *  *  *  *  *  * 
*/
void printStars2(int n){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <=i; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

/*
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
6 6 6 6 6 6
*/
void printStars3(int n){
    
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
}

/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
*/
void printStars4(int n){
    
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
 *  *  *  *  *  *
 *  *  *  *  *
 *  *  *  *
 *  *  *
 *  *
 *
*/
void printStars5(int n){
    
    for(int i = 0; i <n; i++){
        for(int j = 0; j < n - i; j++){
            cout << " * " ;
        }
        cout << endl;
    }
}

/*
1 1 1 1 1
2 2 2 2
3 3 3
4 4
5
*/
void printStars6(int n){
    
    for(int i = 1; i <=n; i++){
        for(int j = 0; j <=n - i; j++){
            cout << i << " " ;
        }
        cout << endl;
    }
}

/*
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
*/
void printStars7(int n){
    
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=n - i+1; j++){
            cout << j << " " ;
        }
        cout << endl;
    }
}

/*
    *
   ***
  *****
 *******
*********
*/
void printStars8(int n){
    
    for(int i = 0; i <n; i++){
        // space
        for(int space = 0; space < n-i-1; space++){
            cout << " ";
        }
        // star
        for(int j = 0; j <2*i+1; j++){
            cout << "*" ;
        }
        // space
        for(int space = 0; space < n-i; space++){
            cout << " ";
        }
        cout << endl;
    }
}

/*
***********
 ********* 
  *******  
   *****   
    ***    
     * 
*/
void printStars9(int n){
    
    for(int i = 0; i <n; i++){
        // space
        for(int space = 0; space < i; space++){
            cout << " ";
        }
        // star
        for(int j = 0; j < 2*n -(2*i+1); j++){
            cout << "*" ;
        }
        // space
        for(int space = 0; space < i; space++){
            cout << " ";
        }
        cout << endl;
    }
}

/*
    *
   ***
  *****
 *******
*********
*********
 *******
  *****
   ***
    *
*/
void printStars10(int n){
    // merge 8 and 9
    for(int i = 0; i <n; i++){
        // space
        for(int space = 0; space < n-i-1; space++){
            cout << " ";
        }
        // star
        for(int j = 0; j <2*i+1; j++){
            cout << "*" ;
        }
        // space
        for(int space = 0; space < n-i; space++){
            cout << " ";
        }
        cout << endl;
    }

    for(int i = 0; i <n; i++){
        // space
        for(int space = 0; space < i; space++){
            cout << " ";
        }
        // star
        for(int j = 0; j < 2*n -(2*i+1); j++){
            cout << "*" ;
        }
        // space
        for(int space = 0; space < i; space++){
            cout << " ";
        }
        cout << endl;
    }
}

/*
*
**
***
****
*****
****
***
**
*
*/
void printStars11(int n){
/* One more way to do

    // Upper half
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

*/
    for(int i = 0; i < 2*n-1; i++){
        int star = i;
        if(i>n){
            star = 2*n-i;
        }
        for(int j = 0; j < star-1; j++){
            cout << "*" ;
        }
        
        cout << endl;
    }
}

/*
1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1
*/
void printStars12(int n){

/* My code for this pattern
    for(int i = 0; i <n; i++){
        if(i%2 == 0){
            for(int j = 0; j <=i; j++){
                if(j%2 == 0){
                    cout << 1 << " ";
                }
                else{
                    cout << 0 << " ";
                }
            }
        }
        else{
            for(int j = 0; j <=i; j++){
                if(j%2 == 0){
                    cout << 0 << " ";
                }
                else{
                    cout << 1 << " ";
                }
            }
        }
        cout << endl;
    }
*/
    // online code
    for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
        cout << (i + j) % 2 << " ";
    }
    cout << endl;
}

}

/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21
*/
void printStars13(int n){
    int k = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << k++ << " " ;
        }
        cout << endl;
    }
}

/*
A
A B
A B C
A B C D
A B C D E
A B C D E F
*/
void printStars14(int n){
    
    for(int i = 0; i < n; i++){
        char k = 'A';
        for(int j = 0; j <= i; j++){
            cout << k++ << " " ;
        }
        cout << endl;
    }
}

void printStars15(int n){
    
    for(int i = 0; i < n; i++){
        char k = 'A';
        for(int j = 0; j <= n-i; j++){
            cout << k++ << " " ;
        }
        cout << endl;
    }
}
int main() {
    int n;
    cout << "Enter you row number: ";
    cin >> n;

    // printStars1(n);
    // printStars2(n);
    // printStars3(n);
    // printStars4(n);
    // printStars5(n);
    // printStars6(n);
    // printStars7(n);
    // printStars8(n);
    // printStars9(n);
    // printStars10(n);
    // printStars11(n);
    // printStars12(n);
    // printStars13(n);
    // printStars14(n);
    printStars15(n);
    


    return 0;
}