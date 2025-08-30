#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    private:
    bool checkForCycle(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        // queue to store the node and its parent
        queue<pair<int, int>> q;
        q.push({node, -1});
        // while the queue is not empty, we will pop the front node and add it to the bfs vector
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            // traverse through the adjacency list of the node
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                }
                // if the node is already visited and the parent is not the same as the current node, then there is a cycle
                else if(parent != it){
                    return true;
                }
            }
        }

        return false;
    }

    public:
    // function to check if there is a cycle in the graph
    bool isCycle(int V, vector<int> adj[]){
        // initialize the visited array
        vector<int> vis(V, 0);
        // traverse through the graph
        for(int i = 0; i < V; i++){
            // if the node is not visited, then we will check for a cycle
            if(!vis[i]){
                // if there is a cycle, then we will return true
                if(checkForCycle(i, adj, vis)) return true;
            }
        }
        return false;
    }
};



int main(){
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution Obj;
    bool ans = Obj.isCycle(4, adj);
    if(ans)
        cout << "1" << endl;
    else
        cout << "0" << endl;
    return 0;
}

/*
    Time Complexity: O(N)+O(2E) - Because for every node we are calling the recursive function once and for every node we are traversing through the adjacency list
    Space Complexity: O(3N) ~ O(N) - for the visited array, the adjacency list and the queue
    where N is the number of nodes and E is the number of edges.
*/