#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(char *arr[], int n)
void heapify(char *arr[], int n, int i);
void heapSort(char *arr[], int n);

void printArray(char *arr[], int n) {
    //iterate through the array

        //print each character string of the array

    //print a namespace
}

// Maintains the max heap property in a subtree rooted at index i
void heapify(char *arr[], int n, int i) {

    //initialize largest to i

    //initialize left child to 2 * i + 1

    //initialize right child to 2 * i + 2

    //if left child is alphabetically larger than largest so far (n) and strcmp arr at index left and arr at index largest is greater than 0

        //initialize largest to left
    
    //if right child is alphabetically larger than largest so far (n) and strcmp arr at index right and arr at index largest is greater than 0

        //intialize largest to right

    //if largest is not i (root)
       
        //swap by initializing char *temp to arr at index i 

        //initialize arr at index i to arr at index largest 

        //initialize arr at index largest to temp
}

// Implements Heap Sort for strings (A–Z)
void heapSort(char *arr[], int n) {
    //build the max heap by making a for loop - initialize i to n / 2 - 1; continue while i is greater than or equal to 0; decrement i

        //call heapify function with arr, n, i

    //extract elements one by one by making a for loop - initialize i to n - 1; continue while i is greater than 0; decrement i

        //move current root (max) to the end by initializing char *temp to arr at index 0

        //initialize arr at index 0 to arr at index i

        //initialize arr at index i to temp

        //call the heapify function with arr, i, 0
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
