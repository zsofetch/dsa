#include <stdio.h>
#define MAX 100

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

EPtr L;

void initialize(EPtr L) {
    L->count = 0;
}

void insertPos(EPtr L, int data, int position) {
    // if (position < 1 || position > L->count + 1) {
    //     printf("Position must be valid (less than or equal to count+1).\n");
    //     return L;
    // }
    // if (L->count == MAX) {
    //     printf("The array must not be full.\n");
    //     return L;
    // }

    for (int i = L->count; i >= position; i--) {
        L->elem[i] = L->elem[i-1];
    }
    for (int i = L->count; i >= position; i--) {
        L.elem[i] = L.elem[i - 1];
    }
    L->elem[position - 1] = data;
    L->count++;
}
void deletePos(EPtr L, int position) {
    // if (position < 1 || position > L.c00ount) {
    //     printf("Position must be valid (less than or equal to count).\n");
    //     return L;
    // }
    for (int i = position - 1; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int locate(EPtr L, int data) {
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i + 1;
        }
    }
    return -1;
}

// int retrieve (EPtr L, int position) {

// }
void insertSorted(EPtr L, int data) {
    // if (L->count == MAX) {
    //     printf("The array must not be full.\n");
    //     return L;
    // }
    int i = L->count - 1;
    while (i >= 0 && L->elem[i] > data) {
        L->elem[i + 1] = L->elem[i];
        i--;
    }
    L->elem[i + 1] = data;
    L->count++;
}

void display(EPtr L) {
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

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
