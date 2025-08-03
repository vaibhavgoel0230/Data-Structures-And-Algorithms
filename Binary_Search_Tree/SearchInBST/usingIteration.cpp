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
bool searchInBST(TreeNode* root, int val){
    // create a temporary pointer to the root
    TreeNode* temp = root;

    // traverse the tree
    while(temp){
        // if the value is found, return true
        if(val == temp->val) return true;
        // if the value is less than the current node, move to the left child
        else if(val < temp->val) temp = temp->left;
        // if the value is greater than the current node, move to the right child
        else temp = temp->right;
    }

    // if the value is not found, return false
    return false;
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
    bool result = searchInBST(root, val);

    // print the result
    if(result == false) cout << "Not Found" << endl;
    else cout << "Found" << endl;

    return 0;
}

// Time Complexity: O(h), where h is the height of the BST.
// Space Complexity: O(1) - we are not using any extra space
