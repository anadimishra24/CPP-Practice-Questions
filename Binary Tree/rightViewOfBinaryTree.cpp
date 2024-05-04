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


// left view of binary tree
void leftView(Node* root, vector<int>& ans, int lvl){

    // base case
    if(root == NULL){
        return;
    }

    // we entered into new level
    if(lvl == ans.size()){
        ans.push_back(root -> data);
    }

    leftView(root -> right, ans, lvl+1);
    leftView(root -> left, ans, lvl+1);
}

int main(){

    Node* root = NULL; 

    /*  Input: 1 3 -1 -1 2 -1 -1

        Let there is number line:
                   -2 -1   0     1  2  3        
                          1
                        /    \
                       3      2           
        
        Explanation: Node 1 is at <0> and Node 2 is at <-1> and Node 4 is at <-2>....
                    now we calculate its horizontal distance from root and traverse level by level from right to left and insert first node on every level i.e.
                           ___________________________________
                          | Horizontal Distace(hd) |  Node    |
                          |----------------------- |----------|
                          |          <0>           | 1        |
                          |          <-1>          | 3        |
                          |          <1>           | 2        |
                          |________________________|__________|
    
                    And we print the nodes of hd in sorted order like: <-2>, <-1>, <0>, <1>, <2>, <3>
        Output: 1 3
    */

    /* Input: 1 2 4 -1 8 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
                                   1
                                /     \
                               2        3
                              / \      / \
                             4   5     6  7
                              \
                               8   
        Output: 1 2 4 8
    */
    
    root = createBinaryTree(root);

    // print the tree in level order
    cout << "Level order traversal: \n";
    levelOrderTraversal(root);


    // left view of binary tree
    vector <int> ans;
    leftView(root, ans, 0);   // 0 is level

    cout << "Left view of Binary Tree: ";
    for(auto node : ans){
        cout << node << " ";
    }
    return 0;
}