#include <bits/stdc++.h>
#include <iostream>
using namespace std;


/* 547. Number of Provinces
   https://leetcode.com/problems/number-of-provinces */


/* There is also other way to solve this question is that directly use the given matrix instead of using another adjency list
    only change we need to do is: when we call the DFS then we need to find the neighbout first then we traversre the corresponding nodes of 'u'
    
class Solution {
public:

    int node;

    void DFS(vector<vector<int>>& isConnected, int u, vector<bool>& visited){
        // now visit/traverse corresponding nodes of 'u'
        // change: we first find the connected neighbour first
        visited[u] = true;

        for(int v = 0; v < node; v++ ){
            if(!visited[v] && isConnected[u][v] == 1){
                DFS(isConnected, v, visited);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        node = isConnected.size();
        // create a boolean vector to maintain the record of visited nodes
        vector<bool> visited(node, false);

        // count the # province
        int province = 0;
        for(int i = 0; i < node; i++){
            if(!visited[i]){
                DFS(isConnected, i, visited);
                province++;
            }
        }
        return province;
    }
};
*/

class Graph {
public:

    void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){

        visited[u] = true;

        for(auto&v: adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int node = isConnected.size();

        // create a boolean vector to maintain the record of visited nodes
        vector<bool> visited(node, false);

        // create a adjency list
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < node; i++){
            for (int j = 0; j < node; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(i);
                    adj[j].push_back(i);
                }
            }
        }

        // count the # province
        int province = 0;
        for(int i = 0; i < node; i++){
            if(!visited[i]){
                DFS(adj, i, visited);
                province++;
            }
        }
        return province;
    }
};




int main() {

    
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    Graph bfs;
    

    cout <<"\n#Approach BFS: To find the number of provinces: " << endl;

    cout << "The number of provinces are: ";
    int ans = bfs.findCircleNum(isConnected);
    
    cout << ans << endl;
    cout << endl;
    
    return 0;
}