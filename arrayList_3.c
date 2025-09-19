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

//idk if we need helper functions
void cleanup(List L); 

List initialize(List L) {

    L.max = 10; //capacity of 10 elements
    L.elemPtr = (int*)malloc(sizeof(int) * L.max); //dynamically allocate

    /*cast to (int*) ~malloc returns void
      allocate memory for L.max integers
      sizeof(int) * L.max ~ size of one int times number of elements*/
    
    L.count = 0; //empty list
    return L;

}

List resize(List L) {
    L.max *= 2; // Equivalent to: L.max = L.max * 2
    /*double the capacity*/
    L.elemPtr = (int*)realloc(L.elemPtr, sizeof(int) * L.max);
    /*resize existing memory block
      ~reallocate the memory assigned to the array and double its length
      ~resize existing memory block to new capacity
      ~original pointer
      ~new size in bytes (doubled)*/
    return L;
}
List insertPos(List L, int data, int position) {
    
    if (L.count >= L.max) { // Check if the array is full (count equals or exceeds max)
        L = resize(L); //if the array is full, call the resize function as per checklist
    }
    if (position >= 0 && position <= L.count) {
       //not negative && position must be valid (less than or equal to count)
        
        /*shift elements right to make space for the position if necessary
        for loop: start from last element, move backwards*/
        for (int i = L.count - 1; i >= position; i--) {
            /* start at last     continue while  move backwards
               element           at or after pos*/
            L.elemPtr[i + 1] = L.elemPtr[i]; // move element at index i+1 to index i
        }

        L.elemPtr[position] = data; //inserting element into specified position
        L.count++; 
    }
    return L;
}

List deletePos(List L, int position) {
  
    if (position >= 0 && position < L.count) {
        //position must be valid (less than count for deletion and not negative)

        // for loop: start from position being deleted, move forward
        for (int i = position; i < L.count - 1; i++) {
            L.elemPtr[i] = L.elemPtr[i + 1];
        }
        L.count--; 
    }
    return L;
}

int locate(List L, int data) {
  
    //loop through the array and return the position of the data if found
    for (int i = 0; i < L.count; i++) {
        /* i = 0 ~start at first element
           i < L.count = 0 ~continue while within valid elements
           i++ ~move forward*/ 
        if (L.elemPtr[i] == data) {
            return i;
            //return the position of the data if found
        }
    }
    return -1;
}
List insertSorted(List L, int data) {
  
    if (L.count >= L.max) {
        L = resize(L);
        //if the array is full, call the resize function as per checklist
    }
    
    //insert the element into the correct position based on the value
    int position = 0; // start from beginning
    while (position < L.count && L.elemPtr[position] < data) {
        //  ^^^^^^^^^^^^^^^^^^    ^^^^^^^^^^^^^^^^^^^^^^
        //   not at end yet       current element smaller
        //                          than data to insert
        position++; // move to next position
    }
    // for loop: start from last element, move backwards
    for (int i = L.count - 1; i >= position; i--) {
        //   ^^^^^^^^^^^^^   ^^^^^^^^^^^^  ^^^^
        //   start at last   continue while   move backwards
        //   element         at or after pos
        L.elemPtr[i + 1] = L.elemPtr[i];
    }
    
    L.elemPtr[position] = data;
    // Insert the element into the correct position based on the value
    L.count++; 
    return L;
}

void display(List L) {
    for (int i = 0; i < L.count; i++) {
        
        //display each element of the array until count is reached
        printf("%d", L.elemPtr[i]);
        //comma separator (except for last element)
        if (i < L.count - 1) {
            // not the last element
            printf(", ");
        }
    }
    printf("\nCount: %d, Max: %d\n", L.count, L.max); //current count and capacity
}

//optional helper functions

/*for insertFirst call insert first then add position 0
indicating youre inserting at index 0*/
List insertFirst(List L, int data) {
    return insertPos(L, data, 0);
}

/*for insertLast you do the same but you insert at the 
last position or L.count*/
List insertLast(List L, int data) {
    return insertPos(L, data, L.count);
}

List deleteFirst(List L) {
    return deletePos(L, 0);
}

List deleteLast(List L) {
    // Delete at position L.count-1 (last element)
    if (L.count > 0) { // Check if list is not empty before deleting last element
        return deletePos(L, L.count - 1);
    }
    return L; // return unchanged list if empty
}

List deleteByValue(List L, int data) {
    // Function uses combination of locate and deletePos as mentioned in the note
    
    int position = locate(L, data);
    //  ^^^^^^^^   ^^^^^^^^^^^^^^^
    //find position  Use locate function to find where data is located
    
    //if data was found (position != -1), use deletePos to remove it
    if (position != -1) {
        L = deletePos(L, position);
    }
    return L;
}

void cleanup(List L) {
    if (L.elemPtr != NULL) {
        // Check if pointer is not NULL (safety check)
        free(L.elemPtr);
    }
    // Note: After calling free(), the pointer becomes invalid
    // In a real program, you might want to set L.elem = NULL
}

int main () {
List myList;
myList = initialize(myList);

myList = insertPos(myList, 10, 0);
myList = insertSorted(myList, 5);
myList = insertSorted(myList, 15);
myList = insertSorted(myList, 7);

display(myList);

cleanup(myList);
return 0;
}