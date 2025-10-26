#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(char *arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    char *arr[] = {"Charlie", "Alice", "Bob", "Eve", "David", "Frank"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array of names: ");
    printArray(arr, n);

    // Perform Heap Sort (sorts alphabetically A-Z)
    heapSort(arr, n);

    printf("Sorted array of names:   ");
    printArray(arr, n);

    return 0;
}

void heapify(char *arr[], int n, int i);
void heapSort(char *arr[], int n);

// Maintains the max heap property in a subtree rooted at index i
void heapify(char *arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // If left child is alphabetically larger than root
    if (left < n && strcmp(arr[left], arr[largest]) > 0)
        largest = left;
    
    // If right child is alphabetically larger than largest so far
    if (right < n && strcmp(arr[right], arr[largest]) > 0)
        largest = right;
    
    // If largest is not root
    if (largest != i) {
        char *temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Implements Heap Sort for strings (A–Z)
void heapSort(char *arr[], int n) {
    // Step 1: Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max) to the end
        char *temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}
