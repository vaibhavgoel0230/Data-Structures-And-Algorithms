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
    if(index>=n || nodes[index]==-1) return NULL;

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
        // print a new line
        cout << endl;
    }
}

// function to connect the next pointers
TreeNode* connect(TreeNode* root){
    // if the root is NULL, return NULL
    if(!root) return NULL;

    // create a queue to store the nodes
    queue<TreeNode*> q;
    // push the root node to the queue
    q.push(root);

    // while the queue is not empty
    while(!q.empty()){
        // get the size of the queue
        int size = q.size();
        // create a pointer to store the previous node
        TreeNode* prev = NULL;

        // for each node in the queue
        for(int i=0; i<size; i++){
            // get the front node of the queue
            TreeNode* node = q.front(); 
            // pop the front node from the queue
            q.pop();

            // if the previous node is not NULL, set the next pointer of the previous node to the current node
            if(prev) prev->next = node;
            // set the previous node to the current node
            prev = node;

            // if the left child of the node is not NULL, push the left child to the queue
            if(node->left) q.push(node->left);
            // if the right child of the node is not NULL, push the right child to the queue
            if(node->right) q.push(node->right);
        }
        // set the next pointer of the last node to NULL
        prev->next = NULL;
    }
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
    Time Complexity: O(n) -> We traverse the tree once level by level
    Space Complexity: O(n) -> We use a queue to store the nodes
*/