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

// main function body for sum tree using pair<int, int>
pair<int, int> sumTree(Node* root){

    // base case
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    // base case for leaf node
    if(root -> left == NULL && root -> right == NULL){
        pair<bool, int> p = make_pair(true, root -> data);
        return p;
    }

    pair<bool, int> left = sumTree(root -> left);
    pair<bool, int> right = sumTree(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool sum = (root -> data == left.second + right.second);

    pair<bool, int> ans;
    //ans.second = max(left.second, right.second) + 1;
    if(leftAns && rightAns && sum){
        ans.first = true;
        ans.second = 2 * root -> data;
    }
    else{
        ans.first = false;
    }
    return ans;
}

// function for sum tree
bool isSumTree(Node* root){

    return sumTree(root).first;

}

int main(){

    Node* root = NULL;

    /* Input: 3 1 -1 -1 2 -1 -1
                 3
                /  \ 
               1    2

        Output: 1; The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node.
                    Therefore,the given binary tree is a sum tree
    */

    /* Input: 10 20 40 -1 -1 60 -1 -1 30 -1 -1 
                        10
                       /   \
                      20    30
                    /   \ 
                   40   60

    Output: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10
            which is not equal to 30+40
    */
    
    root = createBinaryTree(root);

    // print the tree in level order
    cout << "Level order traversal: \n";
    levelOrderTraversal(root);

    // is binary tree is sum tree or not
    if(isSumTree(root)){
        cout << "Is tree is a sum tree." << endl;
    }
    else{
        cout << "No tree is not a sum tree." << endl;
    }
    return 0;
}