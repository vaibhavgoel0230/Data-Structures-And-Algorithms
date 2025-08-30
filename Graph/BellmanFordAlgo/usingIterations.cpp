#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    // using iterations
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int S){
        vector<int> dist(V, 1e9);
        dist[S] = 0;

        for(int i=0; i<V-1; i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Nth relaxation check for negative cycle
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }

        return dist;
    }
};

int main(){
    int V = 6;
    vector<vector<int>> edges(7, vector<int>(3));
    edges[0] = {3, 2, 6};
    edges[1] = {5, 3, 1};
    edges[2] = {0, 1, 5};
    edges[3] = {1, 5, -3};
    edges[4] = {1, 2, -2};
    edges[5] = {3, 4, -2};
    edges[6] = {2, 4, 3};
    int S = 0;
    Solution Obj;
    vector<int> ans = Obj.bellmanFord(V, edges, S);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity: O(V*E)
Space Complexity: O(V)
*/