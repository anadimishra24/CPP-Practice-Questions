#include <bits/stdc++.h>
using namespace std;



/* In this file "Tree.cpp I add all those leetcode question that i completed"*/

/* Tree Class and some implementation
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
*/

/* Question: 94. Binary Tree Inorder Traversal */
    https://leetcode.com/problems/binary-tree-inorder-traversal

/* Question: 100. Same Tree */
    https://leetcode.com/problems/same-tree

/* Question: 104. Maximum Depth of Binary Tree */
    https://leetcode.com/problems/maximum-depth-of-binary-tree

/* Question: 111. Minimum Depth of Binary Tree */
    https://leetcode.com/problems/minimum-depth-of-binary-tree

/* Question: 112. Path Sum */
    https://leetcode.com/problems/path-sum

/* Question: 144. Binary Tree Preorder Traversal */
    https://leetcode.com/problems/binary-tree-preorder-traversal

/* Question: 145. Binary Tree Postorder Traversal */
    https://leetcode.com/problems/binary-tree-postorder-traversal

/* Question: 222. Count Complete Tree Nodes */
    https://leetcode.com/problems/count-complete-tree-nodes

/* Question: 257. Binary Tree Paths */
    https://leetcode.com/problems/binary-tree-paths

/* Question: 404. Sum of Left Leaves */
    https://leetcode.com/problems/sum-of-left-leaves

/* Question: 700. Search in a Binary Search Tree */
    https://leetcode.com/problems/search-in-a-binary-search-tree


/* Question: 872. Leaf-Similar Trees */
    There is three solution for this question.
    1. When we check the left and right and find the sum of left leaf node.
    2. We pass a boolean to maintain the record of left tree, if left tree then passed true otherwise false 
    3. We pass a node that act a parent node, when we reach to any leaf node we check the leaf node and parent both should be same, if not then we not include that node in sum
    
    https://leetcode.com/problems/leaf-similar-trees

/* Question: 543. Diameter of Binary Tree  */
    https://leetcode.com/problems/diameter-of-binary-tree

/* Question: 563. Binary Tree Tilt  */
    get the roots left and right value do substraction add to result, 
    but when returning keep in mind that we need the sum of root,left,right node because 
    we need to sum of all left and right for next node 

    https://leetcode.com/problems/binary-tree-tilt/description/

/* Question: 572. Subtree of Another Tree */
    1. Just check the root value at every level of left and right.
    2. We do preorder(RLR) for both root and subRoot and find the substring (prorder of subRoot)
       in the string (preorder of root).
       >> NOTE: We need to maintain the 'null' value also in preorder traversal otherwise the may begin  
                we got the same sequence of substirng in the string but it necesserry it is the same order.

    https://leetcode.com/problems/subtree-of-another-tree


/* Question: 783. Minimum Distance Between BST Nodes */
    https://leetcode.com/problems/minimum-distance-between-bst-nodes

/* Question: */
    We check the current node value is within range or not: Rane is defined as
      (any number smaller than root)root-> left < root < root -> right (any number greater than root)
    https://leetcode.com/problems/validate-binary-search-tree/

/* Question: 530. Minimum Absolute Difference in BST */
    https://leetcode.com/problems/minimum-absolute-difference-in-bst


/* Question: 1448. Count Good Nodes in Binary Tree */
    https://leetcode.com/problems/count-good-nodes-in-binary-tree/


/* Question: 199. Binary Tree Right Side View */
    https://leetcode.com/problems/binary-tree-right-side-view


/* Question: 1161. Maximum Level Sum of a Binary Tree */
    https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree


/* Question: 450. Delete Node in a BST */
    https://leetcode.com/problems/delete-node-in-a-bst

    
/* Question: */


/* Question: */

/* Question: */


/* Question: */

/* Question: */


/* Question: */

/* Question: */


/* Question: */




