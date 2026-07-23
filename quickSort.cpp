#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function using the last element as the pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot in its correct sorted position
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Main QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    // Get array size from user
    cout << "Enter the number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    vector<int> arr(n);

    // Get array elements from user
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print unsorted array
    cout << "\nUnsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform QuickSort
    quickSort(arr, 0, n - 1);

    // Print sorted array
    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
