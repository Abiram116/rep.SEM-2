#include <stdio.h>

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Find the maximum and minimum values in the array
    int max_val = arr[0];
    int min_val = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    // Create an array of buckets
    const int num_buckets = max_val - min_val + 1;
    int buckets[num_buckets];

    // Initialize all buckets to 0
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = 0;
    }

    // Increment the count in each bucket based on the values in the input array
    for (int i = 0; i < n; i++) {
        buckets[arr[i] - min_val]++;
    }

    // Copy the values back to the original array in sorted order
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        while (buckets[i] > 0) {
            arr[index++] = i + min_val;
            buckets[i]--;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program
int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Perform bucket sort
    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
