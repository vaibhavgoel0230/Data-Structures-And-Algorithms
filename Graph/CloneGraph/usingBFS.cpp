#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public:
        int val;
        vector<Node*> neighbors;
    }

    Test case:
    1 -- 2
    |    |
    4 -- 3

    Output:
    1 -- 2
    |    |
    4 -- 3
*/

// Definition of the Node class
class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

// Solution class to clone the graph
class Solution {
    public:
        Node* cloneGraph(Node* node) {
            // If the graph is empty, return nullptr
            if (node == nullptr) return nullptr;
            // Map to store the visited nodes
            unordered_map<Node*, Node*> visited;
            // Call the clone function to clone the graph
            return clone(node, visited);
        }

        // Helper function to clone the graph
        Node* clone(Node* node, unordered_map<Node*, Node*>& visited) {
            // If the node is already visited, return the visited node
            if (visited.find(node) != visited.end()) return visited[node];
            // Create a new node with the value of the current node
            Node* newNode = new Node(node->val);
            // Add the new node to the visited map
            visited[node] = newNode;
            // Clone the neighbors of the node
            for (Node* neighbor : node->neighbors) {
                newNode->neighbors.push_back(clone(neighbor, visited));
            }
            // Return the cloned node
            return newNode;
        }
};

// Helper function to print the graph using BFS
void printGraphBFS(Node* node) {
    if (node == nullptr) return;
    vector<bool> visited(100, false);
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (visited[curr->val]) continue;
        cout << curr->val << " ";
        visited[curr->val] = true;
        for (Node* neighbor : curr->neighbors) {
            if (!visited[neighbor->val]) {
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);
    Solution sol;
    cout << "Original Graph:" << endl;
    printGraphBFS(node1);
    Node* clonedNode = sol.cloneGraph(node1);
    cout << "Cloned Graph:" << endl;
    printGraphBFS(clonedNode);
    return 0;
}