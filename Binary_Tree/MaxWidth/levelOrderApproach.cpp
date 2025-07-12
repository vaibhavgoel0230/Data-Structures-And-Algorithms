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

// function to create the tree
TreeNode* createTree(vector<int>& arr, int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >= n || arr[index] == -1) return NULL;

    // create the root node
    TreeNode* root = new TreeNode(arr[index]);

    // create the left child of the root node
    root->left = createTree(arr, 2*index + 1, n);

    // create the right child of the root node
    root->right = createTree(arr, 2*index + 2, n);

    // return the root node
    return root;
}

// function to get the max width of the tree
int maxWidthOfTree(TreeNode* root){
    // if the root is NULL, return 0
    if(!root) return 0;

    // initialize the answer to 0
    int ans = 0;

    // create a queue to store the nodes and their indices
    queue<pair<TreeNode*, long long>> q;

    // push the root node and its index to the queue
    q.push({root, 0});

    while(!q.empty()){
        // get the size of the current level
        int levelSize = q.size();

        // get the minimum index of the current level
        long long minIndex = q.front().second;

        // initialize the first and last indices of the current level
        int first, last;

        // iterate through the current level
        for(int i=0; i<levelSize; i++){
            // get the node and its index
            auto [node, index] = q.front();

            // adjust the index to the minimum index of the current level
            index -= minIndex;

            // if the current node is the first node in the level, set the first index
            if(i==0) first = index;

            // if the current node is the last node in the level, set the last index
            if(i==levelSize-1) last = index;

            // push the left and right children of the current node to the queue
            if(node->left) q.push({node->left, 2*index + 1});
            if(node->right) q.push({node->right, 2*index + 2});

            // pop the current node from the queue
            q.pop();
        }

        // update the answer with the width of the current level
        ans = max(ans, last-first+1);
    }

    // return the answer
    return ans;
}

int main(){
    // get the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    // create the array
    vector<int> arr(n);
    // get the elements of the array
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    // create the tree
    TreeNode* root = createTree(arr, 0, n);

    // get the max width of the tree
    int maxWidth = maxWidthOfTree(root);

    // print the max width
    cout << "The max width of the tree is: " << maxWidth << endl;
}

// Time Complexity: O(n) - We traverse each node once
// Space Complexity: O(n) - We use a queue to store the nodes. It can have at most n/2 nodes at any level.