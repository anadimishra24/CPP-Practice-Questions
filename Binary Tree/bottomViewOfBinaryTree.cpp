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


// bottom view of binary tree
vector<int> bottomView(Node* root){

    vector<int> ans;
    // base case
    if(root == NULL){
        return ans;
    }

    // one to one mapping
    map<int, int> topNode;
    queue<pair<Node*, int>> que;

    que.push(make_pair(root, 0));

    while(!que.empty()){
        pair<Node*, int> temp = que.front();
        que.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
      
        // if one value is present for a hd, then do nothing
        //if(topNode.find(hd) == topNode.end()){  just removed this condition from topView code remains same
        topNode[hd] = frontNode -> data;
        //}
        if(frontNode -> left){
            que.push(make_pair(frontNode -> left,hd-1));
        }

        if(frontNode -> right){
            que.push(make_pair(frontNode -> right, hd+1));
        }
    }

    for(auto i: topNode){
        ans.push_back(i.second);
    }

    return ans;
}

int main(){

    Node* root = NULL;

    /*  Input: 1 3 -1 -1 2 -1 -1

        Let there is number line:
                   -2 -1   0     1  2  3        
                          1
                        /    \
                       3      2           
        
        Explanation: Node 1 is at <0> and Node 2 is at <-1> and Node 4 is at <-2>....
                    now we calculate its horizontal distance from root and if any hd <> have more than one node than discard the first one and insert new node because bottom node hide the upper node like: <0> have 1, 5, 6 so discard 5 and 6 i.e.
                           ___________________________________
                          | Horizontal Distace(hd) |  Node    |
                          |----------------------- |----------|
                          |          <0>           | 1        |
                          |          <-1>          | 3        |
                          |          <1>           | 2        |
                          |________________________|__________|
    
                    And we print the nodes of hd in sorted order like: <-2>, <-1>, <0>, <1>, <2>, <3>
        Output: 3 1 2
    */

    /* Input: 10 20 40 -1 -1 60 -1 -1 30 -1 -1
                               10
                            /      \
                          20        30
                         /   \    
                        40   60   
        Output: 40 20 60 30
    */
    
    root = createBinaryTree(root);

    // print the tree in level order
    cout << "Level order traversal: \n";
    levelOrderTraversal(root);

    // bottom view of binary tree
    vector <int> ans = bottomView(root);

    cout << "Bottom view of Binary Tree: ";
    for(auto node : ans){
        cout << node << " ";
    }
    return 0;
}