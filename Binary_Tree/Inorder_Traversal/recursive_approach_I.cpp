#include <iostream>
#include <vector>
using namespace std;

// Create a TreeNode struct
struct TreeNode {
    int val; // Value of the node
    TreeNode* left; // Pointer to the left child
    TreeNode* right; // Pointer to the right child
    TreeNode(int x){ // Constructor for the TreeNode struct
        val = x;
        left = right = nullptr;
    }
};

// Create a function to create a binary tree from an array
TreeNode* createTree(int arr[], int index, int n){
    // If the index is out of bounds or the value is -1, return nullptr
    if(index >= n || arr[index] == -1){
        return nullptr;
    }

    // Create a new TreeNode
    TreeNode* root = new TreeNode(arr[index]);

    // Recursively create the left and right subtrees
    root->left = createTree(arr, 2*index+1, n);
    root->right = createTree(arr, 2*index+2, n);

    // Return the root of the tree
    return root;
}

// Create a function to perform an inorder traversal of the binary tree
vector<int> inorderTraversal(TreeNode* root){
    // If the root is nullptr, return an empty vector
    if(root == nullptr){
        return {};
    }

    // Recursively traverse the left subtree
    vector<int> leftVec = inorderTraversal(root->left);

    // Add the value of the current node to the result
    int mid = root->val;

    // Recursively traverse the right subtree
    vector<int> rightVec = inorderTraversal(root->right);

    // Create a result vector and insert the left subtree, current node, and right subtree
    vector<int> result;
    result.insert(result.end(), leftVec.begin(), leftVec.end());
    result.push_back(mid);
    result.insert(result.end(), rightVec.begin(), rightVec.end());

    // Return the result vector
    return result;
}

// Create a function to print an array
void printArray(vector<int> arr){
    // Iterate through the array and print each element
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Create a function to delete the binary tree
void deleteTree(TreeNode* root){
    // If the root is nullptr, return
    if(root == nullptr){
        return;
    }

    // Recursively delete the left and right subtrees
    deleteTree(root->left);
    deleteTree(root->right);

    // Delete the current node
    delete root;
}

// Create a main function
int main(){
    // Prompt the user to enter the number of nodes in the tree
    cout << "Enter the number of nodes in the tree: " << endl;
    int n;
    cin >> n;

    // Create an array to store the values of the nodes
    cout << "Enter the values of the nodes: " << endl;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // Create the binary tree
    TreeNode* root = createTree(arr, 0, n);

    // Perform an inorder traversal of the binary tree
    vector<int> result = inorderTraversal(root);

    // Print the result
    printArray(result);

    // Delete the binary tree
    deleteTree(root);

    return 0;
}

/*
    Time Complexity: O(n) - We traverse the entire tree once
    Space Complexity: O(n) - We use a vector to store the result
*/