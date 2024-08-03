#include <bits/stdc++.h>
using namespace std;

/*
    841. Keys and Rooms
    https://leetcode.com/problems/keys-and-rooms */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


/* 547. Number of Provinces
   https://leetcode.com/problems/number-of-provinces */


class GraphBFS {
public:

    /* Approach II: Using BFS */
    void BFS(vector<vector<int>>& rooms, int source, vector<bool>& visited){
        visited[source] = true;

        queue<int> q;

        // Start BFS from room 0
        visited[source] = true;
        q.push(source);

        while (!q.empty()) {
            int v = q.front();      // v represent the node that we can visit from node rooms (u).
            q.pop();

            for (int &node : rooms[v]) {
                if (!visited[node]) {
                    visited[node] = true;
                    q.push(node);
                }
            }
        }
    }

    bool canVisitAllRoomsBFS(vector<vector<int>>& rooms) {
        int size = rooms.size();

        vector<bool> visited(size, false);

        BFS(rooms, 0, visited);

        for(bool node: visited){
            if(node == false){
                return false;
            }
        }
    }
};


class Graph {
public:

    /* Approach I: Using DFS */
    void DFS(vector<vector<int>>& rooms, int source, vector<bool>& visited){
        visited[source] = true;

        for(int &node: rooms[source]){
            if(!visited[node]){
                DFS(rooms, node, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();

        vector<bool> visited(size, false);

        DFS(rooms, 0, visited);

        for(bool node: visited){
            if(node == false){
                return false;
            }
        }
        return true;
    }
};


int main() {

    
    vector<vector<int>> rooms = {{1},{2},{3},{}};
    Graph dfs;
    

    cout <<"\n#Approach I: Using DFS.\n " << endl;

    /* Approach I: Using DFS */
    if(dfs.canVisitAllRooms(rooms)){
        cout << "Approach I DFS: TRUE, We can visit all the rooms.\n";
    }
    else{
        cout << "Approach I DFS: NO, We can not visit all the rooms.\n";
    }

    /* Approach II: Using BFS */
    GraphBFS bfs;
    if(bfs.canVisitAllRoomsBFS(rooms)){
        cout << "Approach II BFS: TRUE, We can visit all the rooms.\n";
    }
    else{
        cout << "Approach II BFS: NO, We can not visit all the rooms.\n";
    }
    
    cout << endl;
    
    return 0;
}