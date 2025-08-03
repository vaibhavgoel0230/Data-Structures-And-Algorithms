#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Min Heap
class MinHeap{
	// array to store the heap	
	vector<int> arr;
	
	public:
	// check if the heap is empty
	bool isEmpty(){
		return arr.empty();
	}
	
	// get the top element of the heap
	int top(){
		if(isEmpty()) return -1;
		
		return arr[0];
	}

	// get the size of the heap
	int size(){
		return arr.size();
	}

	// push an element into the heap
	void push(int val){
		// push the element into the heap
		arr.push_back(val);

		// get the index of the element
		int index = arr.size()-1;

		// heapify the heap
		while(index > 0 && (arr[index] < arr[(index-1)/2])){
			// swap the element with its parent
			swap(arr[index], arr[(index-1)/2]);

			// update the index
			index = (index-1)/2;
		}
	}
	
	// pop the top element from the heap
	int pop(){
		// if the heap is empty, return -1
		if(isEmpty()) return -1;

		// get the minimum element
		int minimum = arr[0];

		// replace the root with the last element
		arr[0] = arr.back();

		// remove the last element
		arr.pop_back();
		
		// get the index of the element
		int index = 0;

		// heapify the heap
		while( 2*index+1 < arr.size() ){
			// get the left child
			int left = 2*index+1; // Fixed: Changed from 2*index-1 to 2*index+1

			// get the right child
			int right = 2*index+2;

			// get the smallest child
			int smallest = left;

			// if the right child is smaller than the left child, update the smallest child
			if(right < arr.size() && arr[right]<arr[smallest]){
				smallest = right;
			}

			// if the smallest child is greater than the parent, break
			if(arr[smallest]>=arr[index]) break;

			// swap the parent with the smallest child
			swap(arr[smallest], arr[index]);

			// update the index
			index = smallest;
		}
		
		// return the minimum element
		return minimum;
	}
};

// Kth Largest in Stream
class KthLargest{
	// min heap to store the k largest elements
	MinHeap minHeap;

    int k = 0;

	public:

	// constructor
    KthLargest(int k, vector<int>& nums){
        this->k = k;

		// push the elements into the min heap
        for(int num : nums){
            minHeap.push(num);

			// if the size of the min heap is greater than k, pop the top element
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
    }

	// add a number to the data stream
    int add(int num){
		// push the number into the min heap
        minHeap.push(num);

		// if the size of the min heap is greater than k, pop the top element
        if(minHeap.size() > k){
            minHeap.pop();
        }

		// return the top element of the min heap
        return minHeap.top();
    }
};

// main function
int main(){

    // create a vector of integers
    vector<int> nums = {4, 5, 8, 2};

    // create a kth largest object
    KthLargest kthLargest(3, nums);

    // add numbers to the data stream
    cout << kthLargest.add(3) << endl; // return 4
    cout << kthLargest.add(5) << endl; // return 5
    cout << kthLargest.add(10) << endl; // return 5
    cout << kthLargest.add(9) << endl; // return 8
    cout << kthLargest.add(4) << endl; // return 8

    return 0;
}

// Time Complexity: O(log n) for each add operation.
// Space Complexity: O(n) for storing the elements in the heap.