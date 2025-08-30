#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    // using iterations
    vector<vector<int>> floydWarshall(vector<vector<int>> &matrix){
        // initialize the matrix
        int n = matrix.size();
        // traverse the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // if the cell is -1, initialize it to 1e9
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }

                // if the cell is the same as the current cell, initialize it to 0
                if(i == j){
                    matrix[i][j] = 0;
                }
            }
        }

        // traverse the matrix
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    // update the cell with the minimum distance
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // traverse the matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // if the cell is 1e9, initialize it to -1
                if(matrix[i][j] == 1e9){
                    matrix[i][j] = -1;
                }
            }
        }

        return matrix;
    }
};

int main(){
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, -1));
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;
    Solution Obj;
    vector<vector<int>> ans = Obj.floydWarshall(matrix);

    for(auto row: ans){
        for(auto it: row){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Time Complexity: O(V^3)
Space Complexity: O(V^2)
*/