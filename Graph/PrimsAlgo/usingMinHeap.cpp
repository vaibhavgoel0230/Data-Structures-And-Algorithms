#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    public:
    // Function to find the minimum spanning tree using Prim's algorithm
    int spanningTree(int V, vector<vector<int>> adj[]){
        // create the priority queue for storing the nodes and their weights
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        // push the starting node to the priority queue
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()){
            // the top element of the priority queue is the node with the minimum weight
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            // if the node is already visited, then continue
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            // traverse through the adjacent nodes
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                // if the adjacent node is not visited, then push it to the priority queue
                if(vis[adjNode] == 0){
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        // return the sum of the weights of the minimum spanning tree
        return sum;
    }
};

int main(){
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 1},
        {2, 3, 2},
        {3, 4, 1},
        {4, 2, 2}
    };
    vector<vector<int>> adj[V];
    for(auto it: edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    Solution Obj;
    int ans = Obj.spanningTree(V, adj);
    cout << ans << endl;
    return 0;
}

/*
Time Complexity: O(E*log(E))
Space Complexity: O(E+V)
*/

