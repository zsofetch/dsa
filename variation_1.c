//please disregard comments :)) they're for my notes thank u!
//to be debugged
#include <stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List L;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

//count <= MAX 
//set count to 0
List initialize(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position) {
    /*make an if statement
    position >= 0 ~no negative numbers
    position <= L.count ~position is within the array bounds
    L.count < MAX ~count does not exceed limit */
    if (position >= 0 && position <= L.count && L.count < MAX) {
        //shift elements to the right to make space (start from last element then move backwards)
        (for int i = L.count - 1; i >= position; i--) {
            /*i = L.count - 1 ~start at last valid index
              i >= position ~continue while i is at or after the target position
              i-- ~move backwards*/
            L.elem[i + 1] = L.elem[i];
            /*L.elem[i + 1] ~destination; next index position
              L.elem[i] ~source
              this shifts elements from one position to the right*/
        }
        L.elem[position] = data;
        /*the position is free so we place our new data
          L.elem[position] ~array access
          data ~value to store*/
        L.count++; //increment
    }
    return L; 
}

List deletePos(List L, int position) {
    if (position >= 0 && position <= L.count) {
            /*shift elements to the left to fill the gap
              start from the position being deleted and move forward
              this overwrites the deleted element and closes the gap*/
            for (int i = position; i < L.count - 1; i++) {
            /*int i = position ~start at position to delete
              i < L.count - 1 ~continue until second to the last 
              i++ ~move forward*/
            L.elem[i] = L.elem[i + 1];
            //shifts the element one position to the left
            }
            L.count--;
    }
    return L;
}

int locate(List L, int data) {
    for(int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) { //if current element/index = data
            return i;
        }
    }
    return -1;
}

insertSorted(List L, int data) {
    if (L.count < MAX) { //list is not full
       int position = 0;
       while (position < L.count && L.elem[position] < data) {
        /*position < L.count ~while position is not at the end of the list
          L.elem[position] < data ~current element smaller than data to insert*/
        position++; //move to next position
       }
       for (int i = L.count - 1; i >= position; i--) {
        /*i = L.count - 1 ~start at last element index
          i >= position ~continue while i is at or after the target position
          i-- ~move backwards*/
        L.elem[i + 1] = L.elem[i];
        //shifts the element one position to the right
       }
       L.elem[position] = data;
       /*L.elem[position] ~array access
         data ~value to store*/
       L.count++;
    }
    return L;
}
 
void display (List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d", L.elem[i]);

        //for commas
        if (i < L.count -1) {
            printf(" ,");
        }
    }
    printf("\n");
}

int main() {
    List myList = initialize(myList);

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
