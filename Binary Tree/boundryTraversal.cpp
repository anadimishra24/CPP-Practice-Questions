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

// traverse the left sub tree and store the boundry data
void traverseLeftSubTree(Node* root, vector<int>& ans){

    // base case
    if(root == NULL){
        return;
    }

    // exclude the leaf node
    if(root -> left == NULL && root -> right == NULL){
        return;
    }

    ans.push_back(root -> data);

    if(root -> left){
        traverseLeftSubTree(root -> left, ans);
    }
    else{
        traverseLeftSubTree(root -> right, ans);
    }
}

// traverse all the leaf node and store the boundry data
void travereAllLeafNode(Node* root,  vector<int>& ans){

    // base case
    if(root == NULL){
        return;
    }
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(root -> data);
        return;
    }

    // recursive call for left
    travereAllLeafNode(root -> left, ans);

    // recursive call for right
    travereAllLeafNode(root -> right, ans);
    
}

// traverse the right sub tree and store the boundry data
void traverseRightSubTree(Node* root, vector<int>& ans){
    
    // base case
    if(root == NULL){
        return;
    }

    // exclude the leaf node
    if(root -> left == NULL && root -> right == NULL){
        return;
    }

    //ans.push_back(root -> data);

    if(root -> right){
        traverseRightSubTree(root -> right, ans);
    }
    else{
        traverseLeftSubTree(root -> left, ans);
    }
    ans.push_back(root -> data);
}

// boundry order traversal of binary tree
vector<int> boundryTraversal(Node* root){

    vector<int> ans;

    // base case
    if(root == NULL){
        return ans;
    }

    ans.push_back(root -> data);

    // Step 1: traverse the left part of tree and exclude the leaf node
    traverseLeftSubTree(root -> left, ans);

    // Step 2: traverse all the leaf node
    travereAllLeafNode(root -> left, ans);
    travereAllLeafNode(root -> right, ans);

    // Step 3: traverse the right part of tree and exclude the leaf node
    traverseRightSubTree(root-> right, ans);

    return ans;

}

int main(){

    Node* root = NULL;

    /*  Input: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1           
                               1 
                            /     \
                           2       3  
                          / \     / \ 
                         4   5   6   7
                            / \
                           8   9
   
        Output: 1 2 4 8 9 6 7 3
    */

    /* Input: 1 2 4 6 -1 -1 5 -1 -1 9 -1 3 7 -1 -1 8 -1 -1 -1
                                1
                              /
                            2
                           /  \
                          4    9
                        /  \    \
                       6    5    3
                                /  \
                               7    8

        Output: 1 2 4 6 5 7 8 
    */
    
    root = createBinaryTree(root);

    // print the tree in level order
    cout << "Level order traversal: \n";
    levelOrderTraversal(root);

    // boundry order traversal of binary tree
    vector <int> ans = boundryTraversal(root);

    cout << "Boundry Order traversal of Binary Tree: ";
    for(auto node : ans){
        cout << node << " ";
    }
    return 0;
}