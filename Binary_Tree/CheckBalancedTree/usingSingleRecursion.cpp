#include <iostream>
#include <vector>
using namespace std;

// define the Node structure
struct Node{
    // value of the node
    int data;
    // left child of the node
    Node* left;
    // right child of the node
    Node* right;

    // constructor to initialize the node
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// function to build the tree
Node* buildTree(vector<int> &nodes, int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if((index>=n) || (nodes[index] == -1)) return NULL;
    // create the root node
    Node* root = new Node(nodes[index]);
    // create the left and right subtrees
    root->left = buildTree(nodes, 2*index+1, n);
    root->right = buildTree(nodes, 2*index+2, n);
    // return the root node
    return root;
}

// function to check if the tree is balanced
int checkBalanced(Node* root){
    // if the root is NULL, return true as empty tree is balanced
    if(root == NULL) return 0;
    
    // check if left and right subtrees are balanced
    int isLeftBalanced = checkBalanced(root->left);
    if(isLeftBalanced == -1) return -1;
    int isRightBalanced = checkBalanced(root->right);
    if(isRightBalanced == -1) return -1;
    
    if(abs(isLeftBalanced - isRightBalanced) > 1) return -1;
    
    // check if current node is balanced and subtrees are balanced
    return 1 + max(isLeftBalanced, isRightBalanced);
}

int main(){
    // input the number of nodes in the tree
    cout << "Enter the number of nodes in the tree: ";
    int n;
    cin >> n;

    // input the nodes of the tree
    cout << "Enter the nodes of the tree: ";
    vector<int> nodes(n);
    for(int i = 0; i < n; i++){
        cin >> nodes[i];
    }

    // build the tree
    Node* root = buildTree(nodes, 0, n);
    
    // check if the tree is balanced
    int isBalanced = checkBalanced(root);

    if(isBalanced!=-1){
        cout << "The tree is balanced" << endl;
    }
    else{
        cout << "The tree is not balanced" << endl;
    }

    return 0;
}

/*
    Time Complexity: O(n) - it checks each node only once
    Space Complexity: O(1) - no extra space/data structure is used
    - O(h) - But the recursive stack space is used where h is the height of the tree
*/