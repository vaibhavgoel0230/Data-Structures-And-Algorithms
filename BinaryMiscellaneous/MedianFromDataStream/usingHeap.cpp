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
			int left = 2*index-1;

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


// Max Heap
class MaxHeap{
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
		while(index > 0){
			if(arr[index] > arr[(index-1)/2]){
				swap(arr[index], arr[(index-1)/2]);
			}

			// update the index
			index = (index-1)/2;
		}
	}

	// pop the top element from the heap
	int pop(){
		// if the heap is empty, return -1
		if(isEmpty()) return -1;

		// get the maximum element
		int maximum = arr[0];

		// replace the root with the last element
		arr[0] = arr[arr.size()-1];

		// remove the last element
		arr.pop_back();
		
		// get the index of the element
		int index = 0;

		// heapify the heap
		while( 2*index+1 < arr.size() ){
			// get the left child
			int left = 2*index+1;

			// get the right child
			int right = 2*index+2;

			// get the largest child
			int largest = left;

			// if the right child is larger than the left child, update the largest child
			if(right < arr.size() && arr[right]>arr[largest]){
				largest = right;
			}

			// if the largest child is less than the parent, break
			if(arr[largest]<arr[index]) break;

			// swap the parent with the largest child
			swap(arr[largest], arr[index]);

			// update the index
			index = largest;
		}

		// return the maximum element
		return maximum;
	}
};


// Median Finder
class MedianFinder{
	MinHeap minHeap;
	MaxHeap maxHeap;

	public:

	// add a number to the data stream
    void addNum(int num){
		// push the number into the max heap
        maxHeap.push(num);

		// push the root of the max heap into the min heap
        minHeap.push(maxHeap.pop());

		// if the size of the min heap is greater than the size of the max heap, push the root of the min heap into the max heap
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.pop());
        }
    }

	// find the median of the data stream
    double findMedian(){
		// if the size of the min heap is equal to the size of the max heap, return the average of the top elements of the min and max heaps
        if(minHeap.size() == maxHeap.size()){
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }

		// return the top element of the max heap
        return maxHeap.top();
    }
};

// main function
int main(){
	// create a median finder
    MedianFinder medianFinder;

	// add numbers to the data stream
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << "The median is: " << medianFinder.findMedian() << endl;
    medianFinder.addNum(3);
    cout << "The median is: " << medianFinder.findMedian() << endl;

	// return 0
    return 0;
}

// Time Complexity: O(log n) for each addNum operation and O(1) for findMedian operation.
// Space Complexity: O(n) for storing the elements in the heaps.