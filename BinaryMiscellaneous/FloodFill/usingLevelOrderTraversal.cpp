#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// flood fill algorithm using level order traversal
vector<vector<int>> floodFill(vector<vector<int>>& image, int row, int col, int color){

	// get the number of rows and columns of the image
	int m = image.size();
	int n = image[0].size();
	
	// create a visited matrix to store the visited cells
	vector<vector<int>> vis(m, vector<int>(n,0));

	// create a queue to store the cells to be visited
	queue<pair<int,int>> q;

	// push the starting cell into the queue
	q.push({row, col});
	
	// while the queue is not empty
	while(!q.empty()){

		// get the size of the queue
		int size = q.size();

		// traverse the queue
		for(int i=0; i<size; i++){

			// get the current cell
			int ir = q.front().first;
			int ic = q.front().second;

			// get the color of the current cell
			int c = image[ir][ic];

			// change the color of the current cell
			image[ir][ic] = color;

			// pop the current cell from the queue
			q.pop();
			
			// check the bottom cell if it is not visited and has the same color as the current cell
			if(ir+1>=0 && ir+1<m && ic>=0 && ic<n && vis[ir+1][ic]==0 && image[ir+1][ic]==c){
				vis[ir+1][ic] = 1;
				q.push({ir+1, ic});
			}

			// check the top cell if it is not visited and has the same color as the current cell
			if(ir-1>=0 && ir-1<m && ic>=0 && ic<n && vis[ir-1][ic]==0 && image[ir-1][ic]==c){
				vis[ir-1][ic] = 1;
				q.push({ir-1, ic});
			}

			// check the right cell if it is not visited and has the same color as the current cell
			if(ir>=0 && ir<m && ic+1>=0 && ic+1<n && vis[ir][ic+1]==0 && image[ir][ic+1]==c){
				vis[ir][ic+1] = 1;
				q.push({ir, ic+1});
			}

			// check the left cell if it is not visited and has the same color as the current cell
			if(ir>=0 && ir<m && ic-1>=0 && ic-1<n && vis[ir][ic-1]==0 && image[ir][ic-1]==c){
				vis[ir][ic-1] = 1;
				q.push({ir, ic-1});
			}
		}
	}

	// return the image
	return image;
}


int main(){

    // create a vector of vectors of integers
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};

    // get the row, column and color
    int row = 1;
    int col = 1;
    int color = 2;

    // call the floodFill function
    vector<vector<int>> result = floodFill(image, row, col, color);
    
    // print the result
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(n*m) because we are traversing the entire image.
// Space Complexity: O(n*m) because we are using a visited matrix to store the visited cells.