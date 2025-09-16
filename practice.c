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
    //allocate memory for the struct L with EPtr and Etype size
    //make an if statement for when L is not empty, set the count to 0 and return L
}

void insertPos(EPtr L, int data, int position) {
    //make an if statement for when list is null else;

    //make another if statement setting the condition that position must be valid
    //&& position is less than or equal to count && count does not exceed MAX
    
    //make a for loop starting from the last element; if i is greater than or equal to the position; move backwards

    //insert the element - destination = source;

    //exit the for loop and set the element's position to the data to be inserted

    //increment count
    
    }

void deletePos(EPtr L, int position) {

    //make an if statement for when list is null else;

    //make another if statement wherein if position must be valid and the position must be less than or equal to count

    //make a for loop initializing i as position; i is less than the last element; move forward

    //delete the element - source = destination;

    //exit the for loop and decrement count
    
}

int locate(EPtr L, int data) {

    //make an if statement for when list is null

    //make a for loop initializing i as 0; i less than count; and move forwards

    //make an if statement that if the element[i] is equal to the data then return the current index

    //exit the if and for loop statement and return -1 if data is not found

}

int retrieve (EPtr L, int position) {
    //make an if statement for when list is null

    //make an if statement wherein if position is greater than or equal to 0 && position is less than count 
    //return the elem array at a given position else return -1
 }

void insertSorted(EPtr L, int data) {
    //make an if statement for when list is null

    //check if array is full so create an if statement if count is less than MAX

    //set the position to 0

    //make a while loop wherein position is less than count && elem array at that given position is less than data
    //move forward to next position 

    //exit the while loop and make a for loop initialize i = the last element; i greater than or equal to position; move backwards

    //destination = source

    //exit for loop and set elem array at given position to data

    //increment count
}

void display(EPtr L) {
    //make an if statement for when list is null

    //make a standard for loop statement

    //printf L->elem[i]

    //for commas, make an if statement that if i is less than the last element print the comma

    //exit the if statement and for loop and print a namespace
    
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

    free(myList); 

    return 0;
    
}