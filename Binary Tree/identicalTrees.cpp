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
bool isIdentiticalBinaryTree(Node* root1, Node* root2){

    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 != NULL && root2 == NULL){
        return false;
    }

    if(root1 == NULL && root2 != NULL){
        return false;
    }

    bool left = isIdentiticalBinaryTree(root1 -> left, root2 -> left);
    bool right = isIdentiticalBinaryTree(root1 -> right, root2 -> right);

    bool value = root1 -> data == root2 -> data;

    if(left && right && value){
        return true;
    }
    return false;
}

int main(){

    Node* root1 = NULL;     // tree1
    Node* root2 = NULL;     // tree2
    /*
        Input: 1 2 -1 -1 3 -1 -1    Input: 1 2 -1 -1 3 -1 -1
                     1                  1
                    /  \               /  \
                   2    3             2    3     
                    
                             
        Output: Identitical; There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1,
                left child of 1 is 2 and right child
                of 1 is 3

        Input:  1 2 -1 -1 3 -1 -1     Input:  1 3 -1 -1 2 -1 -1
                          1                1
                         /  \             /  \
                        2    3           3    2
        
        Output: Not Identitical;  There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
    */
    

    root1 = createBinaryTree(root1);
    root2 = createBinaryTree(root2);

    // print the tree in level order
    cout << "Level order traversal of tree1: \n";
    levelOrderTraversal(root1);

    // print the tree in level order
    cout << "Level order traversal of tree2: \n";
    levelOrderTraversal(root2);

    // is binary tree is identiticl or not
    if(isIdentiticalBinaryTree(root1, root2)){
        cout << "Identitical." << endl;
    }
    else{
        cout << "Not Identitical." << endl;
    }


    return 0;
}