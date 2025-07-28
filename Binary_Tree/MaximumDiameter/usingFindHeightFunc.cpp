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

// function to find the height of the tree
int findHeight(Node* root){
    // if the root is NULL, return 0
    if(root == NULL) return 0;
    // find the height of the left and right subtrees
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    // return the height of the tree
    return 1 + max(leftHeight, rightHeight);
}

// function to find the diameter of the tree
int findDiameter(Node* root){
    // if the root is NULL, return 0
    if(root == NULL) return 0;
    // find the height of the left and right subtrees
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // find the diameter of the left and right subtrees
    int leftDiameter = findDiameter(root->left);
    int rightDiameter = findDiameter(root->right);
    // return the diameter of the tree  
    return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
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
    
    // find the diameter of the tree
    int diameter = findDiameter(root);

    // print the diameter of the tree
    cout << "The diameter of the tree is: " << diameter << endl;
    return 0;
}

/*
    Time Complexity: O(n^2) - 
    - For every node root, it calls findHeight on both subtrees.
    - findHeight is O(n) on a tree of size n, but you're calling it for each node.
    - So total time = O(n) (nodes) × O(n) (height calls) = O(n²) in the worst case.
    Space Complexity: O(n) - because we are using the stack space for the recursive calls
    - Each recursive call adds one layer to the stack.
    - So space is O(h), where h is the height of the tree (O(n) in worst-case, O(log n) in balanced tree)
*/