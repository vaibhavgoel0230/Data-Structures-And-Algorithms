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
    

pair<int,int> predecessorSuccessor(TreeNode* root, int key){
    // initialize the predecessor and successor
    int predecessor = -1;
    int successor = -1;
    
    // traverse the tree
    TreeNode* successorNode = root;
    // find the successor
    while(successorNode != NULL){
        // if the successor is less than or equal to the key, then the successor is in the right subtree
        if(successorNode->data <= key){
            successorNode = successorNode->right;
        }
        // if the successor is greater than the key, then the successor is in the left subtree
        else{
            successor = successorNode->data;
            successorNode = successorNode->left;
        }
    }

    // traverse the tree
    TreeNode* predecessorNode = root;
    // find the predecessor
    while(predecessorNode != NULL){
        // if the predecessor is greater than or equal to the key, then the predecessor is in the left subtree
        if(predecessorNode->data >= key){
            predecessorNode = predecessorNode->left;
        }
        // if the predecessor is less than the key, then the predecessor is in the right subtree
        else{
            predecessor = predecessorNode->data;
            predecessorNode = predecessorNode->right;
        }
    }

    // return the predecessor and successor
    return {predecessor, successor};
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
    // take the key
    cout << "Enter the key: ";
    int key;
    cin >> key;
    // find the predecessor and successor
    pair<int,int> result = predecessorSuccessor(root, key);
    // print the predecessor and successor
    cout << "The predecessor and successor of " << key << " are " << result.first << " and " << result.second << endl;
    return 0;
}

// Time Complexity: O(h) - because we are traversing the tree once
// Space Complexity: O(1) - because we are not using any extra space
