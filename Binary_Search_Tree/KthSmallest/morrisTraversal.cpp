#include <iostream>
#include <vector>
using namespace std;

// TreeNode class
class TreeNode{
    public:
    // data
    int val;
    // left and right pointers
    TreeNode* left;
    TreeNode* right;
    // constructor
    TreeNode(int val){
        this->val = val;
        left = right = nullptr;
    }
};

// createTree function to create the tree from the array
TreeNode* createTree(vector<int>& arr, int index){
    // if index is out of bounds or the value is -1, return nullptr
    if(index >= arr.size() || arr[index] == -1){
        return nullptr;
    }
    // create the root node
    TreeNode* root = new TreeNode(arr[index]);
    // create the left and right subtrees
    root->left = createTree(arr, 2*index + 1);
    root->right = createTree(arr, 2*index + 2);
    return root;
}

// kthSmallest function to find the kth smallest element in the tree
int kthSmallest(TreeNode* root, int k){
    // if the root is nullptr, return -1
    if(root == nullptr){
        return -1;
    }
    // initialize the count
    int count = 0;
    // initialize the current node
    TreeNode* curr = root;
    // traverse the tree
    while(curr != nullptr){
        // if the left child is nullptr, increment the count and return the value
        if(!curr->left){
            count++;
            // if the count is equal to k, return the value
            if(count == k){
                return curr->val;
            }
            // move to the right child
            curr = curr->right;
        }
        // if the left child is not nullptr, find the predecessor
        else{
            TreeNode* pred = curr->left;
            // find the predecessor
            while(pred->right != nullptr && pred->right != curr){
                pred = pred->right;
            }
            // if the right child of the predecessor is nullptr, make it the current node and move to the left child
            if(pred->right == nullptr){
                pred->right = curr;
                curr = curr->left;
            }
            // if the right child of the predecessor is the current node, make it nullptr, increment the count and return the value 
            // if the count is equal to k, or move to the right child
            else{
                pred->right = nullptr;
                count++;
                if(count == k){
                    return curr->val;
                }
                curr = curr->right;
            }
        }
    }  
    return -1;
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
    // create the tree
    TreeNode* root = createTree(arr, 0);
    // take the kth smallest element
    cout << "Enter the kth smallest element: ";
    int k;
    cin >> k;
    // print the kth smallest element
    cout << "The " << k << "th smallest element is: " << kthSmallest(root, k) << endl;
    return 0;
}

// Time Complexity: O(n) - because we are traversing the tree once
// Space Complexity: O(1) - because we are not using any extra space


