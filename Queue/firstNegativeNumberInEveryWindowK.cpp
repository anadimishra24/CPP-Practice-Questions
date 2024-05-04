#include <bits/stdc++.h>
using namespace std;


vector<int> firstNegativeNumberInEveryWindowK(vector<int> arr, int k){

    queue<int> que;

    vector<int> ans;

    int negative = -1;

    //process first window
    for(int i=0; i<k; i++) {
        if(arr[i] < 0) {
            que.push(i);
        }
    }

    //push ans for FIRST window
    if(que.size() > 0) {
        ans.push_back(arr[que.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    //now process for remaining windows
    for(int i = k; i<5; i++) {
        
        //first pop out of window element      
        if(!que.empty() && (i - que.front())>=k ) {
            que.pop();
        }
        
        //then push current element
        if(arr[i] < 0)
        que.push(i);
        
    // put in ans
    if(que.size() > 0) {
            ans.push_back(arr[que.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    }
    return ans;
}

int main(){

    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;

    vector<int> ans = firstNegativeNumberInEveryWindowK(arr, k);

    cout << "First negative number in every window k is: ";
    for (auto it : ans){
        cout << it << " ";
    } 
        cout << endl;
    
    
    return 0;
}




/*
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
         deque<long long int> que;
         vector<long long> ans;
         int negative = -1;
         
         //process first window
         for(int i=0; i<K; i++) {
             if(A[i] < 0) {
                 que.push_back(i);
             }
         }
         
         //push ans for FIRST window
         if(que.size() > 0) {
             ans.push_back(A[que.front()]);
         }
         else
         {
             ans.push_back(0);
         }
         
         //now process for remaining windows
         for(int i = K; i<N; i++) {
             //first pop out of window element
             
             
             if(!que.empty() && (i - que.front())>=K ) {
                 que.pop_front();
             }
             
             //then push current element
             if(A[i] < 0)
                que.push_back(i);
             
            // put in ans
            if(que.size() > 0) {
                 ans.push_back(A[que.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
 }
 */