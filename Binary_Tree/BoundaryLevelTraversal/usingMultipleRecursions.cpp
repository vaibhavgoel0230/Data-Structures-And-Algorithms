#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

// function to check if the node is a leaf
bool isLeave(Node* root){
	return !root->left && !root->right;
}

// function to find the left boundary of the tree
void leftBoundary(Node* root, vector<int>& result){
    // if the root is NULL, return
	if(!root) return;
	
    // create a pointer to the left child of the root
	Node* curr = root->left;
	
    // while the current node is not NULL
	while(curr){
        // if the current node is not a leaf, add it to the result
		if(!isLeave(curr)){
			result.push_back(curr->data);
		}

        // if the left child is not NULL, move to the left child
		if(curr->left){
			curr = curr->left;
		} else{
            // if the left child is NULL, move to the right child
			curr = curr->right;
		} 
	}
}

// function to find the right boundary of the tree
void rightBoundary(Node* root, vector<int>& result){
    // if the root is NULL, return
	Node* curr = root->right;
	vector<int> temp;
    
    // while the current node is not NULL
	while(curr){
        // if the current node is not a leaf, add it to the result
		if(!isLeave(curr)){
            // add the current node to the temporary vector
			temp.push_back(curr->data);
		}
        
        // if the left child is not NULL, move to the left child
		if(curr->left){
			curr = curr->left;
		} else{
            // if the left child is NULL, move to the right child
			curr = curr->right;
		}
	}

    // reverse the temporary vector
	reverse(temp.begin(), temp.end());
    
    // add the temporary vector to the result
	result.insert(result.end(), temp.begin(), temp.end());
}

// function to find the bottom boundary of the tree
void bottomBoundary(Node* root, vector<int>& result){
    // if the root is NULL, return
	if(isLeave(root)){
        // add the current node to the result
		result.push_back(root->data);
		return;
	}

    // if the left child is not NULL, move to the left child
	if(root->left) bottomBoundary(root->left, result);
    
    // if the right child is not NULL, move to the right child
	if(root->right) bottomBoundary(root->right, result);			
}

// function to print the boundary level traversal of the tree
void printBoundary(vector<int> result){
    // print the result
	cout << "[ "; 
    // iterate through the result
	for(int j=0; j<result.size(); j++){
        // print the current node
        cout << result[j] << ' ';
	}
    // print the closing bracket of the result
	cout << "]" << endl;
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

    // build the trees
    Node* root = buildTree(nodes, 0, n);
    
    // create a vector to store the result
    vector<int> result;

    // if the root is not NULL
    if(root){
        // if the root is not a leaf, add it to the result
        if(!isLeave(root)){
            // add the root to the result
            result.push_back(root->data);
        }
        // find the left boundary
        leftBoundary(root, result);
        // find the bottom boundary
        bottomBoundary(root, result);
        // find the right boundary
        rightBoundary(root, result);
    }

    // print the boundary level traversal of the tree
    printBoundary(result);

    return 0;
}

/*
    Time Complexity: O(n) - where n is the number of nodes in the tree
    - Adding the left boundary takes O(n) time
    - Adding the bottom boundary takes O(n) time
    - Adding the right boundary takes O(n) time
    - The total time complexity is O(n)

    Space Complexity: O(n) - where n is the number of nodes in the tree and the recursive stack space is O(h) where h is the height of the tree
    and in the worst case where the tree is skewed, the height of the tree can be n hence the space complexity is O(n).
    
*/