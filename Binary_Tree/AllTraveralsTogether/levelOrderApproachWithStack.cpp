#include <iostream>
#include <vector>
#include <stack>
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

// function to get all the traversals of the tree
void allTraversals(TreeNode* root, vector<int>& preorderResults, vector<int>& inorderResults, vector<int>& postorderResults){

    // if the root is NULL, return
    if(!root) return;

    stack<pair<TreeNode*, int>> s;
    s.push({root, 1});
    
    while(!s.empty()){
        auto [node, currLevel] = s.top();
        s.pop();

        if(currLevel == 1){
            preorderResults.push_back(node->val);
            s.push({node, 2});
            if(node->left) s.push({node->left, 1});
        } else if(currLevel == 2){
            inorderResults.push_back(node->val);
            s.push({node, 3});
            if(node->right) s.push({node->right, 1});
        } else {
            postorderResults.push_back(node->val);
        }
    }
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

    vector<int> preorderResults, inorderResults, postorderResults;

    // get the preorder, inorder and postorder results
    allTraversals(root, preorderResults, inorderResults, postorderResults);

    // print the preorder, inorder and postorder results
    cout << "Preorder results: ";
    print(preorderResults);
    cout << "Inorder results: ";
    print(inorderResults);
    cout << "Postorder results: ";
    print(postorderResults);

    return 0;
}

/*
    Time Complexity: O(3n) - we are traversing each node in the tree level by level exactly once and we are doing this for 3 times
    Space Complexity: O(4n) -
    1. O(n) for the stack
    2. O(n) for the preorder results
    3. O(n) for the inorder results
    4. O(n) for the postorder results
*/