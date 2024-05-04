#include <bits/stdc++.h>
using namespace std;


// class for creating the tree Node
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

// inorder traveral
void inorderTraversal(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    // recursive call : L N R
    inorderTraversal(root->left);
    cout << root-> data << " ";
    inorderTraversal(root->right);

}

// preorder traveral
void preorderTraversal(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    // recursive call : N L R
    cout << root-> data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);

}

// postorder traveral
void postorderTraversal(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    // recursive call : L R N
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root-> data << " ";

}

// build tree from level order
void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new Node(data);
    
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left Node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right Node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){

    Node* root = NULL;

    // Input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = createBinaryTree(root);

    cout << "Level order traversal: \n";
    levelOrderTraversal(root);

    cout << "inorder traversal is:  ";
    inorderTraversal(root); 

    cout << "\npreorder traversal is:  ";
    preorderTraversal(root);

    cout << "\npostorder traversal is:  ";
    postorderTraversal(root);
    
    // build tree from level order  || Input: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);
    
    // print the tree that build from buildFromLevelOrder(root);
    levelOrderTraversal(root);

    
    return 0;
}

