#include <bits/stdc++.h>
using namespace std;

// Merge two subarrays of arr[]
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    vector<int> leftArr(n1), rightArr(n2); // Temporary vectors for left and right subarrays

    // copy the data to the temporary vectors leftArr and rightArr
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left; // initial indexes for left, right, and merged subarrays

    // merge the temporary vectors back into left array and right array
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of leftArr
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // copy the remaining elements of rightArr
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
//begins on the left index and the end is the right index
void mergeSort(vector<int>& arr, int left, int right){
    if (left >= right) 
        return;
    // Find the middle point to divide the array into two halves
    int mid = left + (right -left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    
}

void print(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    cout << endl;
    }
}

int main()
{
    vector<int> arr = { 1000, 234542, 13, 5, 6, 7, 90, 60, 0, 134, 503 };
    int n = arr.size();

    cout << "Given vector is \n";
    print(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    print(arr);
    return 0;
}