#include <iostream>
#include <vector>
#include <algorithm>
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

// inorder traversal
void inorderTraversal(TreeNode* root, vector<int>& arr){
    // if the root is nullptr, return
	if(!root) return;
    // traverse the left subtree
	inorderTraversal(root->left, arr);
    // add the value of the root to the array
	arr.push_back(root->val);
    // traverse the right subtree
	inorderTraversal(root->right, arr);
}

// find the pair
bool findPair(TreeNode* root, int k){
    // if the root is nullptr, return false
	if(!root) return false;
    // create an array to store the inorder traversal
	vector<int> arr;
	inorderTraversal(root, arr);
    // create two pointers to find the pair
	int left = 0;
	int right = arr.size()-1;
    // traverse the array
	while(left<right){
        // calculate the sum of the two pointers
		int sum = arr[left]+arr[right];
        // if the sum is equal to the target, return true
		if(sum == k) return true;
        // if the sum is less than the target, move the left pointer to the right
		else if(sum < k) left++;
        // if the sum is greater than the target, move the right pointer to the left
		else right--;
	}
    // if the pair is not found, return false
	return false;
}

int main(){
    // take the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    // take the array
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // create the tree
    TreeNode* root = createTree(arr, 0);
    // take the target sum
    int target;
    cout << "Enter the target sum: ";
    cin >> target;
    // check if the pair exists
    if(findPair(root, target)){
        cout << "Pair exists" << endl;
    }
    else{
        cout << "Pair does not exist" << endl;
    }
    return 0;
}

// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(n) for the inorder traversal array