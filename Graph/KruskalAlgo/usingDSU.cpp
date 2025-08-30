#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet{
    private:
    // parent is the parent of the node
    // rank is the rank of the node
    // size is the size of the node
    vector<int> parent, rank, size;

    public:
    DisjointSet(int n){
        // initialize the parent, rank and size arrays
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        size.resize(n+1);
        // initialize the parent and size arrays
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        // if the parent of the node is not the node itself, then find the parent of the node
        if(parent[node] != node){
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }

    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        // if the rank of the parent of the node is less than the rank of the parent of the other node, then make the parent of the node the parent of the other node
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        } else if(rank[pv] < rank[pu]){
            // if the rank of the parent of the other node is less than the rank of the parent of the node, then make the parent of the other node the parent of the node
            parent[pv] = pu;
        } else {
            // if the rank of the parent of the node is equal to the rank of the parent of the other node, then make the parent of the other node the parent of the node and increment the rank of the node
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        // if the size of the parent of the node is less than the size of the parent of the other node, then make the parent of the node the parent of the other node and increment the size of the other node
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            // if the size of the parent of the other node is less than the size of the parent of the node, then make the parent of the other node the parent of the node and increment the size of the node
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int, int>>> edges;
        // extract the edges from the adjacency list
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        // sort the edges
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        // traverse through the edges
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            // if the parent of the node is not the parent of the other node, then add the weight to the minimum spanning tree
            if(ds.findParent(u) != ds.findParent(v)){
                mstWt += wt;
                // union the two nodes
                ds.unionByRank(u, v);
            }
        }
        // return the weight of the minimum spanning tree
        return mstWt;
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
    cout << "The weight of the minimum spanning tree is: " << ans << endl;
    return 0;
}

/*
Time Complexity: O(E*log(E) + E*α(V))
- O(E) for extracting edges from adjacency list
- O(E*log(E)) for sorting the edges
- O(E*α(V)) for union-find operations, where α is the inverse Ackermann function (practically constant)
Overall: O(E*log(E))

Space Complexity: O(V + E)
- O(V) for the parent, rank, and size arrays in DisjointSet
- O(E) for storing the edges vector
Overall: O(V + E)

where V is the number of vertices and E is the number of edges in the graph.
*/