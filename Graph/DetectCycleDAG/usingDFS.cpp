#include <iostream>
#include <vector>
using namespace std;

class Solution{
    private:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]){
        // mark the node as visited and in the current path
        vis[node] = 1;
        pathVis[node] = 1;

        // traverse for adjacent nodes
        for(auto it: adj[node]){
            // if the node is not visited, then visit it
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj)) return true;
            }
            // if the node is visited and it is in the current path, then there is a cycle
            else if(pathVis[it]){
                return true;
            }
        }
        // backtrack and remove the node from the current path
        pathVis[node] = 0;
        return false;
    }
    public:
    bool isCyclic(int V, vector<int> adj[]){
        // mark all the nodes as not visited and not in the current path
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        // traverse for all the nodes
        for(int i=0; i<V; i++){
            // if the node is not visited, then visit it
            if(!vis[i]){
                // if there is a cycle, then return true
                if(dfs(i, vis, pathVis, adj)) return true;
            }
        }
        // if there is no cycle, then return false
        return false;
    }
};

int main(){
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int V = 11;
    Solution Obj;
    // check if there is a cycle in the graph
    bool ans = Obj.isCyclic(V, adj);
    // print the result
    cout << (ans ? "It is a cycle" : "No cycle") << endl;
    return 0;
}

/*
Time Complexity: O(V + E) + O(V), where V is the number of vertices and E is the number of edges
Space Complexity: O(2N)+O(N) ~ O(2N): O(2N) for two visited arrays and O(N) for the recursion stack
*/