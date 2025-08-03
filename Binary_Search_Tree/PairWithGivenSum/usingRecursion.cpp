#include <iostream>
#include <vector>
#include <algorithm>
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

bool search(TreeNode* root, TreeNode* curr, int complement){
    // if the root is nullptr, return false
    if(!root) return false;
    // create a temporary node to traverse the tree
    TreeNode* temp = root; // Fixed: Changed from curr to root to search in entire tree
    // traverse the tree
    while(temp){
        // if the value of the temporary node is equal to the complement and the temporary node is not the current node, return true
        if(temp->val == complement && temp != curr){
            return true;
        }
        // if the value of the temporary node is greater than the complement, move to the left child
        if(temp->val > complement){
            temp = temp->left;
        }
        // if the value of the temporary node is less than the complement, move to the right child
        else{
            temp = temp->right;
        }
    }
    // if the complement is not found, return false
    return false;
}

bool findPair(TreeNode* root, TreeNode* curr, int target){
    // if the root is nullptr, return false
    if(curr == nullptr) return false; // Fixed: Changed root to curr since we're traversing from curr
    // calculate the complement
    int complement = target - curr->val;    
    // if the complement is found, return true
    if(search(root, curr, complement)){
        return true;
    }
    // if the complement is not found, search in the left and right subtrees
    return findPair(root, curr->left, target) || findPair(root, curr->right, target);
}

int main(){
    // take the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    // take the array
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // create the tree
    TreeNode* root = createTree(arr, 0);
    // take the target sum
    int target;
    cout << "Enter the target sum: ";
    cin >> target;
    // check if the pair exists
    if(findPair(root, root, target)){
        cout << "Pair exists" << endl;
    }
    else{
        cout << "Pair does not exist" << endl;
    }
    return 0;
}

// Time Complexity: O(n^h) where h is the height of the tree
// Space Complexity: O(h) for the recursive stack space