#include <iostream>
#include <vector>

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

// function to convert sorted array to BST
TreeNode* sortedArrayToBST(vector<int> &nums, int start, int end){
    // if the start index is greater than the end index, return NULL
    if(start > end) return NULL;

    // find the middle index
    int mid = start + (end - start) / 2;

    // create the root node
    TreeNode* root = new TreeNode(nums[mid]);

    // create the left and right subtrees
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

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

    // convert the sorted array to BST
    TreeNode* root = sortedArrayToBST(nodes, 0, n-1);

    // print the tree
    printTree(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(n) - we are using the recursion stack to store the nodes
