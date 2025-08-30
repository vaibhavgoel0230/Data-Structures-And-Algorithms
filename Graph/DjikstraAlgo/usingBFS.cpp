#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution{
    public:
    // using BFS
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges){
        // create the adjacency list of pairs of the form model -> {node2, edgeWeight}
        // where the edgeWeight is the weight of the edge between the two nodes
        vector<pair<int, int>> adj[n+1];
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // create the priority queue for storing the nodes and their distances
        // the priority queue is a min-heap in the form of {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> parent(n+1);
        // initialize the parent array with the node itself
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }

        // push the starting node to the priority queue
        pq.push({0, 1});
        // create the distance array for storing the updated distances and a parent array
        // for storing the nodes from where the current nodes represented by indices of
        // the parent array came from.
        vector<int> dist(n+1, 1e9);
        dist[1] = 0;

        while(!pq.empty()){
            // the top element of the priority queue is the node with the minimum distance
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            // traverse through the adjacent nodes
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                // if the distance to the adjacent node is less than the current distance, update the distance
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        // if the distance to the destination node is 1e9, then return -1
        if(dist[n] == 1e9) return {-1};
        // create the path array for storing the path
        vector<int> path;
        int node = n;
        // traverse through the parent array to get the path
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        // push the starting node to the path
        path.push_back(1);
        // reverse the path
        reverse(path.begin(), path.end());
        return path;
    }
};

int main(){
    int n = 5;
    int m = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    Solution Obj;
    vector<int> ans = Obj.shortestPath(n, m, edges);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity: O(E*log(V))
Space Complexity: O(E+V)
*/      