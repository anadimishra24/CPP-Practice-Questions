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

//Approach-1 (Using BFS Cycle Check - Kahn's Algorithm (Topological Sort)
class Graph {
public:
    // get the nodes in topological order
    vector<int> kanhsAlgo(int node, vector<vector<int>>& edges) {

        // Step 1: Initialize inDegree with size 'node' and all values set to 0
        vector<int> inDegree(node, 0);
        
        // maintain the inDegree of nodes, the node have 0 inDegree we can first pick that node and traverse its corresponding nodes
        for(auto& n: edges){
            int u = n[0];
            int v = n[1];

            inDegree[v]++;
        }
        
        // create a queue to maintain the topological order
        queue<int> que;

        // Step 2: check the node which have indegree 0
        for(int i = 0; i < node; i++){
            if(inDegree[i] == 0){
                que.push(i);
            }
        }

        vector<int> topologicalOrder;
        // Step 3: once get the first node which have indegree 0[must have that node because kahn's algo applicable on DAG], now traverse its corresponding nodes
        while(!que.empty()){
            int n = que.front();
            que.pop();
            topologicalOrder.push_back(n); // first node is added in topological oder 

            // now traverse its corresponding nodes and decrease its indegree count
            for(auto& v: edges[n]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    que.push(v);
                }
            }
        }
        return topologicalOrder;      
    }
};


int main() {

    int nodes = 6;
    vector<vector<int>> edges = {{0, 3}, {0, 2}, {1, 4}, {2, 3}, {2, 1}, {3, 1}, {5, 4}}; // output: 0 5 3 2 1   // {{4,3},{4,0},{3,1},{3,2},{0,1},{1,2}};  // output: 0 3 2 4 1
    Graph bfs;
    

    cout <<"\n#Approach: Topological Sort of nodes using kanh's Algorithm [BFS]: ";
    vector<int> result = bfs.kanhsAlgo(nodes,edges);
    
    for(auto& n: result){
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}
