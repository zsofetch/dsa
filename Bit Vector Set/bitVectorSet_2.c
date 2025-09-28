/* Variation 2 - Bit Fields
Bit fields allow the compiler to pack structure members into a small number of bits.
The struct itself holds the bit set.

- instead of manually manipulating bits like in variation 1, we use built in 
  "bit fields" feature in structs

- the struct itself holds the bit set, not just a single variable
*/

#include <stdio.h>
#include <stdlib.h>
#include <stbool.h>

typedef struct {
    // 'field : 8' defines field to be exactly 8 bits wide.
    // this gives us 8 individual bit positions (0-7) for our set elements
    // field : 8 is like saying to allocate exactly 8 bits for this member and the compiler
    // handles the bit manipulation for us.
    unsigned int field : 8;
} Set;

void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set union_set(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(unsigned char set);

void initialize(Set *set) {
    set->field = 0;
}

void insert(Set *set, int element) {
    if (element < 0 || element > 7) {
        printf("Element is out of range.");
        return;
    }
    
    //create the bitmask
    unsigned int mask = 1 << element;
    
    //use bitwise OR to set the corresponding bit
    //the OR operation turns ON the target bit without affecting the others
    set->field |= mask; 
}

void delete(Set *set, int element) {
    if (element < 0 || element > 7) {
        printf("Element is out of range.");
        return;
    }
    //create the mask for the bit we want to clear
    unsigned int mask = 1 << element; //this creates a 1 at the position we want to remove
    
    //inverts the mask (flips all bits)
    mask = ~mask;
    set->field &= mask;
}

bool find(Set set, int element) {
    if (element < 0 || element > 7) {
        return false;
    }

    //create the mask for the bit we want to check
    unsigned int mask = 1 << element; //creates a 1 at the position we want to check

    //use bitwise AND to check the status of the corresponding bit
    return (set.field & mask) != 0;
    /*
    AND operation - if target bit is 1, the result is non-zero (true)
    if target bit is 0, result is zero (false)
    */
}

//combine two sets 
Set union_set(Set A, Set B) {
    Set C; //create a new Set struct containing elements from both input sets

    C.field = A.field | B.field;

    return C;
}

//find elements that exist in both sets
Set intersection(Set A, Set B) {
    Set C;

    C.field = A.field & B.field;

    return C;
}

//find elements in A but not in B (A minus B)
Set difference(Set A, Set B) {
    Set C;

    C.field = A.field & (~B.field);

    return C;
}

void display(Set set) {
    // Note: Pass by value since we're only reading the set
    
    printf("{ "); 
    bool first = true; 
    
    for (int i = 0; i <= 7; i++) {
        //check if the bit corresponding to element i is set
        if (find(set, i)) {  
            // This position contains a 1, so element i is in the set
            if (!first) {      
                printf(", ");  
            }
            printf("%d", i); 
            first = false; // Mark that we've printed at least one element
        }
    }
    
    printf(" }\n"); 
}

// HELPER FUNCTION: Show the binary representation of the bit field
void display_binary(Set set) {
    printf("Binary Version: ");

    for (int i = 7; i >= 0; i--) {
        // Extract bit i: shift right by i positions, then mask with 1
        // (set.field >> i) moves bit i to the rightmost position
        // & 1 keeps only that rightmost bit (0 or 1)
        printf("%d", (set.field >> i) & 1);
    }
    printf(" (decimal: %u)\n", set.field);
}

int main() {
    Set A, B, C;
    
    printf("=== BIT VECTOR SET - VARIATION 2 ===\n\n");
    
    printf("1. INITIALIZING SET A:\n");
    initialize(&A);  
    printf("Initial set A: ");
    display(A); 
    display_binary(A); //dapat 0 rani
    
    printf("\n2. INSERTING ELEMENTS:\n");
    
    printf("Inserting element 0 into set A:\n");
    insert(&A, 0);   // Turn ON bit at position 0
    printf("After inserting 0: ");
    display(A);     
    display_binary(A);  
    
    printf("Inserting element 4 into set A:\n");
    insert(&A, 4);   // Turn ON bit at position 4  
    printf("After inserting 4: ");
    display(A);   
    display_binary(A); 
    
    printf("Inserting element 5 into set A:\n");
    insert(&A, 5);  
    printf("After inserting 5: ");
    display(A);  
    display_binary(A);
    printf("Final set after inserts: {0, 4, 5}\n");
    
    printf("\n3. DELETING ELEMENTS:\n");
    printf("Starting with A.field = 49, set: {0, 4, 5}\n");
    
    printf("Deleting element 5 from set A:\n");
    delete(&A, 5);   // Turn OFF bit at position 5
    printf("After deleting 5: ");
    display(A);     
    display_binary(A); 
    
    printf("Deleting element 4 from set A:\n");  
    delete(&A, 4);   // Turn OFF bit at position 4
    printf("After deleting 4: ");
    display(A);     
    display_binary(A);  
    printf("Final set after deletes: {0}\n");
    
    // TEST 4: Set operations (using examples from your image)
    printf("\n4. SET OPERATIONS EXAMPLE:\n");
    
    A.field = 49;  
    B.field = 36;
    
    printf("Set A (field = 49): ");
    display(A);       
    display_binary(A);
    
    printf("Set B (field = 36): ");
    display(B);       
    display_binary(B);
    
    C = union_sets(A, B);
    printf("Union (A U B): ");
    display(C);      
    display_binary(C); 
    
    C = intersection(A, B);  
    printf("Intersection (A & B): ");
    display(C);       
    display_binary(C); 
    
    C = difference(A, B);
    printf("Difference (A - B): ");
    display(C);      
    display_binary(C); 
    
    printf("\n=== END ===\n");
    
    return 0; 
}