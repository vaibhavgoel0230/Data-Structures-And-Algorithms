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
bool isValidBST(TreeNode* root){
    TreeNode* curr = root;
    TreeNode* pred;

    // traverse the tree
    while(curr != NULL){
        // if the left child is NULL, then we are at the leftmost node
        if(curr->left == NULL){
            // if the predecessor is not NULL and the predecessor's data is greater than or equal to the current node's data, then the tree is not a BST
            if(pred != NULL && pred->data >= curr->data){
                return false;
            }
            pred = curr;
            curr = curr->right;
        }
        else{
            // if the left child is not NULL, then we need to find the inorder predecessor
            TreeNode* temp = curr->left;
            while(temp->right != NULL && temp->right != curr){
                temp = temp->right;
            }
            // if the right child of the predecessor is NULL, then we need to make the right child of the predecessor point to the current node
            if(temp->right == NULL){
                // make the right child of the predecessor point to the current node
                temp->right = curr;
                // move to the left child
                curr = curr->left;
            }
            else{
                // if the right child of the predecessor is not NULL, then we need to make the right child of the predecessor point to NULL
                temp->right = NULL;
                // if the predecessor is not NULL and the predecessor's data is greater than or equal to the current node's data, then the tree is not a BST
                if(pred != NULL && pred->data >= curr->data){
                    return false;
                }
                // update the predecessor
                pred = curr;
                // move to the right child
                curr = curr->right;
            }
        }
    }
    return true;
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
    if(isValidBST(root)){
        cout << "The tree is a valid BST" << endl;
    }
    else{
        cout << "The tree is not a valid BST" << endl;
    }

    return 0;
}  

// Time Complexity: O(n) - because we are traversing the tree once
// Space Complexity: O(1) - because we are not using any extra space
