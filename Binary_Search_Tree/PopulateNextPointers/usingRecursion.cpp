#include <iostream>
#include <queue>

using namespace std;

// TreeNode class
struct TreeNode{
    // value of the node
    int val;
    // left child of the node
    TreeNode* left;
    // right child of the node
    TreeNode* right;
    // next pointer of the node
    TreeNode* next;

    // constructor
    TreeNode(int val){
        this->val = val;
        left = right = next = NULL;
    }
};

// function to build the tree
TreeNode* buildTree(vector<int> &nodes, int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if(index >= n || nodes[index] == -1) return NULL;

    // create the root node
    TreeNode* root = new TreeNode(nodes[index]);
    // create the left and right subtrees
    root->left = buildTree(nodes, 2*index+1, n);
    root->right = buildTree(nodes, 2*index+2, n);
    // return the root node
    return root;
}

// function to print the tree
void printTree(TreeNode* root){
    // if the root is NULL, return
    if(!root) return;

    // create a queue to store the nodes
    queue<TreeNode*> q;
    // push the root node to the queue
    q.push(root);
    
    // while the queue is not empty
    while(!q.empty()){
        // get the size of the queue
        int size = q.size();
        // get the front node of the queue
        TreeNode* node = q.front();
        // print the value of the node
        cout << node->val << " ";
        
        // for each node in the queue
        for(int i=0; i<size; i++){
            // get the front node of the queue
            TreeNode* node = q.front();
            // pop the front node from the queue
            q.pop();

            // if the next pointer of the node is not NULL, print the value of the next pointer
            if(node->next) cout << node->next->val << " ";
            // if the next pointer of the node is NULL, print "#"
            else cout << "# ";

            // if the left child of the node is not NULL, push the left child to the queue
            if(node->left) q.push(node->left);
            // if the right child of the node is not NULL, push the right child to the queue
            if(node->right) q.push(node->right);
        }
    }
    // print a new line
    cout << endl;
}

// NOTE: The tree is a perfect binary tree where all the leaves are at the same level and all the internal nodes have two children.
// function to connect the next pointers
TreeNode* connect(TreeNode* root){
    // if the root is NULL or the left child of the root is NULL, return NULL
    if(!root || !root->left) return NULL;

    // connect the left and right children of the root
    root->left->next = root->right;

    // if the next pointer of the root is not NULL, connect the right child of the root to the left child of the next node
    if(root->next) root->right->next = root->next->left;

    // recursively connect the left and right children of the root
    connect(root->left);
    connect(root->right);

    // return the root node
    return root;
}

// main function
int main(){
    // take the number of nodes as input
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // take the nodes as input
    vector<int> nodes(n);
    cout << "Enter the nodes: ";
    for(int i=0; i<n; i++) cin >> nodes[i];

    // build the tree
    TreeNode* root = buildTree(nodes, 0, n);
    
    // connect the next pointers
    root = connect(root);

    // print the tree
    printTree(root);
    
    return 0;
}

/*
    Time Complexity: O(n) -> n is the number of nodes in the tree
    Space Complexity: O(1) -> We don't use any extra space. The only space we use is the space for the recursion stack.
*/