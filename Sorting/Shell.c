#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap) {
                // Swap arr[j] and arr[j - gap]
                temp = arr[j];
                arr[j] = arr[j - gap];
                arr[j - gap] = temp;
            }
        }
    }
}


// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before sorting: \n");
    printArray(arr, n);
    
    shellSort(arr, n);
    
    printf("Array after sorting: \n");
    printArray(arr, n);
    
    return 0;
}
