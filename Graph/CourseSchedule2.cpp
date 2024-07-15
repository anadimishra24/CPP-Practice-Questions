/*  210. Course Schedule II
    https://leetcode.com/problems/course-schedule-ii */


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Approach-1 (Using BFS Cycle Check - Kahn's Algorithm (Topological Sort)
class Solution {
public:
    vector<int> topologicalSort(int numCourses, unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
        queue<int> que;

        int count = 0;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }

        vector<int> topoOrder;

        while (!que.empty()) {
            int u = que.front();
            topoOrder.push_back(u);
            que.pop();

            for (int& v : adj[u]) {

                indegree[v]--;

                if (indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
            }
        }

        // only return topological order when all courses are taken otherwise return empty topological order
        if (count == numCourses) {
            return topoOrder; // Return topological order
        } else {
            return {}; // Return empty vector indicating cycle or incomplete sort
        }   
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0); // kahn's algo

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // b ---> a
            adj[b].push_back(a);

            // arrow ja raha hai 'a' me
            indegree[a]++;
        }
        // if cycle is present, not possible otherwise return the course selection in topological order
        return topologicalSort(numCourses, adj, indegree);
    }
};


//Approach-2 Using DFS Cycle Check (Topological Sort)
class SolutionDFS {
public:

    bool isCycle;
    void topologicalSortDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion,stack<int>& st) {
       
       // marked the visited true of node 'u'
       visited[u] = true;
       inRecursion[u] = true;

       for(auto& v: adj[u]){
            if(inRecursion[v] == true){
                isCycle = true;
                return;
            }

            if(!visited[v]){
                topologicalSortDFS(adj, v, visited, inRecursion,st);
            }
       }
        st.push(u);
        inRecursion[u] = false;
    }

    vector<int> findOrderDFS(int numCourses, vector<vector<int>>& prerequisites) {
        
        // adjancey list
        unordered_map<int, vector<int>> adj;
        // maintain the record of current node traverse, because we need to modify the node traversal from traversed to new node for next set of node and its corresponding node
        vector<bool> inRecursion(numCourses, false);
        // records of visited nodes
        vector<bool> visited(numCourses, false); 

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // b ---> a
            adj[b].push_back(a);
        }

        // stack for maintaing the topological order of node
        stack<int> st;

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                // if cycle is present, not possible otherwise return the course selection in topological order
                topologicalSortDFS(adj, i, visited, inRecursion,st);
            }
        }

        if(isCycle){
            return {};
        }

        // if cycle is not present then, return the course order
        vector<int> topoSort;
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            topoSort.push_back(curr);
        }

        return topoSort;
    }
};


int main() {

    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};  // Output: {0,2,1,3}    // {{1,0}}; // numCourses = 2;  Output: {0,1}
    Solution sol;
    
    // if we get the cycle in topologicalSortCheck then it will return empty vector otherwise return topological order of subjects
    cout <<"\n#Approach I: Topological Sort using BFS to check that courses completion: ";
    vector<int> subOrder = sol.findOrder(numCourses,prerequisites);

    cout << "\nThe course completion order[BFS]: ";
    
    for(auto& course: subOrder){
        cout << course << " ";
    }

    // if we get the cycle in topologicalSortCheck then it will return empty vector otherwise return topological order of subjects
    SolutionDFS dfs;
  
    cout <<"\n#Approach II: Topological Sort using DFS to check that courses completion: ";
    vector<int> couseOrder = dfs.findOrderDFS(numCourses,prerequisites);

    cout << "\nThe course completion order[DFS]: ";
    
    for(auto& course: couseOrder){
        cout << course << " ";
    }
    
    return 0;
}
