#include<iostream>
#include<cstdlib> 
#include<ctime>   
using namespace std;

int randomPartition(int arr[], int low, int high) {
    srand(time(NULL)); 
    int randomIndex = low + rand() % (high - low + 1); 
    swap(arr[randomIndex], arr[high]); 
    int pivot = arr[high]; 
    int i = low - 1; 
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        cout << "Partition: ";
        for (int k = low; k <= high; k++) {
            if (k == pi) cout << "[" << arr[k] << "] ";
            else cout << arr[k] << " ";
        }
        cout << " Pivot: " << arr[pi] << endl;
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted Array:- ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
