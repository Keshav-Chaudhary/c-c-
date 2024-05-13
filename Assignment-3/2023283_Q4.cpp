#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Func. to get the maximum element from the task IDs list
int getMaxElement(vector<int>& taskIDs) {
    int maxElement = *max_element(taskIDs.begin(), taskIDs.end()); // Find the maximum element
    taskIDs.erase(find(taskIDs.begin(), taskIDs.end(), maxElement)); // Remove the maximum element from the list
    return maxElement; // Return the maximum element
}

// Func. to get the kth smallest element from the task IDs list
int getKthSmallestElement(vector<int>& taskIDs, int k) {
    sort(taskIDs.begin(), taskIDs.end()); // Sorting the task IDs list in ascending order
    int kthSmallest = taskIDs[k - 1]; // getting the kth smallest element
    taskIDs.erase(find(taskIDs.begin(), taskIDs.end(), kthSmallest)); // removing the kth smallest element from the list
    return kthSmallest; // returning the kth smallest element
}

// func. to get the median element from the task IDs list
int getMedianElement(vector<int>& taskIDs) {
    int medianIndex = taskIDs.size() / 2; // Calculating the index of the median element
    int median = taskIDs[medianIndex]; // Get the median element
    sort(taskIDs.begin(), taskIDs.end()); // Sort the task IDs list in ascending order
    taskIDs.erase(taskIDs.begin() + medianIndex); // Remove the median element from the list
    return median; // Return the median element
}

int main() {
    vector<int> taskIDs = {34, 56, 12, 44, 10};
    vector<int> originalTaskIDs = taskIDs; // Save a copy of the original task IDs for query 3

    // Example queries
    cout << "Input Query: 1\nOutput: " << getMaxElement(taskIDs) << endl;
    cout << "Input Query: 2\nEnter k: 3\nOutput: " << getKthSmallestElement(taskIDs, 3) << endl;
    cout << "Input Query: 3\nOutput: " << getMedianElement(originalTaskIDs) << endl;

    return 0;
}
