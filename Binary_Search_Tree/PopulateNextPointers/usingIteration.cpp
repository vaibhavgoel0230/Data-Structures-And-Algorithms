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
        // initialize the value of the node
        this->val = val;
        // initialize the left and right children to NULL
        left = right = next = NULL;
    }
};

// function to build the tree
TreeNode* buildTree(vector<int> &nodes, int index, int n){
    // If the index is out of bounds or the value is -1, return NULL
    if(index >= n || nodes[index] == -1) return NULL;

    // Create the root node
    TreeNode* root = new TreeNode(nodes[index]);
    // Build the left subtree
    root->left = buildTree(nodes, 2*index+1, n);
    // Build the right subtree
    root->right = buildTree(nodes, 2*index+2, n);

    return root;
}

// function to print the tree
void printTree(TreeNode* root){
    // If the root is NULL, return
    if(!root) return;

    // Create a queue to store the nodes
    queue<TreeNode*> q;
    // Push the root node to the queue
    q.push(root);

    // Traverse the tree
    while(!q.empty()){
        // Get the size of the queue
        int size = q.size();

        // Get the front node of the queue
        TreeNode* node = q.front();
        cout << node->val << " ";

        // Traverse the nodes at the current level
        for(int i=0; i<size; i++){
            // Get the front node of the queue
            TreeNode* node = q.front();
            q.pop();

            // If the next pointer is not NULL, print the next pointer
            if(node->next) cout << node->next->val << " ";
            // If the next pointer is NULL, print "#"
            else cout << "# ";

            // Push the left and right children to the queue
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    // Print a new line
    cout << endl;
}

// function to get the next pointer
TreeNode* getNext(TreeNode* root){
    // Start from the next pointer of the root
    TreeNode* temp = root->next;

    while(temp){
        // If the left child is not NULL, return the left child
        if(temp->left) return temp->left;
        // If the right child is not NULL, return the right child
        if(temp->right) return temp->right;
        // Move to the next pointer
        temp = temp->next;
    }

    // If the left and right children are NULL, return NULL
    return NULL;
} 

// function to connect the next pointers
TreeNode* connect(TreeNode* root){
    // If the root is NULL, return NULL
    if(!root) return NULL;

    // Set the next pointer of the root to NULL
    root->next = NULL;

    TreeNode* temp = root;

    // Traverse the tree
    while(temp){
        TreeNode* curr = temp;

        while(curr){
            // If the left child is not NULL
            if(curr->left){
                // If the right child is not NULL
                if(curr->right){
                    // Set the next pointer of the left child to the right child
                    curr->left->next = curr->right;
                }
                // If the right child is NULL
                else{
                    // Get the next pointer of the current node
                    curr->left->next = getNext(curr);
                }
            }

            // If the right child is not NULL
            if(curr->right){
                // Get the next pointer of the current node
                curr->right->next = getNext(curr);
            }

            // Move to the next pointer
            curr = curr->next;
        }

        // If the left child is not NULL, move to the left child
        if(temp->left) temp = temp->left;
        // If the right child is not NULL, move to the right child
        else if(temp->right) temp = temp->right;
        // If the left and right children are NULL, move to the next pointer
        else temp = getNext(temp);
    }

    return root;
}

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
    printTree(root);

    // connect the next pointers
    root = connect(root);

    // print the tree
    printTree(root);

    return 0;
}

// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(1) - we are not using any extra space
