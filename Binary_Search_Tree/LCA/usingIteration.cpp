#include <iostream>
#include <vector>
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
    
// LCA function to find the lowest common ancestor of two nodes
TreeNode* LCA(TreeNode* root, int a, int b){
    // traverse the tree
    while(root != NULL){
        // if the root is greater than a and b, then the lowest common ancestor is in the left subtree
        if(root->data > a && root->data > b){
            root = root->left;
        }
        // if the root is less than a and b, then the lowest common ancestor is in the right subtree
        else if(root->data < a && root->data < b){
            root = root->right;
        } 
        // if the root is the lowest common ancestor, break
        else {
            break;
        }
    }
    // return the lowest common ancestor
    return root;
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
    // take the two nodes
    cout << "Enter the two nodes: ";
    int a, b;
    cin >> a >> b;
    // find the lowest common ancestor
    TreeNode* lca = LCA(root, a, b);
    // print the lowest common ancestor
    cout << "The LCA of " << a << " and " << b << " is " << lca->data << endl;
    return 0;
}

// Time Complexity: O(h) - because we are traversing the tree once
// Space Complexity: O(1) - because we are not using any extra space
