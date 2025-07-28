#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// define the TreeNode structure
struct TreeNode{
    // value of the node
    int val;
    // left child of the node
    TreeNode* left;
    // right child of the node
    TreeNode* right;
    // constructor to initialize the node
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// function to create the tree from the array
TreeNode* createTree(vector<int>& arr, int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >= n || arr[index] == -1) return NULL;
    // create the root node
    TreeNode* root = new TreeNode(arr[index]);
    // create the left and right children of the root node
    root->left = createTree(arr, 2*index + 1, n);
    root->right = createTree(arr, 2*index + 2, n);
    // return the root node
    return root;
}

// function to find the maximum height of the tree
int maxHeight(TreeNode* root){
    // if the root is NULL, return 0
    if(!root) return 0;
    // find the maximum height of the left and right subtrees
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    // return the maximum height of the tree
    return 1 + max(leftHeight, rightHeight);
}

int main(){
    // number of elements in the array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    // array to store the elements of the tree
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++) cin >> arr[i];
    // create the tree from the array
    TreeNode* root = createTree(arr, 0, n);
    // find the maximum height of the tree
    int height = maxHeight(root);
    // print the maximum height of the tree
    cout << "The maximum height of the tree is: " << height << endl;
    // return 0 to indicate successful execution
    return 0;
}

// Time Complexity: O(n) - each node is processed exactly once
// Space Complexity: O(n) - uses a stack to store the nodes and at most n/2 nodes can be present in the stack at any level