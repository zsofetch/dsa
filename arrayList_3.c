//dynamic array accessed by value

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

Dynamically allocate memory for the array using LENGTH
Set max to defined LENGTH
Set the count to 0
Return List

List initialize(List L) {

    L.max = 4; //capacity of 4 elements
    L.elem = (int*)malloc(sizeof(int) * L.max); //dynamically allocate

    /*cast to (int*) ~malloc returns void
      allocate memory for L.max integers
      sizeof(int) * L.max ~ size of one int times number of elements*/
    
    L.count = 0; //empty list
    return L;



}
Reallocate the memory assigned to the array and double its length
Double the max variable
Return modified List


List resize(List L) {
    L.max *= 2; // Equivalent to: L.max = L.max * 2
    /*double the capacity*/

    L.elem = (int*)realloc(L.elem, sizeof(int) * L.max);
    /*resize existing memory block*/Note: realloc() automatically copies existing data to new memory
    // and frees the old memory block
    
    return L;
    // ^^^^^^^^
    // Return the modified list structure
}

// =============================================================================
// INSERT AT POSITION FUNCTION
// =============================================================================
List insertPos(List L, int data, int position) {
    // Function signature breakdown:
    // - Return type: List (return the modified list)
    // - Function name: insertPos
    // - Parameters: List L (list to modify), int data (value), int position (where)
    
    // STEP 1: Check if array is full and resize if necessary
    if (L.count >= L.max) {
        //  ^^^^^^^^^^^^^
        // If current count equals or exceeds capacity
        
        L = resize(L);
        //  ^^^^^^^^^^
        // Call resize function to double capacity
        // Assignment needed because we pass by value
    }
    
    // STEP 2: Validate the position
    if (position >= 0 && position <= L.count) {
        //     ^^^^^^^^^^^^   ^^^^^^^^^^^^^^^^^^
        //     not negative   can insert at end
        
        // STEP 3: Shift elements to the right to make space
        int i; // Loop counter variable
        
        // for loop: start from last element, move backwards
        for (i = L.count - 1; i >= position; i--) {
            //   ^^^^^^^^^^^^^   ^^^^^^^^^^^^  ^^^^
            //   start at last   continue while   move backwards
            //   element         at or after pos
            
            // Move element at index i to index i+1
            L.elem[i + 1] = L.elem[i];
            // ^^^^^^^^^^^^     ^^^^^^^^^
            // destination      source
            // Access dynamically allocated array through pointer
        }
        
        // STEP 4: Insert the new data at the specified position
        L.elem[position] = data;
        // ^^^^^^^^^^^^^^^   ^^^^
        // Access array      value to store
        // through pointer
        
        // STEP 5: Increment the count
        L.count++; // Add one more element to count
        // ^^^^^^^^
        // Increment count of elements
    }
    
    // STEP 6: Return the modified list
    return L;
    // ^^^^^^^^
    // Return the list structure (pass by value)
}

// =============================================================================
// DELETE AT POSITION FUNCTION
// =============================================================================
List deletePos(List L, int position) {
    // Function signature breakdown:
    // - Return type: List (return the modified list)
    // - Function name: deletePos
    // - Parameters: List L (list to modify), int position (element to delete)
    
    // STEP 1: Validate the position
    if (position >= 0 && position < L.count) {
        //     ^^^^^^^^^^^^   ^^^^^^^^^^^^^^^^^^
        //     not negative   within valid range
        
        // STEP 2: Shift elements to the left to fill the gap
        int i; // Loop counter variable
        
        // for loop: start from position being deleted, move forward
        for (i = position; i < L.count - 1; i++) {
            //  ^^^^^^^^^^^^^   ^^^^^^^^^^^^^^^  ^^^^
            //  start at pos    continue until   move forward
            //  to delete       second to last
            
            // Move element at index i+1 to index i
            L.elem[i] = L.elem[i + 1];
            // ^^^^^^^^^     ^^^^^^^^^^^^^
            // destination   source
            // Shift elements left through pointer access
        }
        
        // STEP 3: Decrement the count
        L.count--; // Remove one element from count
        // ^^^^^^^^
        // Decrement count of elements
    }
    
    // STEP 4: Return the modified list
    return L;
    // ^^^^^^^^
    // Return the list structure (pass by value)
}

