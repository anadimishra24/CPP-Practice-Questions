#include <bits/stdc++.h>
using namespace std;


// function for check that move is valid or not
bool isPossibleMove(int newX, int newY, vector <vector<int>> maze, vector <vector<int>> visited){

    if((newX >= 0 && newX < maze.size()) && (newY >= 0 && newY < maze.size()) && visited[newX][newY] == 0 && maze[newX][newY] == 1){
        return true;
    }
    else{
        return false;
    }
    
}


void solve(vector <vector<int>> &maze, vector <vector<int>> &visited, vector <string> &ans, string path, int x, int y){

    // base case
    if(x == maze.size()-1 && y == maze.size()-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // down
    int newX = x+1;
    int newY = y;
    if(isPossibleMove(newX, newY, maze, visited)){
        path.push_back('D');
        solve(maze, visited, ans, path, newX, newY);
        path.pop_back();
    }

    // up
    newX = x-1;
    newY = y;
    if(isPossibleMove(newX, newY, maze, visited)){
        path.push_back('U');
        solve(maze, visited, ans, path, newX, newY);
        path.pop_back();
    }

    // left
    newX = x;
    newY = y-1;
    if(isPossibleMove(newX, newY, maze, visited)){
        path.push_back('L');
        solve(maze, visited, ans, path, newX, newY);
        path.pop_back();
    }

    // right
    newX = x;
    newY = y+1;
    if(isPossibleMove(newX, newY, maze, visited)){
        path.push_back('R');
        solve(maze, visited, ans, path, newX, newY);
        path.pop_back();
    }
    visited[x][y] = 0;
}

vector<string> ratInMaze(vector <vector<int>> maze){

    vector <string> ans;
    if(maze[0][0] == 0){
        return ans;
    }

    int srcX = 0, srcY = 0;
    vector <vector<int>> visited = maze;   
    
    // initialized the visited matrix with all 0's
    for (int i = 0; i < maze.size(); i++){
        for (int j = 0; j < maze.size(); j++){
            visited[i][j] = 0;
        }
    }

    string path = "";
    // recursion function for solving the maze
    solve(maze, visited, ans, path, srcX, srcY);

    //sort the answer in lexicographically order
    sort(ans.begin(), ans.end());

    return ans;  
    
}

int main(){


    vector <vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> ans = ratInMaze(maze);

    cout << "Paths for rat to pass the maze: ";
    for(auto str: ans){
        cout << str << " ";
    }

    return 0;
}
