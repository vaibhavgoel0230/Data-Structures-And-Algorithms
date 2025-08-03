#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// TreeNode class
class TreeNode{
    public:
    // data
    int data;
    // left and right pointers
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode(int data){
        this->data = data;
        left = right = NULL;
    }
};

// buildTree function to build the tree from the array
TreeNode* buildTree(vector<int> &arr, int index, int n){
    // if index is out of bounds or the value is -1, return NULL
    if(index >= n || arr[index] == -1){
        return NULL;
    }

    // create a new TreeNode
    TreeNode* root = new TreeNode(arr[index]);
    // build the left and right subtrees
    root->left = buildTree(arr, 2*index+1, n);
    root->right = buildTree(arr, 2*index+2, n);
    return root;
}

// isValidBST function to check if the tree is a valid BST
bool isValidBST(TreeNode* root, int minVal, int maxVal){
    // if the tree is empty, it is a valid BST
    if(root == NULL){
        return true;
    }

    // if the root data is out of the range, return false
    if(root->data < minVal || root->data > maxVal){
        return false;
    }

    // check if the left and right subtrees are valid BSTs
    return isValidBST(root->left, minVal, root->data-1) && isValidBST(root->right, root->data+1, maxVal);
}

int main(){
    // take the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;
    vector<int> arr(n);
    // take the elements of the array
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // build the tree
    TreeNode* root = buildTree(arr, 0, n);
    // check if the tree is a valid BST
    if(isValidBST(root, INT_MIN, INT_MAX)){
        cout << "The tree is a valid BST" << endl;  
    }
    else{
        cout << "The tree is not a valid BST" << endl;
    }
    return 0;
}

// Time Complexity: O(n) - because we are traversing the tree once
// Space Complexity: O(h) - because we are using recursion and the stack space will be O(h). O(n) in worst case where the tree is a linked list/skewed tree.
// O(log(n)) in best case where the tree is a balanced binary tree.