// =============================================================================
// LOCATE FUNCTION
// =============================================================================
int locate(List L, int data) {
    // Function signature breakdown:
    // - Return type: int (return position where found, or -1)
    // - Function name: locate
    // - Parameters: List L (list to search), int data (value to find)
    
    // STEP 1: Initialize loop counter
    int i; // Loop counter variable
    
    // STEP 2: Loop through the array to search for the data
    for (i = 0; i < L.count; i++) {
        //  ^^^^^^   ^^^^^^^^^^^  ^^^^
        //  start at continue while move forward
        //  first    within valid   to next
        //  element  elements       element
        
        // STEP 3: Check if current element matches search data
        if (L.elem[i] == data) {
            // ^^^^^^^^^    ^^^^
            // current      value we're
            // element      searching for
            // Access through pointer
            
            // STEP 4: Found it! Return the position
            return i;
            // ^^^^^^^^
            // Return the index where data was found
        }
    }
    
    // STEP 5: Data not found
    return -1;
    // ^^^^^^^^
    // Return -1 as sentinel value for "not found"
}

// =============================================================================
// INSERT SORTED FUNCTION
// =============================================================================
List insertSorted(List L, int data) {
    // Function signature breakdown:
    // - Return type: List (return the modified sorted list)
    // - Function name: insertSorted
    // - Parameters: List L (sorted list), int data (value to insert)
    
    // STEP 1: Check if array is full and resize if necessary
    if (L.count >= L.max) {
        //  ^^^^^^^^^^^^^
        // If current count equals or exceeds capacity
        
        L = resize(L);
        //  ^^^^^^^^^^
        // Call resize function to double capacity
    }
    
    // STEP 2: Find the correct position to insert the data
    int position = 0; // Start from beginning
    
    // Loop to find insertion position for sorted order
    while (position < L.count && L.elem[position] < data) {
        //     ^^^^^^^^^^^^^^^^^^    ^^^^^^^^^^^^^^^^^^^^^^
        //     not at end yet       current element smaller
        //                          than data to insert
        
        position++; // Move to next position
        // ^^^^^^^^^^
        // Check next position
    }
    
    // STEP 3: Shift elements to the right to make space
    int i; // Loop counter variable
    
    // for loop: start from last element, move backwards
    for (i = L.count - 1; i >= position; i--) {
        //   ^^^^^^^^^^^^^   ^^^^^^^^^^^^  ^^^^
        //   start at last   continue while   move backwards
        //   element         at or after pos
        
        // Move element at index i to index i+1
        L.elem[i + 1] = L.elem[i];
        // ^^^^^^^^^^^^     ^^^^^^^^^
        // destination      source
    }
    
    // STEP 4: Insert the new data at the found position
    L.elem[position] = data;
    // ^^^^^^^^^^^^^^^   ^^^^
    // Insert at correct sorted position
    
    // STEP 5: Increment the count
    L.count++; // Add one more element
    // ^^^^^^^^
    
    // STEP 6: Return the modified list
    return L;
    // ^^^^^^^^
    // Return the sorted list structure
}

// =============================================================================
// DISPLAY FUNCTION
// =============================================================================
void display(List L) {
    // Function signature breakdown:
    // - Return type: void (no return value)
    // - Function name: display
    // - Parameters: List L (list to display)
    
    // STEP 1: Print opening bracket
    printf("[");
    
    // STEP 2: Loop through all valid elements
    int i; // Loop counter variable
    
    // for loop: iterate through all elements
    for (i = 0; i < L.count; i++) {
        //  ^^^^^^   ^^^^^^^^^^^  ^^^^
        //  start at continue while move forward
        //  first    within valid   to next
        //  element  elements       element
        
        // STEP 3: Print the current element
        printf("%d", L.elem[i]);
        //     ^^^^  ^^^^^^^^^
        //     format current element
        //     specifier accessed through pointer
        
        // STEP 4: Print comma separator (except for last element)
        if (i < L.count - 1) {
            //     ^^^^^^^^^^^^^
            // Not the last element
            
            printf(", ");
            // Print separator
        }
    }
    
    // STEP 5: Print closing bracket and newline
    printf("]\n");
    printf("Count: %d, Max: %d\n", L.count, L.max);
    //     ^^^^^^^^^^^^^^^^^^^^
    // Show current count and capacity for debugging
}

// =============================================================================
// CLEANUP FUNCTION (IMPORTANT FOR DYNAMIC MEMORY)
// =============================================================================
void cleanup(List L) {
    // Function signature breakdown:
    // - Return type: void (no return value)
    // - Function name: cleanup
    // - Parameters: List L (list to clean up)
    
    // STEP 1: Free the dynamically allocated memory
    if (L.elem != NULL) {
        //  ^^^^^^^^^^^^^^
        // Check if pointer is not NULL (safety check)
        
        free(L.elem);
        //   ^^^^^^^^^
        // Free the memory allocated by malloc/realloc
        // This prevents memory leaks
    }
    
    // Note: After calling free(), the pointer becomes invalid
    // In a real program, you might want to set L.elem = NULL
}
