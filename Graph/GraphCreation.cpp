#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph{
public:
    unordered_map<int,list<int>> adjacent;

    /* u --> v || v --> u */
    /* add extra parametre for decide that graph is directed or undirecte,isDirected = 0 -> undirected and isDirected = 1 -> directed */
    void insertEdge(int u, int v, bool isDirected){
        // create an edge from u -> v [u to v]
        adjacent[u].push_back(v);
        // if the graph is undirected than the direction should also be v -> u [v to u]
        if(!isDirected){
            adjacent[v].push_back(u);
        }
    }

    // Function to print adjacency list representation of the graph
     void printAdjacencyList() {
        for (auto& pair : adjacent) {
            cout << pair.first << " -> ";     // print node 
            for (int neighbor : pair.second) {
                cout << neighbor << ", ";      // print all the adjacent connecting nodes j from node i
            }
            cout << endl;
        }
    }

};



int main(){

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;
    
    // initialize graph member
    Graph g1;

    cout << "Enter the edges (u v):" << endl;
    for(int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        // creating an undirected graph
        g1.insertEdge(u,v,0);
    }

    // print the adjancy list of graph
    cout << "\nAdjacency List:\n";
    g1.printAdjacencyList();

    return 0;
}
