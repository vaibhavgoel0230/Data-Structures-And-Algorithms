#include <iostream>
#include <vector>
using namespace std;

// define the Node structure
struct Node{
    // value of the node
    int data;
    // left child of the node
    Node* left;
    // right child of the node
    Node* right;

    // constructor to initialize the node
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// function to build the tree
Node* buildTree(vector<int> &nodes, int index, int n){
    // if the index is out of bounds or the value is -1, return NULL
    if((index>=n) || (nodes[index] == -1)) return NULL;
    // create the root node
    Node* root = new Node(nodes[index]);
    // create the left and right subtrees
    root->left = buildTree(nodes, 2*index+1, n);
    root->right = buildTree(nodes, 2*index+2, n);
    // return the root node
    return root;
}

// function to find if the two trees are identical
bool checkIdentical(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL || root2==NULL) return false;

    return (
        root1->data == root2->data &&
        checkIdentical(root1->left, root2->left) &&
        checkIdentical(root1->right, root2->right)
    );
}

int main(){
    // input the number of nodes in the tree
    cout << "Enter the number of nodes in the tree: ";
    int n;
    cin >> n;

    // input the nodes of the first tree
    cout << "Enter the nodes of the first tree: ";
    vector<int> nodes1(n);
    for(int i = 0; i < n; i++){
        cin >> nodes1[i];
    }

    // input the nodes of the second tree
    cout << "Enter the nodes of the second tree: ";
    vector<int> nodes2(n);
    for(int i = 0; i < n; i++){
        cin >> nodes2[i];
    }
    // build the trees
    Node* root1 = buildTree(nodes1, 0, n);
    Node* root2 = buildTree(nodes2, 0, n);
    
    // check if the trees are identical
    bool isIdentical = checkIdentical(root1, root2);

    // print the result
    cout << "The trees are " << (isIdentical ? "identical" : "not identical") << endl;
    return 0;
}

/*
    Time Complexity: O(n+m) - where n and m are the number of nodes in the two trees
    Space Complexity: O(1) - no extra space/data structure is used
    O(h) space is used for the recursive stack space
    where h is the height of the two trees
*/