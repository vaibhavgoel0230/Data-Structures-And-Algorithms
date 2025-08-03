#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// TreeNode class
struct TreeNode{
    // value of the node
    int val;
    // left child of the node
    TreeNode* left;
    // right child of the node
    TreeNode* right;
    // constructor
    TreeNode(int val){
        // initialize the value of the node
        this->val = val;
        // initialize the left and right children to NULL
        left = right = NULL;
    }
};

// helper function to convert preorder to BST
void helper(TreeNode* root, vector<int> &preorder, int &i, int ub){
    // if the index is out of bounds or the value is greater than the upper bound, return
    if(i >= preorder.size() || preorder[i] >= ub) return;

    // if the value is less than the root value, create a left child
    if(preorder[i] < root->val){
        root->left = new TreeNode(preorder[i++]);
        helper(root->left, preorder, i, root->val);
    }

    // if the value is greater than the root value, create a right child
    if(i < preorder.size() && preorder[i] > root->val){
        root->right = new TreeNode(preorder[i++]);
        helper(root->right, preorder, i, ub);
    }
}

// Function to convert preorder to BST
TreeNode* preorderToBST(vector<int> &preorder){
    // if the preorder is empty, return NULL
    if(preorder.empty()) return NULL;

    // create the root node
    TreeNode* root = new TreeNode(preorder[0]);

    // initialize the index
    int i=1;
    // call the helper function to convert the preorder to BST
    helper(root, preorder, i, INT_MAX);

    // return the root node
    return root;
}


// function to print the tree
void printTree(TreeNode* root){
    // if the root is NULL, return
    if(root == NULL) return;

    // print the value of the node
    cout << root->val << " ";

    // print the left subtree
    printTree(root->left);

    // print the right subtree
    printTree(root->right);
}

int main(){
    // input the number of nodes
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    
    // input the nodes
    cout << "Enter the nodes: ";
    vector<int> nodes(n);
    for(int i = 0; i < n; i++){
        cin >> nodes[i];
    }

    // convert the preorder to BST
    TreeNode* root = preorderToBST(nodes);

    // print the tree
    printTree(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(n) - because we are iterating through the preorder array once
// Space Complexity: O(n) - because we are creating a new tree