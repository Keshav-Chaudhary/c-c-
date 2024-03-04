#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max(int a, int b, int c) {
    return max(max(a, b), c);
}
int Maxysumsubarray(vector<int> arr, int l, int m, int h) {
    int sum = 0;
    int sumfromleft = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > sumfromleft)
            sumfromleft = sum;
    
    }
    cout<<sum;
    sum = 0;
    int sumfromright = INT_MIN;
    for (int i = m+1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > sumfromright)
            sumfromright = sum;
    }
    cout<<sum;
    return sumfromleft + sumfromright;
    
}

int Maxysumsubarraysum(vector<int> arr, int l, int h) {
    if (l == h)
        return arr[l];
    int m = (l + h)/2;
    return max(Maxysumsubarraysum(arr, l, m),
               Maxysumsubarraysum(arr, m+1, h),
               Maxysumsubarray(arr, l, m, h));
}

int main() {
    vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> arr2 = {1, 2, 3, 4, -10, 6, 7, 8, 9};
    vector<int> arr3 = {-5, -2, -6, -1, -2, -3, -7, -4};

    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();

    cout << "Max_sum 1 is " << Maxysumsubarraysum(arr1, 0, n1-1) << endl;
    cout << "Max_sum 2 is " << Maxysumsubarraysum(arr2, 0, n2-1) << endl;
    cout << "Max_sum 3 is " << Maxysumsubarraysum(arr3, 0, n3-1) << endl;

    return 0;
}
