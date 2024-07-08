/*  207. Course Schedule
    https://leetcode.com/problems/course-schedule */


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Approach-1 (Using BFS Cycle Check - Kahn's Algorithm (Topological Sort)
class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>>& adj, int n,
                              vector<int>& indegree) {
        queue<int> que;

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int& v : adj[u]) {

                indegree[v]--;

                if (indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
            }
        }

        if (count == n)  // I was able to visit all nodes (course)
            return true; // i.e. I was able to finish all courses

        return false; // means there was a cycle and I couldn't complete all courses
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

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

        // if cycle is present, not possible
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};

//Approach-2 (Using DFS Cycle Check)
class SolutionDFS {
public:
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return false;
        }
        
        return true;
    }
};
int main() {

    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    Solution sol;
    SolutionDFS dfs;

    // if we get the cycle in topologicalSortCheck then it will return false
    cout <<"\n#Approach I: Using Topological Sort to check the cycle.";
    if(sol.canFinish(numCourses,prerequisites)){
        cout << "\nYes, I can finish all the courses." << endl;
    }
    else{
        cout << "\nNo, I cannot finish all the courses." << endl;
    }
    
    // if we get the cycle in DFS then it will return false
    cout <<"\n#Approach II: Using DFS to check the cycle.";
    if(dfs.canFinish(numCourses,prerequisites)){
        cout << "\nYes, I can finish all the courses." << endl;
    }
    else{
        cout << "\nNo, I cannot finish all the courses." << endl;
    }
    
    return 0;
}
