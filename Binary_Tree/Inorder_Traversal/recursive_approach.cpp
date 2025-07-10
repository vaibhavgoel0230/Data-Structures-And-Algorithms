#include <iostream>
#include <vector>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to create tree from given array
Node* createTree(int arr[], int index, int n) {
    if (index >= n || arr[index] == -1) {
        return nullptr;
    }

    // Create current node
    Node* root = new Node(arr[index]);

    // Recursively create left and right subtrees
    root->left = createTree(arr, 2 * index + 1, n);
    root->right = createTree(arr, 2 * index + 2, n);

    return root;
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(Node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    inorderTraversal(root->left, result);

    // Visit the current node
    result.push_back(root->data);

    // Traverse the right subtree
    inorderTraversal(root->right, result);
}

// Function to delete the binary tree
void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Recursively delete the left and right subtrees
    deleteTree(root->left);
    deleteTree(root->right);

    // Delete the current node
    delete root;
}   

int main() {
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create the binary tree
    Node* root = createTree(arr, 0, n);

    // Perform inorder traversal
    vector<int> result;
    inorderTraversal(root, result);

    // Print the result
    cout << "Inorder traversal of the binary tree: ";
    for (int val : result) {
        cout << val << " ";
    }

    cout << endl;

    // Free the allocated memory
    deleteTree(root);

    return 0;
}

// COMPLEXITY ANALYSIS:
// - Time Complexity: O(n) - We traverse each node exactly once
// - Space Complexity: O(n) - Uses an auxiliary space which holds all nodes when dealing with a skewed tree.
// - The maximum number of nodes that could be in stack at any given time would be roughly the height of the tree, which is O(log₂n) for a balanced tree
// - However, in the worst case of a completely skewed/unbalanced tree, the height could be O(n), making the maximum stack size O(n)
// - This is why we consider the space complexity to be O(n) to account for the worst case scenario

// EXPLANATION:
// - The inorder traversal of a binary tree is a traversal that visits the left subtree, the root node, and then the right subtree.
// - The recursive approach is straightforward and easy to understand.
// - However, it uses an auxiliary space which holds all nodes when dealing with a skewed tree.
// - The space complexity is O(n) because the recursive stack can have at most n/2 nodes when the tree is balanced.
// - The time complexity is O(n) because we visit each node exactly once.
