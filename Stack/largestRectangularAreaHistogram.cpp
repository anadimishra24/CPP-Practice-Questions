#include <bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans; 
}

int largestRectangleAreaHistogram(vector<int> &height, int size){
    vector<int> next(size);
    next = nextSmallerElement(height, size);
    cout << " next = " ;
    for (auto count: next){
        cout << count << " ";
    }

cout << "\n_________________________" <<endl;
    vector<int> prev(size);
    prev = prevSmallerElement(height, size);
cout << "prev = " ;
for (auto count: prev){
        cout << count << " ";
    }
    int area = INT_MIN;
    for(int i=0; i<size; i++) {
        int l = height[i];
        
        if(next[i] == -1) {
            next[i] = size;
        }
        
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

    

int main(){


    vector<int> heights = {2, 1, 5, 6, 2, 3};       // output: 10
   

    int size = heights.size();

    int ans =  largestRectangleAreaHistogram(heights, size);

    cout << "\n\nLargest Rectangular Area In Histogram is: " << ans << endl;

    

    return 0;
} 