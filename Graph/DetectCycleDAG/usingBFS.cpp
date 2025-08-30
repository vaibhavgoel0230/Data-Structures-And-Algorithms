#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    public:
    // using Kahn's Algorithm
    bool isCyclic(int V, vector<int> adj[]){
        // calculate the indegree of each node
        // indegree is the number of edges coming into a node
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
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

        // count the number of nodes processed
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // increment the count
            cnt++;

            // reduce the indegree of the adjacent nodes
            for(auto it: adj[node]){
                indegree[it]--;
                // if the indegree of the node becomes 0, then push it to the queue
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        // if the count is not equal to the number of nodes, then there is a cycle
        return cnt != V;
    }
};

int main(){
    vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
    int V = 6;
    Solution Obj;
    bool ans = Obj.isCyclic(V, adj);
    // print the result
    cout << (ans ? "It is a cycle" : "No cycle") << endl;
    return 0;
}

/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array and O(N) for the queue data structure 
*/