#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> subarraysmaxandmin(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);

    for (int i = 0; i < n; ++i) {
        int minimumvalues = arr[i];
        for (int j = i; j < n; ++j) {
            minimumvalues = min(minimumvalues, arr[j]);
            result[j - i] = max(result[j - i], minimumvalues);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    vector<int> result = subarraysmaxandmin(arr);
    cout << "The resulting array is [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}