/*Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/
/*Q1* test case Input: nums = [3,2,3,1,2,4,5,5,6], k = 2
Output: 5
*/
// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int arr[] = {0,-6,-5,-3,-2,1};
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);
	if (N >= 9) {
        cout << "fourth highest number: " << arr[N - 9] << endl;
    } else {
        cout << "NO second highest no..." << endl;
    }

	return 0;
}