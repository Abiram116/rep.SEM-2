#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= j && arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);

        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main() {
    printf("Enter a list of numbers separated by spaces: ");

    // Assuming a maximum array size of 1000
    int input_list[1000];
    int input_size = 0;

    // Reading input
    while (scanf("%d", &input_list[input_size]) == 1) {
        input_size++;
    }

    quick_sort(input_list, 0, input_size - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < input_size; i++) {
        printf("%d ", input_list[i]);
    }

    return 0;
}
