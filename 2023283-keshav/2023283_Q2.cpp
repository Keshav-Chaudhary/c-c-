#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    size_t leftindex = 0, rightindex = 0;

    while (leftindex < left.size() && rightindex < right.size()) {
        if (left[leftindex] < right[rightindex]) {
            result.push_back(left[leftindex]);
            leftindex++;
        } else {
            result.push_back(right[rightindex]);
            rightindex++;
        }
    }

    while (leftindex < left.size()) {
        result.push_back(left[leftindex]);
        leftindex++;
    }

    while (rightindex < right.size()) {
        result.push_back(right[rightindex]);
        rightindex++;
    }

    return result;
}
vector<int> mergeSortRecursive(vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    size_t mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSortRecursive(left);
    right = mergeSortRecursive(right);

    return merge(left, right);
}
vector<int> mergeSortIterative(vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    vector<vector<int>> stack;
    for (int item : arr)
        stack.push_back({item});

    while (stack.size() > 1) {
        vector<int> left = stack.back();
        stack.pop_back();
        vector<int> right = stack.back();
        stack.pop_back();
        stack.push_back(merge(left, right));
    }

    return stack[0];
}
void printVector(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ",";
    }
}

int main() {
    string input;
    cout << "Enter the array to be sorted with elements separated by comma: ";
    getline(cin, input);
    stringstream ss(input);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
        if (ss.peek() == ',')
            ss.ignore();
    }
    vector<int> sortedArrRecursive = mergeSortRecursive(arr);
    cout << "Sorted array by Recursion is: ";
    printVector(sortedArrRecursive);
    cout << endl;
    vector<int> sortedArrIterative = mergeSortIterative(arr);
    cout << "Sorted array by Iteration is: ";
    printVector(sortedArrIterative);
    cout << endl;

    return 0;
}
