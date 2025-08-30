#include <iostream>
#include <vector>
using namespace std;

// using DSU
class DSU{
    private:
    // rank is the rank of the node
    // parent is the parent of the node
    // components is the number of components in the graph
    vector<int> rank, parent;
    int components;

    public:
    // constructor to initialize the rank, parent and components
    DSU(int n) {
        rank.resize(n, 1);
        parent.resize(n);
        components = 0;
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    // find the parent of the node
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // add a component to the graph
    void addComponents() {
        components++;
    }

    // get the number of components in the graph
    int getComponents() {
        return components;
    }

    // unite the two nodes
    void unite(int x, int y){
        int px = find(x), py = find(y);
        if(px == py) return;

        // if the rank of the node is less than the rank of the other node, then make the parent of the node the parent of the other node
        if(rank[px] < rank[py]){
            parent[px] = py;
        } else if(rank[px] > rank[py]){
            // if the rank of the node is greater than the rank of the other node, then make the parent of the other node the parent of the node
            parent[py] = px;
        } else {
            // if the rank of the node is equal to the rank of the other node, then make the parent of the other node the parent of the node and increment the rank of the node
            parent[py] = px;
            rank[px]++;
        }
        // decrement the number of components
        components--;
    }
};

class Solution{
    public:
    int numIslands(vector<vector<int>> &grid){
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        DSU dsu(m*n);
        vector<vector<int>> dir = {
            {-1,0}, {0,1}, {1,0}, {0, -1}
        };

        // traverse the grid
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int idx = i*n + j;
                    // add a component to the graph
                    dsu.addComponents();
                    for(auto& d: dir){
                        int nr = i + d[0];
                        // get the column of the cell
                        int nc = j + d[1];
                        // if the cell is land, then unite the two nodes
                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                            int nidx = nr*n + nc;
                            // unite the two nodes
                            dsu.unite(idx, nidx);
                        }
                    }
                }
            }
        }
        // return the number of components
        return dsu.getComponents();
    }
};

int main(){
    // grid to test the code
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };
    // object of the Solution class
    Solution Obj;
    // print the number of islands
    cout << Obj.numIslands(grid) << endl;
    return 0;
}

/*
Time Complexity: O(m * n * α(m * n))
- We iterate through all m * n cells in the grid
- For each cell that contains '1', we perform at most 4 union operations (for 4 directions)
- Each union operation involves two find operations
- With path compression and union by rank, each find operation takes O(α(m * n)) amortized time
- α is the inverse Ackermann function, which is effectively constant for practical purposes
- Overall: O(m * n * α(m * n)) ≈ O(m * n)

Space Complexity: O(m * n)
- DSU parent array: O(m * n) space
- DSU rank array: O(m * n) space
- Direction array: O(1) space (constant 4 directions)
- Other variables: O(1) space
- Overall: O(m * n)

where m is the number of rows and n is the number of columns in the grid.
*/