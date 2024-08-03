#include <bits/stdc++.h>
using namespace std;



/* 1466. Reorder Routes to Make All Paths Lead to the City Zero
   https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero */


    /* Approach II: Using BFS */


class Graph {
public:

    /* Approach I: Using DFS */
   int routeChange = 0;

    void DFS(int u, int parent, unordered_map<int, vector<pair<int,int>>>& adj){

        for(auto& pairs: adj[u]){

            int v = pairs.first;
            int realOrFake = pairs.second;

            if(v != parent){
                if(realOrFake == 1){
                    routeChange++;
                }
                DFS(v,u, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int,int>>>adj;
      
        // create adjecny list
        for(auto& edge: connections){
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back({b,1}); // 1 means real edge
            adj[b].push_back({a,0}); // 0 means edge draw by ourself
        }

        // call the DFS
        DFS(0, -1, adj);    // 0 -> starting point | -1 -> parent of starting node

        return routeChange;
    }
};


int main() {

    
    vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    int n = 6;

    Graph dfs;
    

    cout <<"\n#Approach I: Using DFS.\n " << endl;

    /* Approach I: Using DFS */
    int routes = dfs.minReorder(n, connections);

    cout << "Reorder routes to reach the city 0 is: " << routes << endl;

    
    
    return 0;
}