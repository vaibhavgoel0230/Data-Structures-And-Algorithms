#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    public:
    // using Kahn's Algorithm
    vector<int> topoSort(int V, vector<int> adj[]){
        // calculate the indegree of each node
        vector<int> indegree(V, 0);
        // traverse for all the nodes
        for(int i=0; i<V; i++){
            // traverse for all the adjacent nodes
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        // push the nodes with indegree 0 to the queue
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        // store the result
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // reduce the indegree of the adjacent nodes
            for(auto it: adj[node]){
                indegree[it]--;
                // if the indegree of the node becomes 0, then push it to the queue
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
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
    adj[3].push_back(1);
    adj[2].push_back(3);
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
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array and O(N) for the queue data structure
*/