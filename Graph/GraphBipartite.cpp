#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
    bool colouredDFS(unordered_map<int, vector<int>>& adj, int u, vector<int>& isColoured, int currColour){
        isColoured[u] = currColour; // 1 -> red, 0 -> blue

        for(auto& v: adj[u]){
            if(isColoured[v] == currColour){
                return false; // Found adjacent node with same color
            }
            if(isColoured[v] == -1){ // Not colored
                // Color the adjacent node with opposite color
                int nextColour = 1 - currColour;
                if(!colouredDFS(adj, v, isColoured, nextColour)){
                    return false;
                }
            }
        }
        return true; // All adjacent nodes are colored properly
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> adj;

        // Build adjacency list
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < graph[i].size(); ++j){
                int u = i;
                int v = graph[i][j];
                adj[u].push_back(v);
                adj[v].push_back(u); // Since graph is undirected
            }
        }

        vector<int> isColoured(n, -1); // -1 indicates not colored
        
        // Try to color each component of the graph
        for(int i = 0; i < n; ++i){
            if(isColoured[i] == -1){ // Node i is not colored
                if(!colouredDFS(adj, i, isColoured, 1)){
                    return false; // Found a component that is not bipartite
                }
            }
        }

        return true; // All components are bipartite
    }
};


class SolutionBFS {
public:
   bool colouredBFS(vector<vector<int>>& graph, int u, vector<int>& isColoured,
                     int currColour) {
        queue<int> que;
        que.push(u);
        isColoured[u] = currColour;

        while (!que.empty()) {
            int curr = que.front();
            que.pop();

            for (int v : graph[curr]) {
                if (isColoured[v] == isColoured[curr]) {
                    return false; // Found adjacent nodes with the same color
                }
                if (isColoured[v] == -1) {
                    isColoured[v] = 1 - isColoured[curr]; // Assign opposite color
                    que.push(v);
                }
            }
        }
        return true; // All adjacent nodes are colored properly
    }
    
    bool isBipartiteBFS(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> isColoured(n, -1); // -1 indicates not colored

        // Try to color each component of the graph
        for (int i = 0; i < n; ++i) {
            if (isColoured[i] == -1) { // Node i is not colored
                if (!colouredBFS(graph, i, isColoured, 0)) { // Start coloring with 0
                    return false; // Found a component that is not bipartite
                }
            }
        }

        return true; // All components are bipartite
    }
};


// graph = [[1,2,3],[0,2],[0,1,3],[0,2]]

int main(){
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}}; // true       // {{1,2,3},{0,2},{0,1,3},{0,2}};  // false
    Solution dfs;
    
    if(dfs.isBipartite(graph)){
        cout << "Yes! The graph is Bipartite" << endl;
    }else{
        cout << "No! The graph is not Bipartite" << endl;
    }

    SolutionBFS bfs;
    
    if(bfs.isBipartiteBFS(graph)){
        cout << "Yes! The graph is Bipartite" << endl;
    }else{
        cout << "No! The graph is not Bipartite" << endl;
    }
    
    
    return 0;
}
