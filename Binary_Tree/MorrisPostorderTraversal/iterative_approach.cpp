#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// TreeNode class
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

// function to create the tree
TreeNode* createTree(int arr[], int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >= n || arr[index] == -1){
        return NULL;
    }

    // create the root node
    TreeNode* root = new TreeNode(arr[index]);

    // create the left and right subtrees
    root->left = createTree(arr, 2*index+1, n);
    root->right = createTree(arr, 2*index+2, n);

    return root;
}

// function to perform postorder traversal
vector<int> postorderTraversal(TreeNode* root){
    // if the root is NULL, return an empty vector  
    if(root == NULL){
        return {};
    }

    // create a current pointer to traverse the tree
    TreeNode* curr = root;
    // create a result vector to store the postorder traversal
    vector<int> result;

    // traverse the tree
    while(curr){
        // if the right child is NULL, add the value to the result vector and move to the left child
        if(curr->right == NULL){
            result.push_back(curr->val);
            curr = curr->left;
        }
        // if the right child is not NULL, find the predecessor
        else{
            TreeNode* prev = curr->right;
            // find the predecessor
            while(prev->left && prev->left!=curr){
                prev = prev->left;
            }
            // if the predecessor is NULL, add the value to the result vector and move to the right child
            if(prev->left == NULL){
                prev->left = curr;
                result.push_back(curr->val);
                curr = curr->right;
            }
            // if the predecessor is not NULL, set the left child to NULL and move to the left child
            else{
                prev->left = NULL;
                curr = curr->left;
            }
        }
    }

    // reverse the result vector to get the postorder traversal
    reverse(result.begin(), result.end());
    return result;
}

// function to print the result vector
void print(vector<int> result){
    // print the result vector
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

// main function
int main(){
    // take the input from the user
    cout << "Enter the number of nodes in the tree: ";
    int n;
    cin >> n;

    // create an array to store the values of the nodes
    cout << "Enter the values of the nodes: ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // create the tree
    TreeNode* root = createTree(arr, 0, n);

    // perform the postorder traversal
    vector<int> result = postorderTraversal(root);

    // print the result
    cout << "Postorder Traversal: ";
    print(result);

    return 0;
}

/*
    Time Complexity: O(n) - We traverse the tree twice, once to find the predecessor and once to reverse the result vector
    Space Complexity: O(1) - We use a constant amount of extra space
*/