/* 1791. Find Center of Star Graph 
    https://leetcode.com/problems/find-center-of-star-graph  */


#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:

    // solution I: by using the counting of degree of all node
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // Since nodes are labeled from 1 to n

        vector<int> degree(n + 1, 0); // Degree array for n nodes (1-indexed)

        // Calculate degrees
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
        }

        // Find the node with degree n-1
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }

    // solution II : by using the adjency list
     int findCenterWithAdjencyList(vector<vector<int>>& edges) {
        // Step 1: Build adjacency list and calculate degrees
        unordered_map<int, vector<int>> adjList;
        int n = edges.size() + 1; // Total number of nodes (assuming nodes are labeled from 1 to n)

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // Step 2: Find the node with degree n-1 (center of the star graph)
        for (auto& pair : adjList) {
            if (pair.second.size() == n - 1) {
                return pair.first;
            }
        }

        return -1; // In case no center found (should not happen for a valid star graph)
    }
};

int main() {
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    Solution sol;
    int center = sol.findCenter(edges);
    cout << "The centre node of the graph by countng the degree of each node is: " << center << endl;

    int adjCenter = sol.findCenterWithAdjencyList(edges);
    cout <<"\nThe cente nodee of the graph with using of adjency list is: " << adjCenter << endl;
    return 0;
}
