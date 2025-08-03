#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// TreeNode class
class TreeNode{
    public:
    // value of the node
    int val;
    // left child
    TreeNode* left;
    // right child
    TreeNode* right;
    // constructor
    TreeNode(int val){
        this->val = val;
        left = right = nullptr;
    }
};

// create the tree
TreeNode* createTree(vector<int>& arr, int index){
    // if the index is out of bounds or the value is -1, return nullptr
    if(index >= arr.size() || arr[index] == -1){
        return nullptr;
    }
    // create the root node
    TreeNode* root = new TreeNode(arr[index]);
    // create the left child
    root->left = createTree(arr, 2*index + 1);
    // create the right child
    root->right = createTree(arr, 2*index + 2);
    // return the root node
    return root;
}

// BTNode class
class BTNode{
    public:
	// sum of the BST
	int sum;
	// if the BST is valid
	bool isBST;
	// maximum value in the BST
	int max;
	// minimum value in the BST
	int min;
	// constructor
	BTNode(){
		sum=0;
		isBST=true;
		max=INT_MIN;
		min=INT_MAX;
	}
};

// helper function to find the maximum sum of the BST
BTNode* maxSumBSTHelper(TreeNode* root, int& maxim){
	// if the root is nullptr, return a new BTNode
	if(!root) return new BTNode();
	
	// recursive call to the left child
	BTNode* leftNode = maxSumBSTHelper(root->left, maxim);

	// recursive call to the right child
	BTNode* rightNode = maxSumBSTHelper(root->right, maxim);

	// create a new BTNode
	BTNode* currNode = new BTNode();

	// update the sum of the BST
	currNode->sum = root->val + leftNode->sum + rightNode->sum;

	// update the maximum value in the BST
	currNode->max = max(root->val, rightNode->max);

	// update the minimum value in the BST
	currNode->min = min(root->val, leftNode->min);

	// update the BST is valid
	// if the left and right subtrees are valid BSTs and the root value is greater than the maximum value in the left subtree and less than the minimum value in the right subtree, then the BST is valid
	currNode->isBST = (leftNode->isBST && rightNode->isBST) && (root->val > leftNode->max) && (root->val < rightNode->min);
	
	// update the maximum sum of the BST
	if(currNode->isBST) maxim = max(maxim, currNode->sum);

	// return the current node
	return currNode;
}

// function to find the maximum sum of the BST
int maxSumBST(TreeNode* root){
	// maximum sum of the BST
	int maxim = 0;
	// helper function to find the maximum sum of the BST
	maxSumBSTHelper(root, maxim);
	// return the maximum sum of the BST
	return maxim;
}

int main(){
    // take the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    // take the array
    cout << "Enter the elements of the array: ";
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // create the tree
    TreeNode* root = createTree(arr, 0);
    // find the maximum sum of the BST
    cout << "The maximum sum of the BST is: " << maxSumBST(root) << endl;
    return 0;
}

// Time Complexity: O(n) - because we are traversing the entire tree once
// Space Complexity: O(h) - because we are using a recursive stack space