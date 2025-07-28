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
    printTree(root->left);
    printTree(root->right);
}

// function to check if two trees are mirrors of each other
bool areMirror(Node* root1, Node* root2){
    // if both trees are empty, they are mirrors of each other
    if(!root1 && !root2) return true;
    // if one of the trees is empty, they are not mirrors of each other
    if(!root1 || !root2) return false;

    return (root1->data == root2->data) && areMirror(root1->left, root2->right) && areMirror(root1->right, root2->left);
}

int main(){
    // input the number of nodes in the tree
    cout << "Enter the number of nodes in the tree: ";
    int n;
    cin >> n;

    // input the nodes of the tree
    cout << "Enter the nodes of the first tree: ";
    vector<int> nodes1(n);
    for(int i = 0; i < n; i++){
        cin >> nodes1[i];
    }

    cout << "Enter the nodes of the second tree: ";
    vector<int> nodes2(n);
    for(int i = 0; i < n; i++){
        cin >> nodes2[i];
    }

    // build the tree
    Node* root1 = buildTree(nodes1, 0, n);
    Node* root2 = buildTree(nodes2, 0, n);
    // Check if the trees are mirrors of each other
    bool isMirror = areMirror(root1, root2);

    // print the result
    cout << "The trees are " << (isMirror ? "mirrors" : "not mirrors") << " of each other" << endl;
    return 0;
}

/*
    Time Complexity: O(n) - The time complexity is linear as each node is visited once
    Space Complexity: O(n) - because we are using the stack space for the recursive calls
    
*/