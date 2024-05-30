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

void printBinaryTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Print the value of the current node
    cout << root->data << " ";

    // Recursively print the left and right subtrees
    cout << "Left of " << root->data << ": ";
    printBinaryTree(root->left);
    cout << "Right of " << root->data << ": ";
    printBinaryTree(root->right);
}

// Function for preorder traversal
vector<int> preOrder(Node* root) {
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }
    // Recursive call for Node Left Right
    vector<int> left = preOrder(root->left);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.push_back(root->data);
    vector<int> right = preOrder(root->right);
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}

// Function to check if two binary trees are the same
bool isSameTree(Node* p, Node* q) {
    vector<int> p_tree = preOrder(p);
    vector<int> q_tree = preOrder(q);
    if (p_tree.size() != q_tree.size()) {
        return false;
    }
    for (int i = 0; i < q_tree.size(); i++) {
        if (p_tree[i] != q_tree[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);
    p->left->left = new Node(4);
    p->left->right = new Node(5);

    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);
    q->left->left = new Node(4);
    q->left->right = new Node(5);

    if(isSameTree(p,q)){
        cout << "TRUE" << endl;
    }
    else{
        cout << "FALSE" << endl;
    }

    return 0;
}



