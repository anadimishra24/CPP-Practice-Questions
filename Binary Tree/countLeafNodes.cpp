#include<bits/stdc++.h>
using namespace std;


// creating node of tree
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


// creating a tree
Node* createBinaryTree(Node* root){

    cout << "Enter the data: " ;
    int data;
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

// count number of leaves noe in tree (here we use inorder traversal and count the node if it have no left and right nodes)
int countLeafNodes(Node* root, int &count){

    // base case
    if(root == NULL){
        return -1;
    }

    countLeafNodes(root -> left, count);

    if(root->left == NULL && root->right == NULL){
        count++;
    }

    countLeafNodes(root-> right, count);

    return count;
}

int main(){

    // Input tree: 1 2 3 -1 -1 -1 4 -1 -1   || Output: 2
    // Input tree: 1 2 -1 3 4 5 6 7 8 -1 - 1 -1 -1 -1 -1 -1 -1  || Output: 4   

    Node* root = NULL;

    // Input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = createBinaryTree(root);
    levelOrderTraversal(root);

    // function to count number of leaf nodes
    int count = 0;
    int ans = countLeafNodes(root, count);
    cout << "The number of leaf nodes in tree is: " << ans << endl;

    return 0;
}