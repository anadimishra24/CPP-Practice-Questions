#include <bits/stdc++.h> 
using namespace std;


class NStack{

public:

    int *arr;
    int *next;
    int *top;
    int freeSpot;

    // Initialize your data structure.
    NStack(int N, int S){           // N = # of stack, S = size of array
        
        arr = new int[S];
        next = new int[S];
        top = new int[N];

        // intialize top with top = -1
        for (int i = 0; i < N; i++){
            top[i] = -1;
        }

        // intialize next with next index of arr
        for (int i = 0; i < S-1; i++){
            next[i] = i+1;
        }
        // initialize the last index of next
        next[S-1] = -1;

        // intialize the freeSpot
        freeSpot = 0;     
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m){
       
        // check array / stack is overflow or not
        if(freeSpot == -1){
            return false;
        }

        // Step 1: find index to insert element in the array
            int index = freeSpot;

        // Step 2: update freeSpot
            freeSpot = next[index];

        // Step 3: insert in array
            arr[index] = x;

        // Step 4: update next
            next[index] = top[ m - 1 ];

        // Step 5: update top
            top[m-1] = index;


        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m){

        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }

        // simply reverse the step of push operation
        int index = top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freeSpot;
        
        freeSpot = index;
        
        return arr[index];
    }
};


int main(){

    NStack st(3, 6);    // 3 is # stack and 6 is size of array
    
    st.push(10, 1); // Push element ‘10’ into the 1st stack. This returns true.
    st.push(20, 1); // Push element ‘20’ into the 1st stack. This returns true.
    st.push(30, 2); // Push element ‘30’ into the 2nd stack. This returns true.

    cout << "Pop from the first stack: " << st.pop(1) << endl; // Pop the top element from the 1st stack. This returns 20.
    cout << "Pop from the second stack: " << st.pop(2) << endl; // Pop the top element from the 2nd stack. This returns 30.
    
    return 0;
}
