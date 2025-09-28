/* Variation 1 - Bitmask (char holding int value)
This is the most common and space-efficient way to
implement a bit vector set. An unsigned char (or int) is used,
and elements are added by setting the corresponding bit using
the bitwise OR operator.

N = decimal value
( ) = binary value
{ } = set elements
[ ] = array elements

ON is 1
OFF is 0
*/

#include <stdio.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char union_set(unsigned char A, unsigned char B);
unsigned char intersection_set(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);

//sets all bits to 0 creating an empty set
void initialize(unsigned char *set) {
    *set = 0;
}

void insert(unsigned char *set, int element) {
    if (element < 0 || element > 7) { //8 bit range
        printf("Element %d is out of range", element);
        return;
    }
    unsigned char mask = 1 << element; // left shift moves the bit to the right position
    *set |= mask; //if either bit is 1, result is 1
}

void delete(unsigned char *set, int element) {
    if (element < 0 || element > 7) {
        printf("Element %d is out of range", element);
        return;
    }
    unsigned char mask = 1 << element;

    //invert the mask (this creates a mask with a 0 at the target bit and 1s everywhere else)
    mask = ~mask; //~ means "NOT" and flips the all bit
    *set &= mask; // both bits must be 1 for the result to be 1
}

bool find(unsigned char set, int element) {
     if (element < 0 || element > 7) {
        return false; //true if found, false if not
    }
    //create a mask for the element's position
    unsigned char mask = 1 << element;

    //use bitwise AND between the set and the mask
    return (set & mask) != 0; 
    //if target bit is ON - result will be non-zero (true)
    //if target bit is OFF - result will be zero (false)
}

//the union is achieved by the bitwise OR operation
unsigned char union_set(unsigned char A, unsigned char B) {
    return A | B;
}

//the intersection is achieved by the bitwise AND operation
unsigned char intersection_set(unsigned char A, unsigned char B) {
    return A & B;
}

//the difference is achieved by A AND (NOT B)
unsigned char difference(unsigned char A, unsigned char B) {
    return A & (~B);
}

void display(unsigned char set) {
    printf("{ ");
    bool first = true; //tracks if this is the first element

    //iterate through all possible elements (0 - 7)
    for (int i = 0; i <= 7; i++) {
        //check if the bit corresponding to element i is set
        
        //check if bit at position i is set (ON)
        if (find(set, i)) {
            //this position has a 1, so element i is in the set

            if (!first) { //if not the first element
                printf(", "); //print a comma and space before the number
            }
            printf("%d", i);
            first = false; //next element wont be first anymore
        }
    }
    printf(" }\n");
}

//=======HELPER FUNCTION: displayBinary shows the actual binary representation
void displayBinary(unsigned char set) {
    printf("Binary version: ");

    //iterate showing each bit from left to right (position 7 down to position 0)
    for (int i = 7; i >= 0; i--) {
        printf("%d", (set >> i) & 1);

        /*
        (set >> i) shifts all bits right by i position
        & 1 keeps only the rightmost bit (0 or 1)
        */
    }
    printf(" (decimal: %d)\n", set);
}

int main () {
    unsigned char A, B, C;

    printf("=== BIT VECTOR SET - VARIATION 1 ===\n\n");

    printf("1. Initializing Set A:\n");
    initialize(&A);
    printf("Initial set A: ");
    display(A);
    displayBinary(A);

    printf("\n2. Inserting Elements:\n");
    printf("Inserting element 1 into set A:\n");
    insert(&A, 1); //turning ON bit at position 1
    printf("After inserting 1: ");
    display(A);
    displayBinary(A);

    printf("\n3. Deleting Elements:\n");
    printf("Deleting element 6 from set A:\n");
    printf("After deleting 6: ");
    display(A);
    displayBinary(A);

    printf("\n4. Set Operations Example:\n");

    A = 64;
    B = 32;

    printf("\nSet A = 64: ");
    display(A);
    displayBinary(A);

    printf("\nSet B = 32: ");
    display(B);
    displayBinary(B);

    C = union_set(A, B);
    printf("\nUnion (A U B): ");
    display(C);
    displayBinary(C);

    C = intersection_set(A, B);
    printf("\nIntersection (A & B): ");
    display(C);
    displayBinary(C);

    C = difference(A, B);
    printf("\nDifference (A - B): ");
    display(C);
    displayBinary(C);

    printf("\n=== END ===\n");

    return 0;
}

