/* Variation 3 - Boolean or Enums
- Instead of bit manipulation, nag gamit tag arrau
- Each array index represents an element
- The value at each position is true/false indicating membership 

[true, false, true, false, false, false, false, true] = set {0, 2, 7}

*/
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

/*
- Index represents the element number
- Value represents membership (true = in set, false = not in set)
- set[0] = true means element 0 is in the set
- set[3] = false means element 3 is NOT in the set
*/

void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void union_set(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);

void initialize(Set set) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        set[i] = false;
        //set the value at each index to false this marks every possible element as "not present" or 0
    }
}

//adds an element to the set (set array position to true)
void insert(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        printf("Element is out of range");
        return;
    }

    //use the 'element' value as the array index;=
    //set the value at that index to true
    set[element] = true; //mark this element as present in the set
}

//delete an element in the set (set array position to false)
void delete(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        printf("Element is out of range");
        return;
    }
    set[element] = false;
}

//check if an element exists in the set
bool find(Set set, int element) {
    if (element < 0 || element >= ARRAY_SIZE) {
        return false;
    }

    //access the array index corresponding to the element that u want to find
    //the resulting set element is true if it is present in set A OR set B
    return set[element];
}

void union_set(Set A, Set B, Set C) {
    //A, B = input sets to combine
    //C = output set where both A and B are in union

    for (int i = 0; i < ARRAY_SIZE; i++) {

        //the resulting set element is true if it is present in Set A OR Set B

        C[i] = A[i] || B[i];
    }
}

void intersection(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && B[i];
    }
}

void difference(Set A, Set B, Set C) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        C[i] = A[i] && !B[i]; //the resulting set element is true ONLY if it is present in A AND NOT in B
    }
}

void display(Set set) {
    printf("{ ");    
    bool first = true; 
    
    // STEP 1: Iterate and list the elements that are TRUE
    for (int i = 0; i < ARRAY_SIZE; i++) {
        
        // STEP 2: Check if the current element is in the set
        if (set[i]) { 
            //pwede sad: if (set[i]) == true or if (find(set, i))
            // This position has value 'true', so element i is in the set
            if (!first) {      
                printf(", ");   
            }
            printf("%d", i);     // Print the element number (the array index)
            first = false;    
    }
    }
    printf(" }\n"); 
}
// HELPER FUNCTION: Show the boolean array representation
void display_array(Set set, char* label) {
    printf("%s = [", label);  
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // Print 1 for true, 0 for false to make it more compact
        printf("%d", set[i] ? 1 : 0); 
        
        if (i < ARRAY_SIZE - 1) {  // If not the last element, add a comma
            printf(",");       
        }
    }
    
    printf("] "); 
    display(set); 
    
}

int main() {
    //boolean arrays ning Set A, B, C
    Set A, B, C;
    
    printf("=== BIT VECTOR SET - VARIATION 3 ===\n\n");
    
    // TEST 1: Initialize empty set
    printf("1. INITIALIZING SET A:\n");
    initialize(A);   // No & needed - arrays passed by reference automatically
    printf("Initial set A: ");
    display(A);     
    display_array(A, "A");  
    
    // TEST 2: Insert elements 
    printf("\n2. INSERTING ELEMENTS:\n");
    
    printf("Inserting element 0 into set A:\n");
    insert(A, 0);   
    display_array(A, "A"); 
    
    printf("Inserting element 2 into set A:\n");
    insert(A, 2);   
    display_array(A, "A"); 
    
    printf("Inserting element 7 into set A:\n");
    insert(A, 7); 
    display_array(A, "A"); 
    printf("Final set: {0, 2, 7}\n");
    
    // TEST 3: Delete elements
    printf("\n3. DELETING ELEMENTS:\n");
    printf("Starting with set {0, 2, 7}\n");
    
    printf("Deleting element 0 from set A:\n");
    delete(A, 0);   
    display_array(A, "A");  
    
    printf("Deleting element 7 from set A:\n");
    delete(A, 7);  
    display_array(A, "A"); 
    printf("Final set: {2}\n");
    
    // TEST 4: Set operations 
    printf("\n4. SET OPERATIONS EXAMPLE:\n");
    
    // A = {0, 2, 7} -> [1,0,1,0,0,0,0,1]
    initialize(A);
    insert(A, 0);
    insert(A, 2);  
    insert(A, 7);
    
    // B = {2, 4, 5} -> [0,0,1,0,1,1,0,0]
    initialize(B);
    insert(B, 2);
    insert(B, 4);
    insert(B, 5);
    
    printf("Set A: ");
    display_array(A, "A"); 
    
    printf("Set B: ");
    display_array(B, "B"); 
    
    // Union: A ∪ B (elements in A OR B or both)
    initialize(C);  // Clear result set first
    union_set(A, B, C);
    printf("Union (A ∪ B): ");
    display_array(C, "C");
    
    // Intersection: A & B (elements in both A AND B)
    initialize(C);  // Clear result set first
    intersection(A, B, C);
    printf("Intersection (A ∩ B): ");
    display_array(C, "C"); 
    
    // Difference: A - B (elements in A but NOT in B)
    initialize(C);  // Clear result set first
    difference(A, B, C);
    printf("Difference (A - B): ");
    display_array(C, "C"); 
    
    // TEST 5: Find operation
    printf("\n5. FIND OPERATION TEST:\n");
    printf("Testing find operation on set A {0, 2, 7}:\n");
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        bool found = find(A, i);
        printf("find(A, %d) = %s\n", i, found ? "true" : "false");
    }
    
    printf("\n=== END ===\n");
    
    return 0; 
}