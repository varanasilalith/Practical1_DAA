#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted sub-arrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
    }
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

// Recursive function to perform Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    if (!(cin >> size) || size <= 0) return 1;
    vector<int> arr(size);
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) cin >> arr[i];
    
    mergeSort(arr, 0, size - 1);
    
    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
