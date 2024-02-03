// C++ program for implementation 
// of Bubble sort 
#include <bits/stdc++.h> 
using namespace std; 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n - 1; i++) 

		// Last i elements are already 
		// in place 
		for (j = 0; j < n - i - 1; j++) 
			if (arr[j] > arr[j + 1]) 
				swap(arr[j], arr[j + 1]); 
} 

// Function to print an array 
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 5, 1, 4, 2, 8}; 
	int N = sizeof(arr) / sizeof(arr[0]); 
	bubbleSort(arr, N); 
	cout << "Sorted array: \n"; 
	printArray(arr, N); 
	return 0; 
}
/*The above function always runs O(n^2) time even if the array is sorted.
It can be optimized by stopping the algorithm if the inner loop didn’t cause any swap*/

// Optimized implementation of Bubble sort 
#include <bits/stdc++.h> 
using namespace std; 

// An optimized version of Bubble Sort 
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

// Function to print an array 
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout <<" "<< arr[i]; 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = {5, 3, 1, 9, 8, 2, 4, 7}; 
	int N = sizeof(arr)/sizeof(arr[0]); 
	bubbleSort(arr, N); 
	cout <<"Sorted array: \n"; 
	printArray(arr, N); 
	return 0; 
} 
// This code is contributed by shivanisinghss2110 
/*Time Complexity: O(N2)
Auxiliary Space: O(1)
At pass 1 :  Number of comparisons = (n-1)
                     Number of swaps = (n-1)

  At pass 2 :  Number of comparisons = (n-2)
                     Number of swaps = (n-2)

  At pass 3 :  Number of comparisons = (n-3)
                    Number of swaps = (n-3)
                              .
                              .
                              .
  At pass n-1 :  Number of comparisons = 1
                        Number of swaps = 1

Now , calculating total number of comparison required to sort the array
= (n-1) + (n-2) +  (n-3) + . . . 2 + 1
= (n-1)*(n-1+1)/2  { by using sum of N natural Number formula }
= n (n-1)/2    .

For the Worst case:

Total number of swaps = Total number of comparison
Total number of comparison (Worst case) = n(n-1)/2
Total number of swaps (Worst case) = n(n-1)/2
*/