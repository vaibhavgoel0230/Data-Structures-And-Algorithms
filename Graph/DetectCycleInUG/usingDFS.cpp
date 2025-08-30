#include <iostream>
#include <vector>
using namespace std;

class Solution{
    private:
    bool checkForCycle(int node, int parent, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        // visit adjacent nodes
        for(auto it : adj[node]){
            // if the node is not visited, then we will call the dfs function for that node
            if(!vis[it]){
                if(checkForCycle(it, node, adj, vis)) return true;
            }
            // if the node is already visited and the parent is not the same as the current node, then there is a cycle
            else if(parent != it){
                return true;
            }
        }

        return false;
    }

    public:
    // function to check if there is a cycle in the graph
    bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                // if there is a cycle, then we will return true
                if(checkForCycle(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};


int main() {
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution Obj;
    bool ans = Obj.isCycle(4, adj);
    if(ans)
        cout << "1" << endl;
    else
        cout << "0" << endl;
    return 0;
}