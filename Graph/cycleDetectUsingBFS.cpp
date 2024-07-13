/* Detect the cycle in directed graph using BFS [Kanh's Algorithm]*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph{

public:

    /* We use kanh's algo to detect the cycle in directed graph just use a count variable in it, 
    if count is equal to #nodes means all nodes visited, if count is less than # nodes then it have a cycle in it*/
    
    bool isCyclePresentKanhs(int node,vector<vector<int>> edges){

        // count to maintian the record of visited node
        int count = 0;

        // Step 1: Create a vector that maintain the record of indegree of nodes.
        vector<int> inDegree(node,0);

        for(auto& n: edges){
            int u = n[0];
            int v = n[1];

            inDegree[v]++;
        }

        // Step 2: Now, pick the node that have 0 indegree put it into the queue
        queue<int> que;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                que.push(i);
                count++;
            }
        }

        /*Note: Either we increase the count everytime when we push the node in queue or we increase the count only once when we pop the node from queue, both works same way*/
        // Step 3: Pick the node from queue and start traversing its corresponding nodes.Increase the count value when reach to the new node.
        while(!que.empty()){
            int n = que.front();
            que.pop();
            //count++;   // second option

            for(auto& v: edges[n]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    que.push(v);
                    count++;
                }
            }

        }
        
        return count != node;
        // return (count == node) ? false : true;
        /* same condition is written above in one line using ternery operatior
        if(count == node){
            return true;
        }
        else{
            return false;
        }
        */
    }


};

int main() {

    int nodes = 2;
    vector<vector<int>> edges =  {{0, 1}, {1, 0}}; // output: YES, cycle is present  // nodes = 6; {{0, 3}, {0, 2}, {1, 4}, {2, 3}, {2, 1}, {3, 1}, {5, 4}}; // output: No, cycle is not present
    Graph bfs;
    

    cout <<"\n#Approach: Kanh's Algorithm [BFS] to detect the cycle in graph: ";
    
    if(bfs.isCyclePresentKanhs(nodes,edges)){
        cout << "YES, graph have a cycle.\n" << endl;
    }
    else{
        cout << "NO, graph doesn't have a cycle.\n" << endl;
    }

    cout << endl;
    
    return 0;
}
