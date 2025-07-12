#include <iostream>
#include <vector>
using namespace std;

// TreeNode structure
struct TreeNode{
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

    return root;
}

// inorderTraversal function
void inorderTraversal(TreeNode* root, vector<int> & inorderArr){
    // BASE CASE: if the root is NULL, return
    if(root == NULL) return;

    // create the current node
    TreeNode* curr = root;

    // traverse the tree
    while(curr){
        // if the left child is NULL, add the value to the inorderArr and move to the right child
        if(curr->left == NULL){
            inorderArr.push_back(curr->val);
            curr = curr->right;
        }
        // if the left child is not NULL, find the predecessor
        else{
            TreeNode* prev = curr->left;
            // find the predecessor
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }

            // if the predecessor is NULL, make the current node the right child of the predecessor
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            // if the predecessor is not NULL, add the value to the inorderArr and move to the right child
            else{
                prev->right = NULL;
                inorderArr.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
}

// print function
void print(vector<int> printArr){
    // print the inorderArr
    for(int i=0; i<printArr.size(); i++){
        cout << printArr[i] << " ";
    }

    cout << endl;
}

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

    // create the inorderArr
    vector<int> inorderArr;

    // perform the inorder traversal
    inorderTraversal(root, inorderArr);

    // print the inorderArr
    print(inorderArr);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)