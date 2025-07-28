#include <iostream>
#include <vector>
#include <queue>
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

// function to find the zigzag traversal of the tree
vector<vector<int>> zigZagTraversal(Node* root){
    // if the root is NULL, return an empty vector
	if(!root) return {};
	
    // create a queue to store the nodes
	queue<Node*> q;
    // push the root node into the queue
	q.push(root);
    // create a boolean to check if the traversal is from left to right
	bool leftToRight = true;
	
    // create a vector to store the result
	vector<vector<int>> result;
	
    // while the queue is not empty
	while(!q.empty()){
        // get the size of the current level
		int levelSize = q.size();
        // create a vector to store the nodes of the current level
		vector<int> vec(levelSize);
		
        // iterate through the nodes of the current level
		for(int i=0; i<levelSize; i++){
            // get the front node of the queue
			Node* node = q.front();
            // pop the front node from the queue
			q.pop();
            // get the index of the current node
			int index = leftToRight ? i : levelSize-i-1;
            // store the data of the current node in the vector
			vec[index] = node->data;
            // push the left and right children of the current node into the queue
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		
        // toggle the boolean to check if the traversal is from left to right
		leftToRight = !leftToRight;
        // push the vector into the result
		result.push_back(vec);
	}
    // return the result
	root->left = root->right = NULL; // to avoid memory leak
	return result;
}

// function to print the zigzag traversal of the tree
void printZigZagTraversal(vector<vector<int>> result){
    // print the result
	cout << "[ "; 
    // iterate through the result
	for(int i=0; i<result.size(); i++){
        // print the current level
		cout << "{ ";
        // iterate through the nodes of the current level
		for(int j=0; j<result[i].size(); j++){
            // print the current node
			cout << result[i][j] << ' ';
		}
        // print the closing brace of the current level
		cout << "} ";
	}
    // print the closing bracket of the result
	cout << "]";
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
    
    // Evaluate the zigzag traversal of the tree
    vector<vector<int>> result = zigZagTraversal(root);

    printZigZagTraversal(result);

    return 0;
}

/*
    Time Complexity: O(n) - where n is the number of nodes in the tree and each node is enqueued and dequeued once
    Space Complexity: O(n) - In the worst case, the queue will contain all the nodes at the last level of the tree and 
    the last level can have at most n/2 nodes. The resultant vector will also hold all the nodes of the tree hence the 
    space complexity is O(n).
*/