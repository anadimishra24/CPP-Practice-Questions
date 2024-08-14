#include <bits/stdc++.h>
#include <iostream>
using namespace std;


/*  Ques: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze */


class Maze{
public:

    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance){

        int row = maze.size();
        int col = maze[0].size();

        queue<pair<int,int>> que;

        que.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+'; //marking it visited '+'
        
        // hold the steps count that we travel to reach the exit door
        int steps = 0;
        
        while(!que.empty()){
            int qSize = que.size();
            while(qSize--){
                pair<int, int> curr = que.front();
                que.pop();

                /* Check is current is itself is a exit, it should be a border of maxe i.e row = 0 || row = row-1 and  
                    col = 0 | col = col-1 and it should be in the range of maze[] and not equal to entrence[] */

                if(curr != make_pair(entrance[0], entrance[1]) &&
                    (curr.first == 0 || curr.first == row-1 && curr.second == 0 || curr.second == col-1)){
                    return steps;
                }

                //  check the corresponding of curr 
                for(auto &dir: directions){
                    int new_row = curr.first + dir[0];
                    int new_col = curr.second + dir[1];

                    if(new_row >= 0 && new_row < row && new_col >= 0 && new_col < col && maze[new_row][new_col] != '+') {
                        que.push({new_row, new_col});
                        maze[new_row][new_col] = '+'; //marking it as visited
                    }
                }
            }
            
            steps++;
        }

        // if it reaches to it state it means there is no way to come out from the maze 
        return -1;
    }
};


int main(){

    Maze mz;

    vector<vector<char>> maze ={{'.','+'}};   // {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    vector<int> entrance = {0,0};  // {1,2};

    int path = mz.nearestExit(maze, entrance);

    cout << "Nearest Exit from the maze: " << path << endl;

    
    return 0;
}
