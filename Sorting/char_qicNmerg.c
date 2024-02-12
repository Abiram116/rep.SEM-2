#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(char arr[], int l, int h);
void quickSort(char arr[], int l, int h);
void merge(char arr[], int l, int m, int h);
void mergeSort(char arr[], int l, int h);

int main() {
    int n, i;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    if (n < 5) {
        printf("Size should be minimum 5.\n");
        return 1;
    }
    
    char arr[n];
    
    printf("Enter %d characters: ", n);
    for (i = 0; i < n; i++)
        scanf(" %c", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("\nArray sorted using Quick Sort: ");
    for (i = 0; i < n; i++)
        printf("%c ", arr[i]);
    
    mergeSort(arr, 0, n - 1);

    printf("\nArray sorted using Merge Sort: ");
    for (i = 0; i < n; i++)
        printf("%c ", arr[i]);

    return 0;
}

// Quick Sort
int partition(char arr[], int l, int h) {
    char pivot = arr[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char temp = arr[i + 1];
    arr[i + 1] = arr[h];
    arr[h] = temp;
    return (i + 1);
}

void quickSort(char arr[], int l, int h) {
    if (l < h) {
        int pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

// Merge Sort
void merge(char arr[], int l, int m, int h) {
    char c[50];
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= h){
        if(arr[i] <= arr[j])
            c[k++] = arr[i++];
        else
            c[k++] = arr[j++];
    }
    while(i <= m)
        c[k++] = arr[i++];
    while(j <= h)
        c[k++] = arr[j++];
    for(i = l; i <= h; i++)
        arr[i] = c[i];
}

void mergeSort(char arr[], int l, int h) {
    if (l < h) {
        int mid = l + (h - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);

        merge(arr, l, mid, h);
    }
}
