#include <iostream>
#include <vector>
using namespace std;
#include <climits> 
class MinHeap {
private:
    vector<int> heap;

    // Helper functions to get parent, left child, and right child indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    // Move the newly inserted element up to its correct position to maintain the heap property
    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Move the element down to its correct position to maintain the heap property
    void heapifyDown(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {}

    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Delete the minimum element (root) from the heap
    void deleteMin() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Extract and return the minimum element from the heap
    int extractMin() {
        if (heap.empty()) return INT_MAX;

        int minVal = heap[0];
        deleteMin();
        return minVal;
    }

    // Perform heap sort on the heap
    void heapSort() {
        vector<int> sorted;
        while (!heap.empty()) {
            sorted.push_back(extractMin());
        }
        heap = sorted;
    }

    // Display the elements of the heap
    void displayHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create an instance of MinHeap
    MinHeap minHeap;

    // Insert elements into the heap
    minHeap.insert(3);
    minHeap.insert(7);
    minHeap.insert(1);
    minHeap.insert(5);
    minHeap.insert(2);

    // Display the original Min Heap
    cout << "Original Min Heap: ";
    minHeap.displayHeap();

    // Delete the minimum element from the heap
    minHeap.deleteMin();
    cout << "After Deleting Min Element: ";
    minHeap.displayHeap();

    // Extract the minimum element from the heap
    cout << "Extracted Min Element: " << minHeap.extractMin() << endl;

    // Perform heap sort and display the sorted array
    minHeap.heapSort();
    cout << "Sorted Array using Heap Sort: ";
    minHeap.displayHeap();

    return 0;
}
