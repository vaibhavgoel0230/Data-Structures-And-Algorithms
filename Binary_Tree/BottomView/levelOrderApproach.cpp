#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// TreeNode structure
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// function to create the tree
TreeNode* createTree(int arr[], int index, int n){
    // if the index is greater than or equal to the number of nodes or the value is -1, return NULL
    if(index >= n || arr[index] == -1) return NULL;
    // create the root node
    TreeNode* root = new TreeNode(arr[index]);
    // create the left and right subtrees
    root->left = createTree(arr, 2*index+1, n);
    root->right = createTree(arr, 2*index+2, n);
    // return the root node
    return root;
}

// function to print the results
void print(vector<int>& results){
    // print the results
    for(int i=0; i<results.size(); i++){
        cout << results[i] << " ";
    }

    cout << endl;
}

// function to get the bottom view of the tree
vector<int> bottomView(TreeNode* root){
    // if the root is NULL, return an empty vector
    vector<int> results;
    if(!root) return results;

    // map to store the vertical order of the nodes
    map<int,int> verticalOrder;

    // queue to store the nodes and their vertical levels
    queue<pair<TreeNode*, int>> q;
    // push the root node and its vertical level
    q.push({root, 0});

    // while the queue is not empty
    while(!q.empty()){
        // get the size of the current level
        int levelSize = q.size();
        // iterate through the nodes in the current level
        for(int i=0; i<levelSize; i++){
            // get the node and its vertical level
            auto [node, currLevel] = q.front();
            // add the node to the vertical order map
            verticalOrder[currLevel] = node->val;
            // push the left and right children of the node to the queue
            if(node->left) q.push({node->left, currLevel-1});
            if(node->right) q.push({node->right, currLevel+1});
            // pop the current node from the queue
            q.pop();
        }
    }

    // iterate through the vertical order map and add the values to the results vector
    for(auto [level, val] : verticalOrder){
        results.push_back(val);
    }

    // return the results vector
    return results;
}

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

    // get the bottom view of the tree
    vector<int> results = bottomView(root);

    // print the bottom view
    print(results);

    return 0;
}

/*
    Time Complexity: O(n) - this complexity is due to the fact that we are traversing each node in the tree level by level exactly once
    Space Complexity: O(n/2 + n/2) -
    1. O(n/2) for the queue - for the balanced tree, the queue will have at most n/2 elements at any level which is the maximum width of the tree
    2. O(n/2) for the map - the map is used to store the vertical order of the nodes and the number of elements in the map can at most be n/2 for the balanced tree
*/