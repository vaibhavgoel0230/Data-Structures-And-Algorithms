#include <iostream>
#include <vector>
using namespace std;

class Solution{
    private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls){
        // mark the current node as visited
        vis[node] = 1;
        ls.push_back(node);
        // traverse all the nodes that are adjacent to the current node
        for(auto it : adj[node]){
            // if the node is not visited, then we will call the dfs function for that node
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
    }

    public:
    // function to perform dfs traversal
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        // initialize the list to store the dfs traversal
        vector<int> ls;
        // call the dfs function for the starting node
        dfs(0, adj, vis, ls);
        return ls;
    }
};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans){
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}



int main(){
    vector<int> adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution Obj;
    vector<int> ans = Obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}

/*
    Time Complexity: O(N)+O(2E) - Because for every node we are calling the recursive function once and for every node we are traversing through the adjacency list
    Space Complexity: O(3N) ~ O(N) - for the visited array, the adjacency list and the stack space
    where N is the number of nodes and E is the number of edges.
*/