#include <iostream>
#include <vector>
#include <stack>
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
int kthSmallest(TreeNode* root, int k, int& count){
    // if the root is nullptr, return -1
    if(root == nullptr){
        return -1;
    }

    // traverse the left subtree
    int leftResult = kthSmallest(root->left, k, count);
    if(leftResult != -1){
        return leftResult;
    }

    // increment the count
    count++;
    // if the count is equal to k, return the value of the root
    if(count == k){
        return root->val;
    }

    // traverse the right subtree
    return kthSmallest(root->right, k, count);
}

// main function
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

    int count = 0;
    int result = kthSmallest(root, k, count);
    // print the kth smallest element
    cout << "The " << k << "th smallest element is: " << result << endl;
    return 0;
}

// Time Complexity: O(n) - because we are traversing the tree once
// Space Complexity: O(n) - because we are using a stack to store the nodes