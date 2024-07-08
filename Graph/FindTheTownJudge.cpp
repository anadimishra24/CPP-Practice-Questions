/*  997. Find the Town Judge
    https://leetcode.com/problems/find-the-town-judge  */


#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:

    /* solution I: by using the one vector that maintain the both ongoing and incomming degree */
    int findJudge(int n, vector<vector<int>>& trust) {

        // count total degree if incoming degree[edge] to any node do degree++ if outgoing degree then do degree--
        vector<int> countDegree(n + 1, 0); // Degree array for n nodes (1-indexed)

        // Calculate degrees
        for (auto& edge : trust) {
            int u = edge[0];
            int v = edge[1];
            countDegree[u]--;  // outgoing degree from u to v [u -> v]
            countDegree[v]++;  // incoming degree from v to u [u -> v]
            
        }

        // Find the node with incomming degree n-1(everyone trust him) and outging degree 0 (he not trust anyone)
        for (int i = 1; i <= n; ++i) {
            if (countDegree[i] == n-1) {
                return i;
            }
        }

        return -1;
    }
    
    /* solution II: by using the two vector that maintain ongoing degree and incomming degree separately */
    int findJudgeUsingTwoVector(int n, vector<vector<int>>& trust) {

        // count total degree if incoming degree[edge] to any node do degree++ if outgoing degree then do degree--
        vector<int> incommingDegree(n + 1, 0);
        vector<int> outgoingDegree(n + 1, 0);

        // Calculate degrees
        for (auto& edge : trust) {
            int u = edge[0];
            int v = edge[1];
            outgoingDegree[u]++;  // outgoing degree from u to v [u -> v]
            incommingDegree[v]++;  // incoming degree from v to u [u -> v]
            
        }

        // Find the node with incomming degree n-1(everyone trust him) and outging degree 0 (he not trust anyone)
        for (int i = 1; i <= n; ++i) {
            if (outgoingDegree[i] == 0 && incommingDegree[i] == n-1) {
                return i;
            }
        }

        return -1;
    }
};;

int main() {

    /* Samples input and output:
    Example 1:
    Input: n = 2, trust =  {{1,2}}
    Output: 2

    Example 2:
    Input: n = 3, trust = {{1,3},{2,3}}
    Output: 3

    Example 3:
    Input: n = 3, trust = {{1,3},{2,3},{3,1}}
    Output: -1
    */
    int n = 3;
    vector<vector<int>> trust = {{1,3},{2,3},{3,1}};
    Solution sol;

    /* by count total degree if incoming degree[edge] to any node do degree++ if outgoing degree then do degree--*/
    int judge = sol.findJudge(n,trust);
    cout << "The town judge: " << judge << endl;

    /* by countng the degree incomming and outgoing of all node is */
    int judge2 = sol.findJudgeUsingTwoVector(n,trust);
    cout << "The town judge: " << judge2 << endl;

    return 0;
}
