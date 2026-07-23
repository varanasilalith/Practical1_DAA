#include <iostream>
using namespace std;
// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
       for (int j = 0; j < n - i - 1; j++) {
           if (arr[j] > arr[j + 1]) {
               // Swap adjacent elements if they are in the wrong order
               int temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
           }
       }
   }
}
// Function to print the array
void printArray(int arr[], int n) {
   for (int i = 0; i < n; i++) {
       cout << arr[i] << " ";
   }
   cout << endl;
}
int main() {
   int arr[] = {64, 34, 25, 12, 22, 11, 90};
   int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Original Array: ";
   printArray(arr, n);
   bubbleSort(arr, n);
   cout << "Sorted Array: ";
   printArray(arr, n);
   return 0;
}
