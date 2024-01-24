#include <iostream>
#include <string>

using namespace std;
struct MyStruct {
    int id;
    string name;
    string country;
};
void inputStructDetails(MyStruct &s) {
    cout << "Enter ID: ";
    cin >> s.id;

    cin.ignore(); 
    cout << "Enter name: ";
    getline(cin, s.name);

    cout << "Enter country: ";
    getline(cin, s.country);
}
void displayStructDetails(const MyStruct &s) {
    cout << "\nStruct Details:\n";
    cout << "ID: " << s.id << endl;
    cout << "Name: " << s.name << endl;
    cout << "Country: " << s.country << endl;
}

int main() {
    MyStruct *structPtr = new MyStruct;
    inputStructDetails(*structPtr);
    displayStructDetails(*structPtr);
    delete structPtr;
    return 0;
}

#include <stdio.h>
#include <limits.h>

void findSecondLargestAndSmallest(int arr[], int size) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    printf("Second Largest: %d\n", secondLargest);
    printf("Second Smallest: %d\n", secondSmallest);
}

int main() {
    int arr[] = {5, 8, 2, 1, 7, 3, 9, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    findSecondLargestAndSmallest(arr, size);
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> calculatePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n, 0);

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

int rangeSumQuery(const vector<int>& prefixSum, int l, int r) {
    if (l == 0) {
        return prefixSum[r];
    } else {
        return prefixSum[r] - prefixSum[l - 1];
    }
}

int main() {
    // Example array
    vector<int> arr = {1, 2, 3, 4, 5};

    // Calculate the prefix sum array
    vector<int> prefixSum = calculatePrefixSum(arr);

    // Example range sum query
    int l = 1, r = 3;
    int result = rangeSumQuery(prefixSum, l, r);

    // Display the result
    cout << "Sum of elements from index " << l << " to " << r << ": " << result << endl;

    return 0;
}

#include <iostream>
void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
void swap_by_reference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 5, num2 = 10;

    swap_by_value(num1, num2);
    std::cout << "After swap_by_value: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    swap_by_reference(num1, num2);
    std::cout << "After swap_by_reference: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
}
