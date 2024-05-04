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


Node* createBinaryTree(Node* root){

    int data;
    cout << "Enter the data: ";
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

/* pair<int,int> means it hold two int value pair<diameter,height>
    use pair<int,int> for get the Time Complexity O(n) */
pair<int, int> diameterAndHeight(Node* root){

    // base case
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterAndHeight(root -> left);
    pair<int,int> right = diameterAndHeight(root -> right);

    int dia1 = left.first;
    int dia2 = right.first;
    int dia3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(dia1, max(dia2,dia3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}


// get the diameter of tree
int getDiameterOfBinaryTree(Node* root){

    /* Its working fine but its Time Complexity is O(nxn)
        becasue when we call getDiameterOfBinaryTree(root -> left) or 
        getDiameterOfBinaryTree(root -> right) we simultaneously called
        getHeightOfBinaryTree(root -> left) due to this its time complexity is O(NxN)
    // base case
    if(root == NULL){
        return 0;
    }

    int dia1 = getDiameterOfBinaryTree(root -> left);
    int dia2 = getDiameterOfBinaryTree(root -> right);
    int dia3 = getHeightOfBinaryTree(root -> left) + 1 + getHeightOfBinaryTree(root -> right);

    int ans = max(dia1, max(dia2, dia3));

    return ans;
    */


   return diameterAndHeight(root).first;
}

int main(){

    /*
        Input: 1 2 -1 -1 3 -1 -1 
                     1
                    /  \
                   2    3
        Output: 3

        Input:  10 20 40 -1 -1 60 -1 -1 30 -1 -1 
                        10
                       /   \
                      20    30
                    /   \ 
                   40   60
        Output: 4
    */

    Node* root = NULL;

    root = createBinaryTree(root);

    // print the tree in level order
    cout << "Level order traversal: \n";
    levelOrderTraversal(root);

    // diameter of binary tree
    int diameter = getDiameterOfBinaryTree(root);
    cout << "Diameter of Binary Tree: " << diameter << endl;

    return 0;
}