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

// function to print the tree
void printTree(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    printTree(root->right);
}

// function to find the LCA of the tree
Node* flattenTree(Node* root){
    // Morris Traversal
    Node* curr = root;
    while(curr){
        if(curr->left){
            Node* prev = curr->left;
            while(prev->right) prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        } else{
            curr = curr->right;
        }
    }
    return root;
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
    
    // Flatten Binary Tree to Linked List
    flattenTree(root);

    // print the LL
    printTree(root);
    cout << endl;
    return 0;
}

/*
    Time Complexity: O(2n) - The time complexity is linear as each node is visited twice ( once for establishing the temporary link and once for reverting it)
    Space Complexity: O(1) - because we are not using any extra space for the recursive calls
    
*/