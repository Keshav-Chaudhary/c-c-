/*Example: 
Input : A[ ] = { 2, 3, 8, -1, 7, 10 }
Output : -1, 2, 3, 7, 8, 10 

Test case
Input : A[ ] = {-4, 6, 9, -1, 3 }
Output : -4, -1, 3, 6, 9
*/

#include <bits/stdc++.h>
using namespace std;
void merge(int array[], int const left, int const mid,
		int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto Iof1stsubarr = 0, Iof2ndsubarr = 0;
	int Iofmergedarr = left;
	while (Iof1stsubarr < subArrayOne
		&& Iof2ndsubarr < subArrayTwo) {
		if (leftArray[Iof1stsubarr]
			<= rightArray[Iof2ndsubarr]) {
			array[Iofmergedarr]
				= leftArray[Iof1stsubarr];
			Iof1stsubarr++;
		}
		else {
			array[Iofmergedarr]
				= rightArray[Iof2ndsubarr];
			Iof2ndsubarr++;
		}
		Iofmergedarr++;
	}
	while (Iof1stsubarr < subArrayOne) {
		array[Iofmergedarr]
			= leftArray[Iof1stsubarr];
		Iof1stsubarr++;
		Iofmergedarr++;
	}
	while (Iof2ndsubarr < subArrayTwo) {
		array[Iofmergedarr]
			= rightArray[Iof2ndsubarr];
		Iof2ndsubarr++;
		Iofmergedarr++;
	}
	delete[] leftArray;
	delete[] rightArray;
}
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}
int main()
{
	int arr[] = {-4, 6, 9, -1, 3 };
	int SizeOfarr = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, SizeOfarr);

	mergeSort(arr, 0, SizeOfarr - 1);

	cout << "\nSorted array is \n";
	printArray(arr, SizeOfarr);
	return 0;
}
