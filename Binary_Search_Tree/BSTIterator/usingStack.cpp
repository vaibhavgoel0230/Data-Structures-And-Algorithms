#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// TreeNode class
class TreeNode{
    public:
    // value of the node
    int val;
    // left child of the node
    TreeNode* left;
    // right child of the node
    TreeNode* right;
    // constructor of the node
    TreeNode(int val){
        // initialize the value of the node
        this->val = val;
        // initialize the left child of the node
        this->left = nullptr;
        // initialize the right child of the node
        this->right = nullptr;
    }
};

// create the tree
TreeNode* createTree(vector<int>& arr, int index, int n){
    // if the index is out of bounds or the value is -1, return nullptr
    if(index >= n || arr[index] == -1) return nullptr;
    // create the root of the tree
    TreeNode* root = new TreeNode(arr[index]);
    // create the left child of the root
    root->left = createTree(arr, 2*index+1, n);
    // create the right child of the root
    root->right = createTree(arr, 2*index+2, n);
    // return the root of the tree
    return root;
}

// BSTIterator class
class BSTIterator {
    // stack to store the nodes
    stack<TreeNode*> st;
    // push all the nodes in the left subtree
    void pushAll(TreeNode* root){
        // current node
        TreeNode* curr = root;
        // push all the nodes in the left subtree
        while(curr){
            // push the current node
            st.push(curr);
            // move to the left child of the current node
            curr = curr->left;
        }
    }

    public:
    // constructor of the BSTIterator
    BSTIterator(TreeNode* root){
        // push all the nodes in the left subtree
        pushAll(root);
    }

    // return the next smallest number
    int next(){
        // if the stack is empty, return -1
        if(st.empty()) return -1;
        // get the top node
        TreeNode* temp = st.top();
        // pop the top node
        st.pop();
        // push all the nodes in the right subtree
        pushAll(temp->right);
        // return the value of the top node
        return temp->val;
    }

    // return true if there is a next smallest number
    bool hasNext(){
        return !st.empty();
    }
};

int main(){
    // input the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    // input the array of elements
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    // create the tree
    TreeNode* root = createTree(arr, 0, n);

    // input the number of queries
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    // input the queries
    vector<string> queries(q);
    cout << "Enter the queries: ";

    // create the BSTIterator object
    BSTIterator* obj;

    // iterate over the queries
    for(int i = 0; i < q; i++){
        // input the query
        cin >> queries[i];
        // if the query is BSTIterator, create the BSTIterator object
        if(queries[i] == "BSTIterator"){
            obj = new BSTIterator(root);
            cout << "null" << endl;
        }
        // if the query is next, return the next smallest number
        else if(queries[i] == "next"){
            cout << obj->next() << endl;
        }
        // if the query is hasNext, return true if there is a next smallest number
        else if(queries[i] == "hasNext"){
            if(obj->hasNext()) cout << "true" << endl;
            else cout << "false" << endl;
        }
    }
    // delete the BSTIterator object
    delete obj;

    return 0;
}

// Time Complexity: O(1) for next() and hasNext()  
// Space Complexity: O(h) for the stack, where h is the height of the tree

