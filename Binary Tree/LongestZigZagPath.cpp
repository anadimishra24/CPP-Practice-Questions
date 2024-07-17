#include <bits/stdc++.h>
using namespace std;

/*
    1372. Longest ZigZag Path in a Binary Tree
    https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
*/

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

// Approach I: check from which path i am coming and goto its opposite path and incremement the path
int maxPathLen = 0; // Globa; variable
// calculate the longest path 
void longestPath(Node* root, int pathLen, bool goLeft){

    if(root == NULL){
        return;
    }

    maxPathLen = max(maxPathLen,pathLen);  // update the max path of zigzag

    if(goLeft){ // come from right now need to left
        longestPath(root->left, pathLen+1, false); // come from left so go right now, for that we pass goLeft -> false
        longestPath(root->right, 1, true); // goto right and explore new path also, so we set the pathLen = 1 
    }
    else{ // come from left now need to right
        longestPath(root->right, pathLen+1, true); // come from right so go left now, for that we pass goLeft -> true
        longestPath(root->left, 1, false); // goto right and explore new path also, so we set the pathLen = 1 
    }

}

// longest zig zag path of binary tree
int longestZigZag(Node* root){
    int pathLen = 0;
    longestPath(root, pathLen, false); // start from right
    longestPath(root, pathLen, true); // start from left

    return maxPathLen;
}


// Approach II: We maintain the count of left and right on every iteration
int maxPathLen2 = 0; // Globa; variable
// calculate the longest path 
void longestPath2(Node* root, int left, int right){

    if(root == NULL){
        return;
    }

    maxPathLen2 = max({maxPathLen2,left, right});  // update the max path of zigzag

    longestPath2(root -> left, right+1, 0); // left and right in beginning is 0 and 0
    longestPath2(root -> right, 0, left+1); // left and right in beginning is 0 and 0

}

// longest zig zag path of binary tree
int longestZigZag2(Node* root){
  
    longestPath2(root, 0, 0); // left and right in beginning is 0 and 0

    return maxPathLen2;
}


int main(){

    Node* root = NULL;

    /*  Input: [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]          
                     
                             1
                              \
                                1   
                              /  \
                             1    1
                                 / \
                                1   1
                                 \ 
                                  1
                                  \
                                   1

        
       */
    
    root = createBinaryTree(root);

    // print the tree in level order
    cout << "Level order traversal: \n";
    levelOrderTraversal(root);

    // Approach I: longest zig zag path
    int ans = longestZigZag(root);

    cout << "Approach I: Longest Zig Zag Path of Binary Tree: " << ans << endl;


    // Approach II: longest zig zag path
    int ans2 = longestZigZag2(root);

    cout << "Approach II: Longest Zig Zag Path of Binary Tree: " << ans2 << endl;
    
    return 0;
}