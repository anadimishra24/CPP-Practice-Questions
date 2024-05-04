#include <bits/stdc++.h>
using namespace std;


class Node{

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};


// create binary tree
Node* createBinaryTree(Node* root){

    int data;
    cout <<"Enter the data: ";
    cin >> data;

    // creating new Node with value 'data'
    root = new Node(data);

    // if we enter value -1 it treated as NULL
    if(data == -1){
        return NULL;
    }

    // recursive call for left and right child
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = createBinaryTree(root->left);
    
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = createBinaryTree(root->right);

    return root;

}

// print the tree in level order
void levelOrderTraversal(Node* root){

    // create queue with Node* type
    queue<Node*> que;
    
    que.push(root);
    que.push(NULL);

    while(!que.empty()){
        Node* temp = que.front();
        que.pop();

        // previous level traversal completed so change the line
        if(temp == NULL){
            cout << endl;

            // queue have still some child nodes then push NULL
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            // push left in queue
            if(temp -> left){
                que.push(temp -> left);
            }

            // push right in queue
            if(temp -> right){
                que.push(temp -> right);
            }
        }
    }
}


// vertical order traversal of binary tree
vector<int> verticalTraversal(Node* root){

    // map<hd, map<lvl, list/vector of nodes>>>
    map<int, map<int, vector<int>>> nodes;

    // queue pair<<Node, pair<hd, lvl>>>
    queue<pair<Node*, pair<int, int>>> que;
    vector<int> ans;

    // base case
    if(root == NULL){
        return ans;
    }

    que.push(make_pair(root, make_pair(0, 0)));

    while(!que.empty()){
        pair<Node* , pair<int, int>> temp = que.front();
        que.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode -> data);

        if(frontNode -> left){
            que.push(make_pair(frontNode -> left, make_pair(hd-1, lvl+1)));
        }

        if(frontNode -> right){
            que.push(make_pair(frontNode -> right, make_pair(hd+1, lvl+1)));
        }
    }

    for(auto i: nodes){
        for(auto j: i.second){
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main(){

    Node* root = NULL;

    /*  Input: 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1 

        Let there is number line:
                   -2 -1   0     1  2  3        
                           1
                        /      \
                       2         3
                     /   \     /   \
                    4     5   6     7
                               \     \
                                8     9           
        
        Explanation: Node 1 is at <0> and Node 2 is at <-1> and Node 4 is at <-2>....
                    now we calculate its horizontal distance from root i.e.
                           ___________________________________
                          | Horizontal Distace(hd) |  Node    |
                          |----------------------- |----------|
                          |          <0>           | 1, 5, 6  |
                          |          <-1>          | 2        |
                          |          <1>           | 3, 8     |
                          |          <-2>          | 4        |
                          |          <2>           | 7        |
                          |          <3>           | 9        |
                          |________________________|__________|

                    And we print the nodes of hd in sorted order like: <-2>, <-1>, <0>, <1>, <2>, <3>
        Output: 4 2 1 5 6 3 8 7 9 
    */

    /* Input: 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
                             1
                            /  \
                           2    3
                          / \    \
                         4   5    6
        
        Output: 4 2 1 5 3 6 
    */
    
    root = createBinaryTree(root);

    // print the tree in level order
    cout << "Level order traversal: \n";
    levelOrderTraversal(root);

    // vertical order traversal of binary tree
    vector <int> ans = verticalTraversal(root);

    cout << "Vertical Order traversal of Binary Tree: ";
    for(auto node : ans){
        cout << node << " ";
    }
    return 0;
}