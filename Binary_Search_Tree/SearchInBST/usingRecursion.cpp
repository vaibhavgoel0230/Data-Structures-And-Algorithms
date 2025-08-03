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

// function to build the tree
TreeNode* buildTree(vector<int> &nodes, int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >= n || nodes[index] == -1) return NULL;

    // create the root node
    TreeNode* root = new TreeNode(nodes[index]);
    // create the left and right subtrees
    root->left = buildTree(nodes, 2*index+1, n);
    root->right = buildTree(nodes, 2*index+2, n);
    // return the root node
    return root;
}

// function to search in the BST
TreeNode* searchInBST(TreeNode* root, int val){
    // if the root is NULL or the value is found, return the root
    if(root==NULL || root->val==val) return root;

    // if the value is less than the root, search in the left subtree
    if((val < root->val) && (root->left)){
        TreeNode* left = root->left;
        root->right = root->left = NULL; root = NULL; free(root);
        return searchInBST(left, val);
    }

    // if the value is greater than the root, search in the right subtree
    if((val > root->val) && (root->right)){
        TreeNode* right = root->right;
        root->right = root->left = NULL; root = NULL; free(root);
        return searchInBST(right, val);
    }

    // if the value is not found, return NULL
    return NULL;
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

    // build the tree
    TreeNode* root = buildTree(nodes, 0, n);

    // input the value to search
    cout << "Enter the value to search: ";
    int val;
    cin >> val;

    // search in the BST
    TreeNode* result = searchInBST(root, val);

    // print the result
    if(result == NULL) cout << "Not Found" << endl;
    else cout << "Found" << endl;

    return 0;
}

// Time complexity: O(h), where h is the height of the BST.
// Auxiliary Space: O(h) This is because of the space needed to store the recursion stack.