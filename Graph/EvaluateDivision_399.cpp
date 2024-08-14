#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* Ques: https://leetcode.com/problems/evaluate-division  */

class Evaluate{
public:

    void DFS(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dst, unordered_set<string>& visited, double product, double &ans) {
        if(visited.find(src) != visited.end())
            return;
        
        visited.insert(src);
        if(src == dst) {
            ans = product;
            return;
        }
        
        for(auto p : adj[src]) {
            
            string v   = p.first;
            double val = p.second;
            
            DFS(adj, v, dst, visited, product*val, ans);
                
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int size = equations.size();
        
        unordered_map<string, vector<pair<string,double>>> adj;

        for(int i = 0; i < size; i++){
            string u = equations[i][0];
            string v = equations[i][1];

            double value = values[i];

            adj[u].push_back({v, value}); // For eq: a/c
            adj[v].push_back({u, 1.0/value});  // For eq: c/a
        }

        vector<double> result;

        for(auto &query: queries){
            string src = query[0];
            string dst = query[1];
            
            double ans     = -1.0;
            double product = 1.0;
            
            if(adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                
                DFS(adj, src, dst, visited, product, ans);
            }
            result.push_back(ans);
        }
        return result;
    }
};

int main(){


    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    Evaluate ev;

    vector<double> result = ev.calcEquation(equations, values, queries);

    cout << "Result after evaluation the equation: " ;
    for(double &r: result){
        cout << r << " ";
    }

    return 0;
}
