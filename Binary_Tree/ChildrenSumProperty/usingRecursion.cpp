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

// function to check if the tree satisfies the children sum property
bool isChildrenSum(Node* root){
    // if the tree is empty, it satisfies the children sum property
    if(root==NULL) return true;

    // if the left and right subtrees satisfy the children sum property, then the current tree satisfies the children sum property
    bool leftSatisfies = isChildrenSum(root->left);
    bool rightSatisfies = isChildrenSum(root->right);

    int sum=0;
    // if the left child exists, add its value to the sum
    if(root->left) sum+=root->left->data;
    // if the right child exists, add its value to the sum
    if(root->right) sum+=root->right->data;

    // if the sum is 0, then the current tree satisfies the children sum property
    if(sum==0) return true;

    // return true if the current node's value is equal to the sum of the left and right child's values and the left and right subtrees satisfy the children sum property
    return (root->data == sum) && leftSatisfies && rightSatisfies;
}

int main(){
    // input the number of nodes in the tree
    cout << "Enter the number of nodes in the tree: ";
    int n;
    cin >> n;

    // input the nodes of the tree
    cout << "Enter the nodes of tree: ";
    vector<int> nodes(n);
    for(int i = 0; i < n; i++){
        cin >> nodes[i];
    }

    // build the tree
    Node* root = buildTree(nodes, 0, n);
    // Check if the tree satisfies the children sum property
    bool isChildrenSumSatisfied = isChildrenSum(root);

    // print the result
    cout << "The tree " << (isChildrenSumSatisfied ? "satisfies" : "does not satisfy") << " the children sum property" << endl;
    return 0;
}

/*
    Time Complexity: O(n) - The time complexity is linear as each node is visited once
    Space Complexity: O(n) - because we are using the stack space for the recursive calls
    
*/