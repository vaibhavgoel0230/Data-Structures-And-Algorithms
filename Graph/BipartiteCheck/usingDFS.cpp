#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
    // DFS function to check if the graph is bipartite
    bool check(int node, int col, vector<vector<int>>& graph, vector<int>& color){
        // color the current node
        color[node] = col;
        // traverse through all adjacent nodes
        for(auto it: graph[node]){
            // if the adjacent node is not colored, color it with the opposite color
            if(color[it] == -1){
                if(check(it, 1 - col, graph, color) == false) return false;
            // if the adjacent node has the same color as the current node, graph is not bipartite
            } else if(color[it] == col){
                return false;
            }
        }
        return true;
    }

    public:
    // check if the graph is bipartite using DFS
    bool isBipartite(vector<vector<int>>& graph){
        int n = graph.size();
        // color array to store the color of each vertex (-1 means uncolored)
        vector<int> color(n, -1);
        
        // check all components of the graph
        for(int i=0; i<n; i++){
            // if the node is not colored, start DFS from this node
            if(color[i] == -1){
                if(check(i, 0, graph, color) == false) return false;
            }
        }
        return true;
    }
};

int main(){
    // This test case is problematic - it's NOT bipartite
    // Node 0 is connected to nodes 1, 2, 3
    // Node 1 is connected to nodes 0, 2  
    // Node 2 is connected to nodes 0, 1, 3
    // Node 3 is connected to nodes 0, 2
    // This forms cycles like 0-1-2-0 and 0-2-3-0, making it non-bipartite
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    Solution Obj;
    cout << "Is bipartite: " << Obj.isBipartite(graph) << endl; // Should output 0 (false)
    
    // Test with a bipartite graph
    vector<vector<int>> bipartiteGraph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << "Is bipartite (second test): " << Obj.isBipartite(bipartiteGraph) << endl; // Should output 1 (true)
    
    return 0;
}

/*
ISSUES WITH THE ORIGINAL CODE:

1. TEST CASE ISSUE: The main issue is that the test graph {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}} 
   is NOT bipartite, but the code might seem to work incorrectly if you expect it to be bipartite.
   
   Graph structure:
   - Node 0 connects to: 1, 2, 3
   - Node 1 connects to: 0, 2  
   - Node 2 connects to: 0, 1, 3
   - Node 3 connects to: 0, 2
   
   This creates odd cycles:
   - Triangle: 0-1-2-0 (odd cycle of length 3)
   - Another path: 0-2-3-0 with 0-1-2 forming conflicts
   
   A bipartite graph cannot have odd cycles, so this should return false.

2. MISLEADING OUTPUT: Without proper labeling, it's unclear what the output means.
   The code is actually working correctly by returning false, but this might confuse
   someone expecting the graph to be bipartite.

The algorithm itself is correct - it's a standard DFS-based bipartite checking algorithm.
The main issue is the test case expectation and output clarity.

Time Complexity: O(V + E)
- We visit each vertex at most once during the DFS traversal
- For each vertex, we examine all its adjacent edges
- In the worst case, we traverse all vertices (V) and all edges (E)
- The outer loop runs V times, but each vertex is processed only once due to the color check
- The DFS recursion visits each node exactly once
- Overall: O(V + E)

Space Complexity: O(V)
- Color array: O(V) space to store the color of each vertex
- Recursion stack: O(V) space in the worst case (for a linear graph or deep recursion)
- Other variables: O(1) space
- Overall: O(V)

where V is the number of vertices and E is the number of edges in the graph.
*/