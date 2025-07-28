#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// define the TreeNode structure
struct TreeNode{
    // value of the node
    int val;
    // left child of the node
    TreeNode* left;
    // right child of the node
    TreeNode* right;
    // constructor to initialize the node
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// function to convert the inorder and postorder arrays to a binary tree
TreeNode* convertToTree(
	vector<int>& inorder,
	int inStart,
	int inEnd,
	vector<int>& postorder,
	int postStart,
	int postEnd,
	map<int, int>& inMap
){
    // if the inStart is greater than inEnd or postStart is greater than postEnd, return NULL
	if( inStart>inEnd || postStart>postEnd ) return NULL;

    // find the index of the root node in the inorder array
	int inRoot = inMap[postorder[postEnd]];

    // find the number of nodes in the left subtree
	int numsLeft = inRoot-inStart;
	
    // convert the left subtree
	TreeNode* leftNode = convertToTree(
		inorder,
		inStart,
		inRoot-1,
		postorder,
		postStart,
		postStart+numsLeft-1,
		inMap
	);

    // convert the right subtree
	TreeNode* rightNode = convertToTree(
		inorder,
		inRoot+1,
		inEnd,
		postorder,
		postStart+numsLeft,
		postEnd-1,
		inMap
	);

    // create the root node
	TreeNode* root = new TreeNode(postorder[postEnd]);
    // set the left and right children of the root node
	root->left = leftNode;
	root->right = rightNode;
    // return the root node
	return root;
}

// function to print the tree
void printTree(TreeNode* root){
    // if the root is NULL, return
    if(!root) return;
    // print the left child of the root node
    printTree(root->left);
    // print the right child of the root node
    printTree(root->right);
    // print the root node
    cout << root->val << " ";
}

int main(){
    // number of elements in the array
    int n;
    cout << "Enter the number of elements in the arrays: ";
    cin >> n;
    // array to store the elements of the tree
    vector<int> inorder(n);
    cout << "Enter the elements of the inorder array: ";
    for(int i=0; i<n; i++) cin >> inorder[i];

    // array to store the elements of the tree
    vector<int> postorder(n);
    cout << "Enter the elements of the postorder array: ";
    for(int i=0; i<n; i++) cin >> postorder[i];

    map<int, int> inMap;
    for(int i=0; i<n; i++) inMap[inorder[i]] = i;

    // find the maximum height of the tree
    TreeNode* root = convertToTree(
        inorder,
        0,
        n-1,
        postorder,
        0,
        n-1,
        inMap
    );
    
    // print the tree
    cout << "The postorder traversal of the tree is: ";
    printTree(root);
    cout << endl;

    // return 0 to indicate successful execution
    return 0;
}

// Time Complexity: O(n) - each node is processed exactly once
// Space Complexity: O(n) - inMap uses O(n) space, the recursive stack uses O(h) space, where h is the height of the tree, in the worst case where the tree is skewed, h can be n, so the space complexity is O(n)