#include <iostream>
#include <vector>
using namespace std;

// TreeNode structure
struct TreeNode {
    // value of the node
    int val;
    // left child of the node
    TreeNode* left;
    // right child of the node
    TreeNode* right;

    // constructor
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

// createTree function
TreeNode* createTree(int arr[], int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >= n || arr[index] == -1){
        return NULL;
    }

    // create the root node
    TreeNode* root = new TreeNode(arr[index]);
    // create the left child
    root->left = createTree(arr, 2*index + 1, n);
    // create the right child
    root->right = createTree(arr, 2*index + 2, n);

    // return the root node
    return root;
}

// preorderTraversal function - root -> left -> right
void preorderTraversal(TreeNode* root, vector<int> & preorderArr){
    // BASE CASE: if the root is NULL, return
    if( root == NULL ){
        return;
    }

    // add the root value to the preorderArr
    preorderArr.push_back(root->val);
    // recursive call to the left child
    preorderTraversal(root->left, preorderArr);
    // recursive call to the right child
    preorderTraversal(root->right, preorderArr);
}

// print function
void print(vector<int> printArr){
    // print the preorderArr
    for(int i=0; i<printArr.size(); i++){
        cout << printArr[i] << " ";
    }

    cout << endl;
}

// main function
int main(){
    // enter the number of elements in the tree
    cout << "Enter the number of elements in the tree: ";
    int n;
    cin >> n;

    // enter the elements of the tree
    int arr[n];
    cout << "Enter the elements of the tree: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // create the tree
    TreeNode* root = createTree(arr, 0, n);
    // create the preorderArr
    vector<int> preorderArr;

    // perform the preorder traversal
    preorderTraversal(root, preorderArr);

    // print the preorderArr
    print(preorderArr);
    return 0;
}

/*
    Time Complexity: O(n) - where n is the number of nodes in the tree as we traverse each node exactly once
    Space Complexity: O(n) - where n is the number of nodes in the tree as we store the preorder traversal in the preorderArr
*/