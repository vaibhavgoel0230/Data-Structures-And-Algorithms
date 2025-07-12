#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// TreeNode structure
struct TreeNode{
    // value of the node
    int val;
    // left child of the node
    TreeNode* left;
    // right child of the node
    TreeNode* right;
    // constructor for the TreeNode
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// function to create the tree
TreeNode* createTree(vector<int>& arr, int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >= n || arr[index] == -1) return NULL;
    // create the root node
    TreeNode* root = new TreeNode(arr[index]);
    // create the left child of the root node
    root->left = createTree(arr, 2*index+1, n);
    // create the right child of the root node
    root->right = createTree(arr, 2*index+2, n);
    // return the root node
    return root;
}

// function to get the vertical order traversal of the tree
vector<vector<int>> verticalOrderTraversal(TreeNode* root){
    // results vector to store the vertical order traversal
    vector<vector<int>> results;
    if(!root) return results;

    // map to store the vertical order traversal
    map<int, map<int, vector<int>>> verticalOrder;

    // queue to store the nodes and their vertical and horizontal distances
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    // while the queue is not empty
    while(!q.empty()){
        // get the node and its vertical and horizontal distances
        TreeNode* node = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        // store the node in the map
        verticalOrder[x][y].push_back(node->val);

        // push the left and right children of the node to the queue
        if(node->left) q.push({node->left, {x-1, y+1}});
        if(node->right) q.push({node->right, {x+1, y+1}});
    }

    // iterate through the map
    for(auto& it : verticalOrder){
        vector<int> temp;
        for(auto& it2 : it.second){
            // sort the nodes in the map
            sort(it2.second.begin(), it2.second.end());
            // store the nodes in the temp vector
            for(auto& it3 : it2.second){
                temp.push_back(it3);
            }
        }
        // store the temp vector in the results vector
        results.push_back(temp);
    }
    // return the results vector
    return results;
}

// function to print the results
void print(vector<vector<int>>& results){
    // print the results
    cout << "Vertical Order Traversal: [";
    for(int i = 0; i < results.size(); i++){
        cout << "[";
        for(int j = 0; j < results[i].size(); j++) cout << results[i][j] << " ";
        cout << "]";
    }
    cout << "]" << endl;
}

int main(){
    // create the tree
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;
    // create the array
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    // create the tree
    TreeNode* root = createTree(arr, 0, n);

    // get the vertical order traversal of the tree
    vector<vector<int>> results = verticalOrderTraversal(root);

    // print the vertical order traversal
    print(results);

    return 0;
}

/*
    Time Complexity: O(n * log2(n) * log2(n) * log2(n))
    - traversal using BFS (queue) : O(n)
    - insertion into map, uses balanced BST, so each x and y lookup is O(log2(n)). since we are inserting n nodes, so O(n * log2(n) * log2(n))
    -sorting per(x,y) group: O(n * log2(n))
    - total: O(n * log2(n) * log2(n) * log2(n))
    Space Complexity: O(n + n/2)
    - queue stores upto n/2 nodes representing the nodes at the current level - O(n/2)
    - map stores all nodes for actual values - O(n)
    - total: O(n + n/2)
*/