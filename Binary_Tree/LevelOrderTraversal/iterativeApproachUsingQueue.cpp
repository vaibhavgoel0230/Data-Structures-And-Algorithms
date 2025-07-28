#include <iostream>
#include <vector>
#include <queue>

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

// function to create the tree from the array
TreeNode* createTree(vector<int>& arr, int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >= n || arr[index] == -1) return NULL;
    // create the root node
    TreeNode* root = new TreeNode(arr[index]);
    // create the left and right children of the root node
    root->left = createTree(arr, 2*index + 1, n);
    root->right = createTree(arr, 2*index + 2, n);
    // return the root node
    return root;
}

// function to print the result
void print(vector<vector<int>>& result){
    // print the result
    cout << "Level Order Traversal: [";
    // iterate through the result
    for(int i=0; i<result.size(); i++){
        // print the current level
        cout << "[";
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

// function to perform level order traversal
vector<vector<int>> levelOrderTraversal(TreeNode* root){
    // result vector to store the level order traversal
    vector<vector<int>> result;
    // if the root is NULL, return the result
    if(!root) return result;
    // queue to store the nodes
    queue<TreeNode*> q;
    // push the root node into the queue
    q.push(root);
    // while the queue is not empty
    while(!q.empty()){
        // get the size of the current level
        int levelSize = q.size();
        // vector to store the nodes of the current level
        vector<int> level;
        // iterate through the nodes of the current level
        for(int i=0; i<levelSize; i++){
            // get the front node of the queue
            TreeNode* node = q.front();
            // pop the front node from the queue
            q.pop();
            // add the value of the node to the level vector
            level.push_back(node->val);
            // if the left child of the node exists, push it into the queue
            if(node->left) q.push(node->left);
            // if the right child of the node exists, push it into the queue
            if(node->right) q.push(node->right);
        }
        // add the level vector to the result
        result.push_back(level);
    }
    // return the result
    return result;
}

// main function
int main(){
    // number of elements in the array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    // array to store the elements of the tree
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++) cin >> arr[i];
    // create the tree from the array
    TreeNode* root = createTree(arr, 0, n);
    // perform the level order traversal
    vector<vector<int>> result = levelOrderTraversal(root);
    // print the result
    print(result);
    // return 0 to indicate successful execution
    return 0;
}

// Time Complexity: O(n) - each node is processed exactly once
// Space Complexity: O(n) - uses a queue to store the nodes and at most n/2 nodes can be present in the queue at any level