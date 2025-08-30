#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
    private:
    // using DFS
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                // if the node is not visited, then visit it
                dfs(it, vis, st, adj);
            }
        }
        // push the node to the stack
        st.push(node);
    }
    public:
    vector<int> topoSort(int V, vector<int> adj[]){
        // mark all the nodes as not visited
        vector<int> vis(V, 0);
        // store the result
        stack<int> st;
        // traverse for all the nodes
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        // store the result
        vector<int> topo;
        // push the nodes to the result
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        // return the result
        return topo;
    }
};

int main(){
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    int V = 6;
    Solution Obj;
    vector<int> ans = Obj.topoSort(V, adj);
    // print the result
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the visited array and O(N) for the stack data structure
*/