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

// zig zag level order traversal of binary tree
vector<int> zigZagLevelOrderTraversal(Node* root){

    vector<int> result;
    if(root == NULL){
        return result;
    }

    // create a queue for storing the node's data from level order also in zig zag way
    queue<Node*> que;
    
    // insert the root in queue
    que.push(root);

    // create a flag for determining the path for traversal either left to right or vice versa
    bool leftToRight = true;

    while(!que.empty()){
        int size = que.size();
        vector<int> temAns(size);

        // level process
        for (int i = 0; i < size; i++){
            Node* firstNode = que.front();
            que.pop();

            /* check the condition wheater leftToRight is true/false and set index according to it
                 if is it true means we have to travserse from left to right otherwise right to left*/
            int index = leftToRight ? i : size - i - 1;

            temAns[index] = firstNode -> data;

            // firstNode's left is not NULL then push into the stack
            if(firstNode -> left){
                que.push(firstNode -> left);
            }

            // firstNode's right is not NULL then push into the stack
            if(firstNode -> right){
                que.push(firstNode -> right);
            }
        }

        // reverse the direction
        leftToRight = !leftToRight;

/*
        cout << "Printing the temporary array:";
        for (int i = 0; i < temAns.size(); i++)
        {
            cout << temAns[i] << " ";
        }
        cout << endl;
*/
        
        // push the temporary answer in final result vector
        for(auto i: temAns){
            // cout << "\n\t i = " << i << endl;
            result.push_back(i);
        }
    }
    return result;
}

int main(){

    Node* root = NULL;

    /*  Input: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1           
                      1
                    /   \
                   2     3
                  / \   / \
                 4   5 6   7
        
        Output: 1 3 2 4 5 6 7
    */

    /* Input: 7 9 8 10 -1 -1 9 -1 -1 8 -1 -1 7 6 -1 -1 -1
                                7
                             /     \
                            9       7
                          /  \     /   
                         8    8   6     
                        /  \
                       10   9 
        Output: 7 7 9 8 8 6 9 10 
    */
    
    root = createBinaryTree(root);

    // print the tree in level order
    cout << "Level order traversal: \n";
    levelOrderTraversal(root);

    // zig zag traversal of binary tree
    vector <int> ans = zigZagLevelOrderTraversal(root);

    cout << "Zig Zag level order traversal of Binary Tree: ";
    for(auto node : ans){
        cout << node << " ";
    }
    return 0;
}