#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]){
        vector<int> bfs;
        vector<int> vis(V, 0);
        queue<int> q;
        // push the starting node to the queue and mark it as visited
        q.push(0);
        vis[0] = 1;
        // while the queue is not empty, we will pop the front node and add it to the bfs vector
        while(!q.empty()){
            // pop the front node from the queue and add it to the bfs vector
            int node = q.front();
            q.pop();
            // add the node to the bfs vector
            bfs.push_back(node);

            // traverse through the adjacency list of the node
            for(auto it : adj[node]){
                // if the node is not visited, push it to the queue and mark it as visited
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
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
    vector<int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution Obj;
    vector<int> ans = Obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}

/*
    Time Complexity: O(N)+O(2E) - 2E is for total degrees as we traverse through the adjacency list
    Space Complexity: O(3N) ~ O(N) - for the queue and the visited array and adjacency list
    where N is the number of nodes and E is the number of edges.
*/