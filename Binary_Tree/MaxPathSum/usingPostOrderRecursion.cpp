#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// define the Node structure
struct Node{
    // value of the node
    int data;
    // left child of the node
    Node* left;
    // right child of the node
    Node* right;

    // constructor to initialize the node
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// function to build the tree
Node* buildTree(vector<int> &nodes, int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if((index>=n) || (nodes[index] == -1)) return NULL;
    // create the root node
    Node* root = new Node(nodes[index]);
    // create the left and right subtrees
    root->left = buildTree(nodes, 2*index+1, n);
    root->right = buildTree(nodes, 2*index+2, n);
    // return the root node
    return root;
}

// function to find the Maximum Path Sum of the tree
int findMaxPathSum(Node* root, int& maxi){
    // if the root is NULL, return 0
	if(!root) return 0;
	
    // find the maximum path sum of the left and right subtrees
	int leftMax = max(0,findMaxPathSum(root->left, maxi));
	int rightMax = max(0,findMaxPathSum(root->right, maxi));
	
    // update the maximum path sum
	maxi = max(maxi, leftMax + rightMax + root->data);
	
    // return the maximum path sum of the current node
	return max(leftMax + root->data, rightMax + root->data);
}

int main(){
    // input the number of nodes in the tree
    cout << "Enter the number of nodes in the tree: ";
    int n;
    cin >> n;

    // input the nodes of the tree
    cout << "Enter the nodes of the tree: ";
    vector<int> nodes(n);
    for(int i = 0; i < n; i++){
        cin >> nodes[i];
    }

    // build the tree
    Node* root = buildTree(nodes, 0, n);
    
    // find the max path sum of the tree
    int maxPathSum = INT_MIN;
    // call the function to find the max path sum
    findMaxPathSum(root, maxPathSum);

    // print the max path sum of the tree
    cout << "The max path sum of the tree is: " << maxPathSum << endl;
    return 0;
}

/*
    Time Complexity: O(n) - where n is the number of nodes in the tree
    - the complexity arises from the fact that we are traversing the tree only once

    Space Complexity: O(1) - because we are not using any extra space/data structure
    - the recursive stack space is O(h) where h is the height of the tree
    - in the worst case where the tree is skewed, the height of the tree can be n hence the space complexity is O(n)
*/