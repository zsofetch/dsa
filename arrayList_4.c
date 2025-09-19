//dynamic array accessed by pointer
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

// function prototypes
void initialize(List *L);
void insertPos(List *L, int data, int position);
void insertFirst(List *L, int data);
void insertLast(List *L, int data);
void deletePos(List *L, int position);
void deleteFirst(List *L);
void deleteLast(List *L);
void deleteByValue(List *L, int data);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

void initialize(List *L) {
    //allocate memory for elemPtr = cast int; malloc; LENGTH * size of int
    L->elemPtr = (int *) malloc(LENGTH * sizeof(int)); 
    L->count = 0;
    L->max = LENGTH;
}

void insertPos(List *L, int data, int position) {
    if (position < 0 || position > L->count) { //if pos is less than 0 and greater than count
        printf("Invalid position!\n");
        return;
    }

    // Resize if full
    if (L->count == L->max) {
        resize(L);
    }

    // Shift elements to the right
    for (int i = L->count; i > position; i--) {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }
    
    // Insert the new element
    L->elemPtr[position] = data;
    L->count++;
}

void insertFirst(List *L, int data) {
    insertPos(L, data, 0); // just insert at position 0
}

void insertLast(List *L, int data) {
    insertPos(L, data, L->count); // insert at position count (end)
}

void deletePos(List *L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements left
    for (int i = position; i < L->count - 1; i++) {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
}

void deleteFirst(List *L) {
    deletePos(L, 0); // delete at position 0
}

void deleteLast(List *L) {
    deletePos(L, L->count - 1); // delete at the last index
}

void deleteByValue(List *L, int data) {
    int pos = locate(L, data); // find the position of the value
    if (pos != -1) {
        deletePos(L, pos); // delete at that position
        printf("Deleted %d from the list.\n", data);
    } else {
        printf("Value %d not found in the list.\n", data);
    }
}

int locate(List *L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elemPtr[i] == data) {
            return i; // return index if found
        }
    }
    return -1; 
}

int retrieve(List *L, int position) {
    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return -1;
    }
    return L->elemPtr[position];
}

void insertSorted(List *L, int data) {
    if (L->count == L->max) {
        resize(L);
    }

    int i = L->count - 1;
    // shift right until correct spot is found
    while (i >= 0 && L->elemPtr[i] > data) {
        L->elemPtr[i + 1] = L->elemPtr[i];
        i--;
    }

    L->elemPtr[i + 1] = data;
    L->count++;
}

void display(List *L) {
    printf("List elements: ");
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

// Resize the array when full
void resize(List *L) {
    int newSize = L->max * 2; // double the size
    int *temp = (int *) realloc(L->elemPtr, newSize * sizeof(int));

    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        return;
    }

    L->elemPtr = temp;
    L->max = newSize;
    printf("Resized array to capacity %d\n", L->max);
}

void makeNULL(List *L) {
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}

int main() {
    List myList;
    initialize(&myList);

    insertFirst(&myList, 10);
    insertLast(&myList, 20);
    insertLast(&myList, 30);
    insertFirst(&myList, 5);
    display(&myList);

    deleteFirst(&myList);
    deleteLast(&myList);
    display(&myList);

    insertLast(&myList, 40);
    insertLast(&myList, 50);
    display(&myList);

    deleteByValue(&myList, 40);
    deleteByValue(&myList, 100); // not in list
    display(&myList);

    makeNULL(&myList);
    return 0;
}
