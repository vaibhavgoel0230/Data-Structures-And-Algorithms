#include <iostream>
#include <vector>
#include <queue>

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
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// function to create the tree
TreeNode* createTree(int arr[], int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >= n || arr[index] == -1){
        return NULL;
    }

    // create the root node
    TreeNode* root = new TreeNode(arr[index]);
    // create the left and right subtrees
    root->left = createTree(arr, 2*index+1, n);
    root->right = createTree(arr, 2*index+2, n);

    return root;
}

// function to print the result vector
void print(vector<int>& results){
    for(int i=0; i<results.size(); i++){
        cout << results[i] << " ";
    }

    cout << endl;
}

// function to get the left view of the tree
void leftView(TreeNode* root, int level, vector<int>& results){
    // if the root is NULL, return
    if(!root) return;
    // if the size of the result vector is equal to the level, add the value of the node to the result vector
    if(results.size() == level){
        results.push_back(root->val);
    }
    // traverse the left and right subtrees
    leftView(root->left, level+1, results);
    leftView(root->right, level+1, results);
}

int main(){
    // get the number of nodes in the tree
    cout << "Enter the number of nodes in the tree: ";
    int n;
    cin >> n;

    // get the values of the nodes
    cout << "Enter the values of the nodes: ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // create the tree
    TreeNode* root = createTree(arr, 0, n);

    // get the left view of the tree
    vector<int> results;
    leftView(root, 0, results);

    // print the left view
    print(results);

    // return 0
    return 0;
}

/*
 Time Complexity: O(h), h is the height of the tree. - This complexity arises as we travel along the height of the tree.
 1. Average Case: O(log2(n)) - For a balanced tree, the height is log2(n).
 2. Worst Case: O(n) - For a skewed tree, the height is n.

 Space Complexity: O(h), h is the height of the tree. - This complexity arises as we use a vector to store the left view.
 1. Average Case: O(log2(n)) - For a balanced tree, the height is log2(n).
 2. Worst Case: O(n) - For a skewed tree, the height is n.
*/
