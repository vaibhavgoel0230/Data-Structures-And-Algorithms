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
bool isSymmetricUtil(TreeNode* root1, TreeNode* root2){
    // if both the roots are NULL, return true
    if(!root1 && !root2) return true;
    // if one of the roots is NULL, return false
    if(!root1 || !root2) return false;
    // if the values of the roots are not equal, return false
    if(root1->val != root2->val) return false;
    // check if the left and right subtrees are symmetric
    return isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
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

    bool isSymmetric = true;
    if(!root) isSymmetric = false;
    // find if the tree is symmetric
    else isSymmetric = isSymmetricUtil(root->left, root->right);
    // print if the tree is symmetric
    cout << "The tree is symmetric: " << isSymmetric << endl;
    // return 0 to indicate successful execution
    return 0;
}


// Time Complexity: O(n) - each node is processed exactly once
// Space Complexity: O(n) - Recursive stack space is used to calculate the height of the tree at each node and it makes the space complexity O(h) and h is the height of the tree
// in worst case, the height of the tree can be n, so the space complexity is O(n)
