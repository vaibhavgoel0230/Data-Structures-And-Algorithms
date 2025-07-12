#include <iostream>
#include <vector>

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
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
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

// function to get the path in a tree
bool pathInATree(TreeNode* root, vector<int>& results, int target){
    // if the root is NULL, return false
    if(!root) return false;

    // push the value of the root to the results vector
    results.push_back(root->val);

    // if the value of the root is the target, return true
    if(root->val == target) return true;

    // if the path is found in the left or right subtree, return true
    if(pathInATree(root->left, results, target) || pathInATree(root->right, results, target)) return true;

    // if the path is not found, pop the value of the root from the results vector
    results.pop_back();

    // return false
    return false;
}

// function to print the results
void print(vector<int>& results){
    cout << "Path in a Tree:";
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << " ";
    }
    cout << endl;
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
    // get the target value
    cout << "Enter the target value: ";
    int target;
    cin >> target;

    // create the tree
    TreeNode* root = createTree(arr, 0, n);

    // get the path in a tree
    vector<int> results;
    pathInATree(root, results, target);

    // print the results
    print(results);

    return 0;
}

/*
    Time Complexity: O(n)
    - we traverse the tree once, so O(n)
    Space Complexity: O(n)
    - the recursive stack space is O(n)
*/
