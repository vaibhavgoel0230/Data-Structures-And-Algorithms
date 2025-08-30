#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
    // using BFS
    int numIslands(vector<vector<int>> &grid){
        // get the number of rows and columns of the grid
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int numIslands = 0;
        vector<int> offsets = {0, 1, 0, -1, 0};

        // traverse the grid
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    // if the cell is land, then increment the number of islands
                    numIslands++;
                    grid[i][j] = 0;
                    queue<pair<int,int>> q;
                    // push the cell to the queue
                    q.push({i, j});
                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        // pop the cell from the queue
                        q.pop();
                        for(int k=0; k<4; k++){
                            int nr = p.first + offsets[k];
                            // get the column of the cell
                            // get the row of the cell
                            int nc = p.second + offsets[k+1];
                            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                                grid[nr][nc] = 0;
                                // push the cell to the queue
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        // return the number of islands
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
    Time Complexity: O(m*n*log(m*n))+O(N*M*4) ~ O(m*n), For the worst case, the BFS function will be called for (N*M) nodes, and for every node, we are calling the BFS function 4 times,
    it will take O(N*M*4) time. Set at max will store the complete grid, so it takes log(N*M) time.
    Space Complexity: O(m*n) + O(m*n) ~ O(2m*n) - because we are using a visited matrix and a queue
    where m is the number of rows and n is the number of columns
*/