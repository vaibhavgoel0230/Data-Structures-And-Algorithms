#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    private:
    // check if the graph is bipartite
    bool check(int node, vector<vector<int>>& graph, vector<int>& color ){
        // queue to store the node and its color
        queue<int> q;
        q.push(node);
        color[node] = 1;

        while(!q.empty()){
            // get the node and its color from the queue
            int node = q.front();
            int col = color[node];
            q.pop();

            // traverse through the adjacent nodes
            for(auto it: graph[node]){
                // if the node is not colored, color it with the opposite color
                if(color[it] == -1){
                    color[it] = 1 - col;
                    q.push(it);
                // if the node is colored and the color is the same as the current node, then the graph is not bipartite
                } else if(it != node && color[it] == col){
                    return false;
                }
            }
        }
        // if the graph is bipartite, return true
        return true;
    }

    public:
    // check if the graph is bipartite
    bool isBipartite(vector<vector<int>>& graph){
        // get the number of vertices in the graph
        int n = graph.size();
        // color array to store the color of each vertex
        vector<int> color(n, -1);

        // traverse through all the vertices
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                // if the graph is not bipartite, return false
                if(!check(i, graph, color) == false) return false;
            }
        }
        // if the graph is bipartite, return true
        return true;
    }
};

int main(){
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    Solution Obj;
    cout << Obj.isBipartite(graph) << endl;
    return 0;
}


/*
Time Complexity: O(V + E)
- We visit each vertex at most once during the BFS traversal
- For each vertex, we examine all its adjacent edges
- In the worst case, we traverse all vertices (V) and all edges (E)
- The outer loop runs V times, but each vertex is processed only once due to the color check
- Overall: O(V + E)

Space Complexity: O(V)
- Color array: O(V) space to store the color of each vertex
- Queue: O(V) space in the worst case (when all vertices are in the queue)
- Other variables: O(1) space
- Overall: O(V)

where V is the number of vertices and E is the number of edges in the graph.
*/