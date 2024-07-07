#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    void DFSallPath(vector<vector<int>>& graph, int source, int destination,vector<int> path,vector<vector<int>>& result){

        path.push_back(source);

        // if we reach to our path
        if(source == destination){
            result.push_back(path);
        }
        else{
            // traverse the other path
            for(int &v: graph[source]){
                DFSallPath(graph, v, destination, path, result);
            }
        }
        path.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        int source = 0;
        int destination = n-1;

        vector<int> path;
        vector<vector<int>> result;

        DFSallPath(graph, source, destination, path, result);

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};    // Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
    vector<vector<int>> paths = sol.allPathsSourceTarget(graph);

    // Print all paths found
    cout << "\nAll path from source to destinantion: ";
    cout <<"{ ";
    for (auto& path : paths) {
        cout << "{";
        for (int node : path) {
            cout << node << " ";
        }
        cout <<"}, ";
        //cout << endl;
    }
    cout <<" }";
    return 0;
}
