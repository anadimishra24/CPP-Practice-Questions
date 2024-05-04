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

    vector<int> prev(size);
    prev = prevSmallerElement(height, size);

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

int maxRectangleAreaInBinaryMatrix(vector<vector<int>> rectangle, int rowSize, int colSize){

    int area = largestRectangleAreaHistogram(rectangle[0], colSize);

    // update row by adding the previos row value in current row
    for (int i = 1; i < rowSize; i++){
        for (int j = 0; j < colSize; j++){
            if(rectangle[i][j] != 0){
                rectangle[i][j] = rectangle[i][j] + rectangle[i - 1][j];
            }
            else{
                rectangle[i][j] = 0;
            }
        }
        area = max(area, largestRectangleAreaHistogram(rectangle[i], colSize));
    }

    return area;   
}

int main(){


    vector<vector<int>> rectangle = { {0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0} };       // output: 10
   

    int rowSize = rectangle.size();
    
    int colSsize = rectangle[0].size();
   

    int ans = maxRectangleAreaInBinaryMatrix(rectangle, rowSize, colSsize);

    cout << "\n\nMaximum area in binary matrix is: " << ans << endl;

    

    return 0;
} 