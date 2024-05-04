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

// calculate the height of binary tree
int getHeightOfBinaryTree(Node* root){

    // base case
    if(root == NULL){
        return 0;
    }

    // get height of left side tree recursivelly
    int left = getHeightOfBinaryTree(root -> left);

    // get the height of right side tree recursivelly
    int right = getHeightOfBinaryTree(root -> right);

    // get the max from left and right and add 1 that is root node
    int ans =  max(left, right) + 1;

    return ans;
}

// function for checking the balanced tree with Time Complexity O(n)
pair<bool,int> fastBalancedTree(Node* root){

    // base case
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int, int> left = fastBalancedTree(root -> left);
    pair<int, int> right = fastBalancedTree(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}

// check tree is balanced or not
bool isBalancedBinaryTree(Node* root){

/*
    // base case
    if(root == NULL){
        return true;
    }

    bool left = isBalancedBinaryTree(root -> left);
    bool right = isBalancedBinaryTree(root -> right);

    bool differncesInHeight = abs(getHeightOfBinaryTree(root -> left) - getHeightOfBinaryTree(root -> right) <= 1);

    if(left && right && differncesInHeight){
        return true;
    }
    else{
        return false;
    }
*/

 return fastBalancedTree(root).first;
}

int main(){

    Node* root = NULL;

    /*
        Input: 1 2 -1 3 -1 -1 -1 -1
                         1
                        /
                       2
                        \
                         3 
        Output: 0 (Unbalanced); because The max difference in height
                of left subtree and right subtree is 2, which is greater than 1

        Input:  10 20 40 -1 -1 60 -1 -1 30 -1 -1 
                        10
                       /   \
                      20    30
                    /   \ 
                   40   60
        Output: 1 (Balanced); because The max difference in height
                of left subtree and right subtree is 1
    */
    
    root = createBinaryTree(root);

    // print the tree in level order
    cout << "Level order traversal: \n";
    levelOrderTraversal(root);

    // is binary tree is balanced or not
    if(isBalancedBinaryTree(root)){
        cout << "Balanced." << endl;
    }
    else{
        cout << "Not Balanaced." << endl;
    }


    return 0;
}