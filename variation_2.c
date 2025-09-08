//disregard comments
//to be debugged

#include <stdio.h>
#define MAX 100

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

EPtr L;

// Etype is the structure, EPtr is a pointer to the structure

void initialize(EPtr L) {
    L->count = 0;
}

void insertPos(EPtr L, int data, int position) {
    /*put an if statement for when list is NULL
      Position must be valid (less than or equal to count)
      basically same ra siya with static by value except we use the arrow operator and we dont return L*/
    if (position >= 0 && position <= L->count && L->count < MAX) {
        // for loop: start from last element, move backwards
        for (int i = L->count - 1; i >= position; i--) {
            L->elem[i + 1] = L->elem[i];
        }
        L->elem[position] = data;
        L->count++; 
    }
}

void deletePos(EPtr L, int position) {
    /*put an if statement for when list is NULL
      if (position < 1 || position > L.count) {
          printf("Position must be valid (less than or equal to count).\n");
           return L; }
    */
    for (int i = position - 1; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i; //return current index/position
        }
    }
    return -1; //data not found after checking all elements
}

int retrieve (EPtr L, int position) {
     if (position >= 0 && position < L->count) { //position must be valid (not negative within valid range)
         return L->elem[position]; //access elem array at given position through pointer
    }
    return -1;
 }

void insertSorted(EPtr L, int data) {

    //check if array is full
    if (L->count < MAX) { // Access count through pointer to ensure space available
        int position = 0; 
        while (position < L->count && L->elem[position] < data) {
            position++; // Move to next position
        }
        /*position < L->count ~while position is not at the end of the list
          L->elem[position] < data ~current element smaller than data to insert*/
    
        for (int i = L->count - 1; i >= position; i--) {
        /*i = L.count - 1 ~start at last element index
          i >= position ~continue while i is at or after the target position
          i-- ~move backwards*/
            
            // Move element at index i to index i+1
            L->elem[i + 1] = L->elem[i];
        }

        L->elem[position] = data;
        /*L.elem[position] ~array access
         data ~value to store*/
        
        L->count++;
    }
}

void display(EPtr L) {
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);

        //for commas
        if (i < L->count - 1) {
            printf(", ");
        }
    }
    printf("\n");
}
  
//main is to be modified
int main() {
    EPtr L myList = initialize(myList);

    myList = insertPos(myList, 1, 1);
    myList = insertPos(myList, 3, 2);
    myList = insertPos(myList, 2, 3);
    myList = insertPos(myList, 5, 4);
    printf("After insertPos:\n");
    display(myList);

    myList = deletePos(myList, 1);
    printf("After deletePos:\n");
    display(myList);

    int pos = locate(myList, 2);
    printf("Locate 2: %d\n", pos);

    myList = insertSorted(myList, 4);
    printf("After insertSorted:\n");
    display(myList);

    return 0;
}
