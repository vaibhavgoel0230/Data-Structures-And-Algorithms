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
    
// ceilInBST function to find the ceil of the target value in the BST
int ceilInBST(TreeNode* root, int target){
    // initialize the ceil value
    int ceil = -1;
    // traverse the tree
    while(root != NULL){
        // if the root is greater than the target, then the ceil is in the left subtree
        if(root->data >= target){
            ceil = root->data;
            root = root->left;
        }
        // if the root is less than the target, then the ceil is in the right subtree
        else{
            root = root->right;
        }
    }
    // return the ceil value
    return ceil;
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

    // take the target value
    cout << "Enter the target value: ";
    int target;
    cin >> target;

    // build the tree
    TreeNode* root = buildTree(arr, 0, n);

    // find the ceil of the target value
    int ceil = ceilInBST(root, target);
    // print the ceil
    cout << "The ceil of " << target << " is " << ceil << endl;
    return 0;
}
 
// Time Complexity: O(h) - because we are traversing the tree once
// Space Complexity: O(1) - because we are not using any extra space
