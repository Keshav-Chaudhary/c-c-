/*Example:
Input: nums = [2,0,2,1,1,0]
*/
#include <bits/stdc++.h> 
using namespace std; 
void bubbleSort(int arr[], int n) { 
	bool isUnsorted; 
	do { 
		isUnsorted = false; 
		for (int i = 0; i < (n - 1); i++) { 
			if (arr[i] > arr[i + 1]) { 
				isUnsorted = true; 
				for (; i < (n - 1); i++) { 
					if (arr[i] > arr[i + 1]) { 
						std::swap(arr[i], arr[i + 1]); 
					} 
				} 
			} 
		} 
	} while (isUnsorted); 
} 
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout <<" "<< arr[i]; 
} 
int main() 
{ 
	int arr[] ={2,0,2,1,1,0} ; 
	int N = sizeof(arr)/sizeof(arr[0]); 
	bubbleSort(arr, N); 
	printArray(arr, N); 
	return 0; 
} 