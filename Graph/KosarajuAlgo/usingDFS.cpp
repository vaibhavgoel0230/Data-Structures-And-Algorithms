#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
    private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs3(it, adj, vis);
            }
        }
    }

    public:
    int kosaraju(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }

        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfs3(node, adjT, vis);
                scc++;
            }
        }
        return scc;
    }
};

int main(){
    int n = 5;
    int edges[5][2] = {{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};
    vector<int> adj[n];
    for(int i=0; i<5; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Solution Obj;
    int ans = Obj.kosaraju(n, adj);
    cout << "The number of SCC is: " << ans << endl;    
    return 0;
}

/*
Time Complexity: 3*O(V + E) - The first step is a simple DFS to claculate starting nodes. The second step is a simple DFS to claculate the transpose graph. The third step is a simple DFS to calculate the SCCs.
Space Complexity: O(V) - The stack and the visited array.
where V is the number of vertices and E is the number of edges in the graph.
*/