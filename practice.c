//=========fill the code -- array list variation 1=========
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

List initialize(List L) {
    //set count to 0
    //return L
}

//this is insert first
List insertPos(List L, int data, int position) {
    // make an if statement to validate
    if (if position isn't a negative number && position is within the bounds of count && count doesn't exceed MAX) {
       // make a for loop -- shift elements to the right to make space (start from last element then move backwards)
       for (start at the last valid index; i is at or after the target position; move backwards) {
       //shift elements from one position to the right
        destination/next index position = source;
       }
       //the position is free so place your new data
       access array with position = value to store;

       //increment

    }
    //return the list

}

List deletePos(List L, int position) {
    //make an if statement to validate
  if (position to delete is greater or equal to 0 && position is less than count) {
    //shift elements to the left; start from the position being deleted 
    for (initialize i as the position to delete; i is less than second to the last position; move forward) {
      //shift element one position to the left
      source = destination/next index position
    }
    //decrement

  }
  //return L

}

int locate(List L, int data) {
    //make a standard for loop for traversing through the array
    for (initialize i to 0; i should be less than count; move forward) {
        //if statement to check if data to locate is equal to the array element
        if (the element in that index == data) {
            //return the index

        }
    }
    //return -1 if not found
}

insertSorted(List L, int data) {
    //make an if statement
    if (count does not exceed MAX) { 
        //initialize the position to 0

        //make a while loop 
        while(position does not exceed count && the element in that position is less than the data to insert) {
            //increment and move to the next position

        }
        //make a for loop
        for (initialize i to the second to the last index; continue while i is at or after the target position; move backwards) {
            //shift elements one position to the right
            destination = source;
        }
        //access the element in that position and store the value

        //increment the count of L

    }
    //return list

}
 
void display (List L) {
    //make a standard for loop for traversing through the array 
    for (initialize i to 0; i should be less than count; move forward) {
        //print the value in every index (L.elem[i])

        //for commas
        //make an if statement and print commas every after the value except the last value
        if (i is less than the count - 1) {
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

//=========fill the code -- array list variation 2=========

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

// Etype is the structure, EPtr is a pointer to the structure

EPtr initialize() {
    EPtr L = (EPtr)malloc(sizeof(Etype)); // allocate memory for the struct
    L->count = 0;                         // set the count to 0
    return L;                             // return the list
}

void insertPos(EPtr L, int data, int position) {
    if (L == NULL) return;
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
    if (L == NULL) return;
    if(position >= 0 && position <= L->count) {
    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
        }
    L->count--;
    }
}

int locate(EPtr L, int data) {
    if (L == NULL) return -1;
    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i; //return current index/position
        }
    }
    return -1; //data not found after checking all elements
}

int retrieve (EPtr L, int position) {
    if (L == NULL) return -1;
     if (position >= 0 && position < L->count) { //position must be valid (not negative within valid range)
         return L->elem[position]; //access elem array at given position through pointer
    }
    return -1;
 }

void insertSorted(EPtr L, int data) {

    if (L == NULL) return;
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
    if (L == NULL) return;
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
        //for commas
        if (i < L->count - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    EPtr myList = initialize();

    insertPos(myList, 1, 0);
    insertPos(myList, 3, 1);
    insertPos(myList, 2, 2);
    insertPos(myList, 5, 3);

    printf("After insertPos:\n");
    display(myList);

    deletePos(myList, 1);
    printf("After deletePos:\n");
    display(myList);

    int pos = locate(myList, 2);
    printf("Locate 2: %d\n", pos);

    insertSorted(myList, 4);
    printf("After insertSorted:\n");
    display(myList);

    free(myList); // free allocated memory
    return 0;
}
