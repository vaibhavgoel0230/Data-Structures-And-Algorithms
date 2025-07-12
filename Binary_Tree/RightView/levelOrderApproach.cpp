#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Treenode class
struct TreeNode{
    // value of the node
    int val;
    // left child of the node
    TreeNode* left;
    // right child of the node
    TreeNode* right;

    // constructor
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

// function to create the tree
TreeNode* createTree(int arr[], int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >=n || arr[index] == -1){
        return NULL;
    }

    // create the root node
    TreeNode* root = new TreeNode(arr[index]);
    // create the left and right subtrees
    root->left = createTree(arr, 2*index+1, n);
    root->right = createTree(arr, 2*index+2, n);

    return root;
}

// function to get the right view of the tree
vector<int> rightView(TreeNode* root){
    // result vector to store the right view
    vector<int> results = {};
    // if the root is NULL, return the empty result vector
    if(!root) return results;

    // queue to perform level order traversal
    queue<TreeNode*> q;
    // push the root node into the queue
    q.push(root);
    // perform level order traversal
    // Start the loop until the queue is empty
    while(!q.empty()){
        // get the number of nodes at the current level
        int levelSize = q.size();
        // traverse all the nodes at the current level
        for(int i=0; i<levelSize; i++ ){
            TreeNode* node = q.front();
            // if it is the last node at the current level, add it to the result vector
            if(i==levelSize-1) results.push_back(node->val);
            // push the left and right children of the current node into the queue
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            // remove the current node from the queue
            q.pop();
        }
    }

    // return the result vector
    return results;
}

// function to print the result vector
void print(vector<int> &results){
    // traverse the result vector and print the values
    for(int i=0; i<results.size(); i++){
        cout << results[i] << " ";
    }

    cout << endl;
}

// main function
int main(){
    // get the number of nodes in the tree
    cout << "Enter the number of nodes in the tree: ";
    int n;
    cin >> n;

    // get the values of the nodes
    cout << "Enter the values of the nodes: ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // create the tree
    TreeNode* root = createTree(arr, 0, n);

    // get the right view of the tree
    vector<int> results = rightView(root);

    // print the right view
    print(results);

    // return 0
    return 0;
}

/*

Time Complexity: O(n) - As we are traversing on each node of the tree level by level, enqueueing and dequeueing each node once. Hence, the time complexity is O(n).
Space Complexity: O(n) - We are using a queue to store the nodes at the current level. And, The maximum number of nodes that can be stored in the queue is n/2 as the last level of the tree can have at most n/2 nodes. Hence, the space complexity is O(n).

*/