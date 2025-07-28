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

// function to find the LCA of the tree
Node* findLCA(Node* root, int p, int q){
    // if the root is NULL, return NULL
    if(root==NULL) return NULL;

    // if the root is the LCA, return the root
    if(root->data==p || root->data==q) return root;

    // find the LCA in the left and right subtrees
    Node* left = findLCA(root->left, p, q);
    Node* right = findLCA(root->right, p, q);

    // if the left subtree is NULL, return the right subtree
    if(left==NULL){
        return right;
    }
    // if the right subtree is NULL, return the left subtree
    else if(right==NULL){
        return left;
    }
    // if both subtrees are not NULL, return the root
    else{
        return root;
    }
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

    // input the two nodes
    cout << "Enter the two nodes: ";
    int p, q;
    cin >> p >> q;

    // build the tree
    Node* root = buildTree(nodes, 0, n);
    
    // find the LCA of the tree
    Node* lca = findLCA(root, p, q);

    // print the LCA of the tree
    cout << "The LCA of the tree is: " << lca->data << endl;
    return 0;
}

/*
    Time Complexity: O(n) - because we are traversing the tree only once
    Space Complexity: O(n) - because we are using the stack space for the recursive calls
    
*/