#include <iostream>
#include <vector>
using namespace std;


// using DFS
class Solution {
    private:
    void dfs(vector<vector<int>> &grid, int sr, int sc){
        // if the current cell is out of bounds or the cell is water, return
        if(
            sr<0 || sr>=grid.size() ||
            sc<0 || sc>=grid[0].size() ||
            grid[sr][sc] == 0
        ) return;

        // mark the current cell as water
        grid[sr][sc] = 0;
        // call the dfs function for the adjacent cells
        dfs(grid, sr+1, sc);
        dfs(grid, sr-1, sc);
        dfs(grid, sr, sc+1);
        dfs(grid, sr, sc-1);
    }
    public:
    int numIslands(vector<vector<int>> &grid){
        // if the grid is empty, return 0
        if(grid.empty() || grid[0].empty()) return 0;

        int numIslands = 0;
        // traverse the grid
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                // if the cell is land, call the dfs function
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    numIslands++;
                    // increment the number of islands
                }
            }
        }
        return numIslands;
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
    cout << Obj.numIslands(grid) << endl;
    return 0;
}

/*
    Time Complexity: O(m*n*log(m*n))+O(N*M*4) ~ O(m*n), For the worst case, the DFS function will be called for (N*M) nodes, and for every node, we are calling the DFS function 4 times,
    it will take O(N*M*4) time. Set at max will store the complete grid, so it takes log(N*M) time.
    Space Complexity: O(m*n) - because we are using a visited matrix
    where m is the number of rows and n is the number of columns
*/
