// Question 1 using the inversion method calculate the number of inversions of the given array 
#include <bits/stdc++.h>
using namespace std;
long long countInversions(int arr[], int n) {
    long long inversions = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}
int main() {
    int arr[] = {1, 3, 2, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
// number of inversions for the given array of size n 
    long long inversions = countInversions(arr, N);
    cout << "no.umber of inversion: " << inversions << endl;
/* Highest no. of inversions size n is given by the formula  n*(n-1)/2 example as the length of an array is 4
 then the highest number of inversions can be written as 4*(4-1)/2 therefore the answer is 6 but for this question 
 the total inversions is only 1 as there is only one condition true for the  arr[i] < arr[j] and i > j*/
    cout << "highest no. of inversions possible for an array of size n as given by the user or in quest  " << N << ": " << (N * (N - 1)) / 2 << endl;

    return 0;
}

// Question 2 ) same as the qusstion number 1 but in this cpp we have to use the merge sort algo to perform the number of inversions 
#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); 
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return invCount;
}

long long mergeandcountingtheinvers(int arr[], int temp[], int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeandcountingtheinvers(arr, temp, left, mid);
        invCount += mergeandcountingtheinvers(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

long long countInversionsUsingMergeSort(int arr[], int n) {
    int temp[n];
    return mergeandcountingtheinvers(arr, temp, 0, n - 1);
}

int main() {
    int arr[] = {1, 3, 2, 5};
    int N = sizeof(arr) / sizeof(arr[0]);

    long long inversions = countInversionsUsingMergeSort(arr, N);

    cout << "Number of inversions using Merge Sort: " << inversions << endl;
    cout << "Highest number of inversions possible for an array of size " << N << ": " << (N * (N - 1)) / 2 << endl;

    return 0;
}

/*
  Time Complexity:
  Best Case: O(n log n) 
  Worst Case: O(n log n)
  Merge sort has a consistentand 
   making it efficient 
*/
