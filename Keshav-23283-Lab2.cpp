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