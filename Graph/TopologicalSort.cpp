/* 
# Topological Sort: 
Topological sorting is a special ordering of vertices in a directed acyclic graph (DAG). 
It's a linear ordering of vertices such that for every directed edge 𝑢 → 𝑣, vertex 𝑢 comes before vertex 𝑣
in the ordering. In simpler terms, it arranges the vertices in a way that all dependencies are respected; 
if there's an edge from vertex A to vertex B, then A comes before B in the ordering.

# Topological Sort Order:
Topological sorting provides an order of vertices such that for every directed edge 
𝑢 → 𝑣, vertex 𝑢 appears before 𝑣 in the order.


# Algorithm for Topological Sorting
The algorithm typically used for topological sorting is based on Depth-First Search (DFS):

#DFS-based Approach:
Use DFS to traverse the graph.
Keep track of vertices after visiting all neighbors (recursively), which will give the topological order.

#Kahn's Algorithm:
Use an iterative approach involving a queue and indegree counts to achieve topological sorting.
Initialize indegree counts for all vertices, then iteratively remove vertices with zero indegree (starting with those that have no incoming edges).
*/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Approach-1 Topological Sort using DFS
class Graph {
public:
    void DFS(vector<vector<int>>& edges, int u, vector<bool>& visited, stack<int>& st){

        visited[u] = true;

        for(int& v: edges[u]){
            if(!visited[v]){
                DFS(edges, v, visited, st);
            }
        }
        st.push(u);
    }

    // get the nodes in topological order
    vector<int> topologicalSort(int node, vector<vector<int>>& edges) {

        vector<bool> visited(node+1, false);
        stack<int> st;

        for(int i = 0; i < node; i++){
            if(!visited[i]){
                DFS(edges, i, visited, st);
            }
        }

        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            //cout << "-> " << st.top();
            st.pop();
        }

        return ans;      
    }
};


int main() {

    int nodes = 5;
    vector<vector<int>> edges = {{0,3},{0,2},{1,4},{2,3},{2,1},{3,1},{5,4}}; // output: 0 3 2 4 1  // {{4,3},{4,0},{3,1},{3,2},{0,1},{1,2}};  // output: 0 3 2 4 1
    Graph dfs;
    

    cout <<"\n#Approach: Topological Sort of nodes using DFS: ";
    vector<int> result = dfs.topologicalSort(nodes,edges);
    
    for(auto& n: result){
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}
