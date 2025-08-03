#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <sstream>
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

// serialize the tree
string serialize(TreeNode* root){
	// if the root is nullptr, return "null"
	if(!root) return "null";
	
	// queue to store the nodes
	queue<TreeNode*> q;

	// string to store the serialized tree
	string st;

	// push the root node
	q.push(root);
	
	// iterate over the nodes
	while(!q.empty()){
		// get the front node
		TreeNode* node = q.front();
		// pop the front node
		q.pop();

		// if the node is not nullptr, add the value to the string and push the left and right children to the queue
		if(node){
			st += to_string(node->val) + ",";
			q.push(node->left);
			q.push(node->right);
		} 
		// if the node is nullptr, add "null" to the string
		else{
			st += "null,";
		}
	}
	
	// return the serialized tree
	return st;
}

// deserialize the tree
TreeNode* deserialize(string data){
	// if the data is "null", return nullptr
	if(data == "null") return NULL;

	// stringstream to store the data
	stringstream ss(data);

	// token to store the current token
	string token;

	// get the first token
	getline(ss, token, ',');
	
	// create the root node
	TreeNode* root = new TreeNode(stoi(token));
	
	// queue to store the nodes
	queue<TreeNode*> q;

	// push the root node
	q.push(root);
	
	// iterate over the nodes
	while(!q.empty()){
		// get the front node
		TreeNode* node = q.front();
		// pop the front node
		q.pop();

		// get the next token
		if(!getline(ss, token, ',')) break;

		// if the token is not "null", create the left child and push it to the queue
		if(token != "null"){
			node->left = new TreeNode(stoi(token));
			q.push(node->left);
		}

		// get the next token
		if(!getline(ss, token, ',')) break;

		// if the token is not "null", create the right child and push it to the queue
		if(token != "null"){
			node->right = new TreeNode(stoi(token));
			q.push(node->right);
		}
	}
	
	// return the root node
	return root;
}

void levelOrderTraversal(TreeNode* root){
	// if the root is nullptr, return
	if(!root) return;
	
	// queue to store the nodes
	queue<TreeNode*> q;

	// push the root node
	q.push(root);

	// iterate over the nodes
	while(!q.empty()){
		// get the front node
		TreeNode* node = q.front();
		// pop the front node
		q.pop();
        
        cout << node->val << " ";

		// if the left child is not nullptr, push it to the queue
		if(node->left) q.push(node->left);

		// if the right child is not nullptr, push it to the queue
		if(node->right) q.push(node->right);
	}

    // print a new line
    cout << endl;
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
    // serialize the tree
    string serializedTree = serialize(root);
    // deserialize the tree
    TreeNode* deserializedTree = deserialize(serializedTree);
    // print the serialized tree
    cout << "The serialized tree is: " << serializedTree << endl;
    // print the deserialized tree
    cout << "The deserialized tree is: ";
    levelOrderTraversal(deserializedTree);

    return 0;
}

// Time Complexity: O(n) - because we are traversing the entire tree once
// Space Complexity: O(n) - because we are using a queue to store the nodes
