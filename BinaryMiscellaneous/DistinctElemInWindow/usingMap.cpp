#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

// count distinct elements in every window of size k
vector<int> countDistinctElement(vector<int>& arr, int k){
    // create a map to store the count of each element
	unordered_map<int,int> umap;

    // create a vector to store the result
	vector<int> result;
	
    // get the size of the array
	int n = arr.size();

    // create two pointers to traverse the array
	int i=0, j=0;
	
    // traverse the array
	while(j<n){
        // store the count of the current element
		umap[arr[j]]++;
		
        // if the window size is equal to k
		if(j-i+1 == k){
            // store the count of distinct elements in the current window
			result.push_back(umap.size());
			
            // if the count of the current element is 1, remove it from the map
			if(umap[arr[i]] == 1) umap.erase(arr[i]);
            // otherwise, decrement the count of the current element
			else umap[arr[i]]--;
			
            // move the left pointer to the right
			i++;
		}
		
        // move the right pointer to the right
		j++;
	}

    // return the result
	return result;
}

int main(){
    // create a vector of integers
	vector<int> arr = {2, 2, 3, 2, 1};

    // create a variable to store the window size
	int k = 2;

    // create a vector to store the result
	vector<int> result = countDistinctElement(arr, k);

    // print the result
	for(int i=0; i<result.size(); i++){
		cout << result[i] << " ";
	}

    // print a new line
    cout << endl;
	
	return 0;
}

// Time Complexity: O(n) because we are traversing the array only once.
// Space Complexity: O(n) because we are using a map to store the count of each element.