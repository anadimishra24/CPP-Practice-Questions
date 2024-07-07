#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Step 1: Build adjacency list
        unordered_map<int, vector<int>> adjList;
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        // Step 2: Check for path using DFS
        vector<bool> visited(n, false);
        return dfs(adjList, visited, source, destination);
    }
    
    bool dfs(unordered_map<int, vector<int>>& adjList, vector<bool>& visited, int current, int destination) {
        if (current == destination) {
            return true;
        }
        
        visited[current] = true;
        
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                if (dfs(adjList, visited, neighbor, destination)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    int n = 10;
    vector<vector<int>> edges = {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}};
    int source = 5;
    int destination = 9;
    
    bool isValidPath = sol.validPath(n, edges, source, destination);
    cout << (isValidPath ? "true" : "false");

    return 0;
}
